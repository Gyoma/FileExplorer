#include "TypePercentageStrategy.h"
#include <functional>


TypePercentageStrategy::TypePercentageStrategy()
{}

TypePercentageStrategy::~TypePercentageStrategy()
{}

void TypePercentageStrategy::process(QString const& path)
{
    QFileInfo file_inf(path);

    if (file_inf.isDir())
    {

        QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
        uint64_t total_size = getTotalSize(path, filters);

        std::function<void(QString const&)> process_files = [&](QString const& path)
        {
            for (auto& entity : QDir(path).entryInfoList(filters))
                if (entity.isDir())
                    process_files(entity.absoluteFilePath());
                else
                    types_list[entity.suffix()] += entity.size();
        };

        process_files(path);

        QHashIterator<QString, double> it(types_list);

        while (it.hasNext())
        {
            it.next();
            qcout << "." + it.key() << " = " << double(it.value()) / total_size * 100 << "%" << endl;
        }

    }
    else
        qcout << file_inf.suffix() << "  = 100%" << endl;
}