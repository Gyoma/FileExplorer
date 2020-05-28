#include "FolderPercentageStrategy.h"
#include <functional>

FolderPercentageStrategy::FolderPercentageStrategy()
{}

FolderPercentageStrategy::~FolderPercentageStrategy()
{}

void FolderPercentageStrategy::DoAndPrint(QString const& path)
{
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    uint64_t total_size = getTotalSize(path, filters);

    QFileInfo inf(path);

    if (inf.isDir())
    {
        if (total_size == 0)
        {
            qcout << inf.filePath() << " is empty" << endl;
            return;
        }

        std::function<size_t(QString const&)> folder_size = [&](QString const& path) -> size_t
        {
            size_t size = 0;

            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir())
                    size += folder_size(entity.absoluteFilePath());
                else
                    size += double(entity.size());

            return size;
        };

        auto process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir())
                    qcout << entity.fileName() << " = " << double(folder_size(entity.filePath())) / total_size * 100 << " %" << endl;
                else
                    qcout << entity.fileName() << " = " << double(entity.size()) / total_size * 100 << " %" << endl;
        };

        process_files(path);
    }
    else
    {
        total_size = getTotalSize(inf.dir().path());
        qcout << inf.fileName() << " = " << double(inf.size()) / total_size * 100 << " %" << endl;
    }
}
