#include "TypePercentageStrategy.h"
#include <functional>


TypePercentageStrategy::TypePercentageStrategy()
{}

TypePercentageStrategy::~TypePercentageStrategy()
{}

void TypePercentageStrategy::DoAndPrint(QString const& path)
{
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    QFileInfo inf(path);
    uint64_t total_size = 0;

    std::function<void(QString const&, QString)> process_files = [&](QString const& path, QString const& type)
    {
        for (auto& entity : QDir(path).entryInfoList(filters))
            if (entity.isDir())
                process_files(entity.filePath(), type);
            else
            {
                if (type == "")
                    types_list[entity.suffix()] += entity.size();
                else
                    if (type == entity.suffix())
                        types_list[entity.suffix()] += entity.size();
            }
    };

    if (inf.isDir())
    {
        total_size = getTotalSize(path, filters);

        if (total_size == 0)
        {
            qcout << inf.filePath() << " is empty" << endl;
            return;
        }

        process_files(path, "");
    }
    else
    {
        total_size = getTotalSize(inf.dir().path(), filters);
        process_files(inf.dir().path(), inf.suffix());
    }

    QHashIterator<QString, double> it(types_list);
    while (it.hasNext())
    {
        it.next();
        qcout << "*." + it.key() << " = " << double(it.value()) / total_size * 100 << " %" << endl;
    }
}