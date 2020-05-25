#include "FilePercentageStrategy.h"
#include <functional>

FilePercentageStrategy::FilePercentageStrategy()
{}

FilePercentageStrategy::~FilePercentageStrategy()
{}

uint64_t FilePercentageStrategy::getTotalSize(QString const& path, QDir::Filters filters)
{
    QFileInfo path_inf(path);

    if (path_inf.isDir())
    {
        uint64_t res = 0;

        std::function<uint64_t(QString const&)> process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir())
                    process_files(entity.absoluteFilePath());
                else
                    res += entity.size();

            return res;
        };

        return process_files(path);
    }
    else
        return path_inf.size();
}
