#include "FolderPercentageStrategy.h"
#include <functional>

FolderPercentageStrategy::FolderPercentageStrategy()
{}

FolderPercentageStrategy::~FolderPercentageStrategy()
{}

void FolderPercentageStrategy::DoAndPrint(QString const& path)
{
    //настраиваем фильтр на скрытые файлы и папки
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    uint64_t total_size = getTotalSize(path, filters);

    QFileInfo inf(path);

    //если папка
    if (inf.isDir())
    {
        //если папка пустая
        if (total_size == 0)
        {
            qcout << inf.filePath() << " is empty" << endl;
            return;
        }

        //рекурсивная функция для подсчета процентного соотношения файлов в папке верхнего уровня, начиная с path
        auto process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir()) //если папка
                {
                    uint64_t size = getTotalSize(entity.filePath()); //получаем размер папки
                    qcout << entity.fileName() << " = " << double(size) / total_size * 100 << " %";

                    if (size == 0) //если папка пустая, то печатаем эту информацию
                        qcout << " (empty)";
                    qcout << endl;
                }
                else //есои файл
                    qcout << entity.fileName() << " = " << double(entity.size()) / total_size * 100 << " %" << endl;
        };

        process_files(path);
    }
    else //если изначально не папка
    {
        total_size = getTotalSize(inf.dir().path());
        qcout << inf.fileName() << " = " << double(inf.size()) / total_size * 100 << " %" << endl;
    }
}
