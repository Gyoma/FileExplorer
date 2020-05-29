#include "TypePercentageStrategy.h"
#include <functional>


TypePercentageStrategy::TypePercentageStrategy()
{}

TypePercentageStrategy::~TypePercentageStrategy()
{}

void TypePercentageStrategy::DoAndPrint(QString const& path)
{
    //настраиваем фильтр на скрытые файлы и папки
    QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden;
    QFileInfo inf(path);
    uint64_t total_size = 0;

    //рекурсивная функция для подсчета размеров файлов определенного типа
    //параметры:  path - путь до сущности, type - тип, для которого подсчитывать размер ("" - подсчитывать все типы)
    std::function<void(QString const&, QString)> process_files = [&](QString const& path, QString const& type)
    {
        for (auto& entity : QDir(path).entryInfoList(filters))
            if (entity.isDir()) //если папка
                process_files(entity.filePath(), type); //перейти в эту папку
            else
            {
                if (type == "") //если все типы
                    types_list[entity.suffix()] += entity.size(); //в списке типов соответвующему типу прибавить размер
                else
                    if (type == entity.suffix()) //если нужен только конкретный тип, то проверяем тип файла 
                        types_list[entity.suffix()] += entity.size();
            }
    };

    if (inf.isDir())
    {
        total_size = getTotalSize(path, filters);

        //если папка пустая
        if (total_size == 0)
        {
            qcout << inf.filePath() << " is empty" << endl;
            return;
        }

        //обрабытваем все типы, начиная с path
        process_files(path, "");
    }
    else
    {
        total_size = getTotalSize(inf.dir().path(), filters);
        //обрабытваем конкретный тип inf.suffix, начиная с path
        process_files(inf.dir().path(), inf.suffix());
    }

    //проходим по списку типов и выписываем их процентное соотношение
    QHashIterator<QString, uint64_t> it(types_list);
    while (it.hasNext())
    {
        it.next();
        qcout << "*." + it.key() << " = " << double(it.value()) / total_size * 100 << " %" << endl;
    }
}