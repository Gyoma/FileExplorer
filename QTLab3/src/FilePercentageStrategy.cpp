#include <include/FilePercentageStrategy.h>
#include <functional>
#include <QFileInfo>
#include <QDir>

FilePercentageStrategy::FilePercentageStrategy()
{}

FilePercentageStrategy::~FilePercentageStrategy()
{}

// метод получения размера сущности (файла, папки) в байтах.
uint64_t FilePercentageStrategy::getTotalSize(QString const& path, QDir::Filters filters) const
{
    QFileInfo path_inf(path);

    if (path_inf.isDir()) //если папка
    {
        //если папка пустая - возвращать 0.
        if (QDir(path).isEmpty())
            return 0;

        uint64_t res = 0;

        //рекурсивная функция для подсчета размера всех файлах во всех вложенных папках, начиная с path
        std::function<uint64_t(QString const&)> process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir()) //если папка
                    process_files(entity.filePath()); //заходим в папку
                else
                    res += entity.size(); //суммируем размер файла

            return res;
        };

        return process_files(path);
    }
    else
        return path_inf.size(); //иначе вернуть размер файла
}
