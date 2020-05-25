#include "FolderPercentageStrategy.h"
#include <functional>

FolderPercentageStrategy::FolderPercentageStrategy()
{}

FolderPercentageStrategy::~FolderPercentageStrategy()
{}

void FolderPercentageStrategy::process(QString const& path)
{
    if (QFileInfo(path).isDir())
    {
        QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
        uint64_t total_size = getTotalSize(path, filters);

        qcout << total_size << endl;

        std::function<void(QString const&)> process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir())
                    process_files(entity.absoluteFilePath());
                else
                    qcout << entity.fileName() << " = " << double(entity.size()) / total_size * 100 << "%" << endl;
        };

        process_files(path);
    }
    else
        qcout << path << " 100%" << endl;
}
