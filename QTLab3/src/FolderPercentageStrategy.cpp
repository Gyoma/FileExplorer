#include <include/FolderPercentageStrategy.h>
#include <functional>
#include <QFileInfo>
#include <QDir>

FolderPercentageStrategy::FolderPercentageStrategy()
{}

FolderPercentageStrategy::~FolderPercentageStrategy()
{}

QVector<QPair<QString, uint64_t>> FolderPercentageStrategy::Do(QString const& path)
{
    //настраиваем фильтр на скрытые файлы и папки
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    //данные файлов (название файла и размер этого файла)
    QVector<QPair<QString, uint64_t>> res;
    uint64_t total_size = 0;

    QFileInfo inf(path);
    //если папка
    if (inf.isDir())
    {
        total_size = getTotalSize(path, filters);

        if (total_size == 0)
        {
            res.append({ inf.fileName(), 0 });
            return res;
        }

        //рекурсивная функция для подсчета процентного соотношения файлов в папке верхнего уровня, начиная с path
        auto process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir()) //если папка
                    //получаем размер папки
                    res.append({ entity.fileName(), getTotalSize(entity.filePath(), filters) });
                else //есои файл
                    res.append({ entity.fileName(), (uint64_t)entity.size() });
        };
        process_files(path);
    }
    else //если изначально не папка
    {
        total_size = getTotalSize(inf.dir().path());
        res.append({ inf.fileName(), (uint64_t)inf.size() });
    }

    //добавляем в конец общий размер все папки
    res.append({ "Total size", total_size });
    return res;
}
