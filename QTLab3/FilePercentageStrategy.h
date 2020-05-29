#pragma once
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

//аналог потоку вывода std::cout для вывода объектов классов qt
static QTextStream qcout(stdout);

/*
    FilePercentageStrategy - интерфейс всех стратегий.
    
    getTotalSize - метод получения размера сущности (файла, папки) в байтах.
    параметры: path - путь до сущности, filters - фильтры сущностей, которые учитывается при подсчете размера.

    DoAndPrint - чистый виртуальный метод. Через этот метод выполняется алгоритм соответсвующей стратегии,
    результат выписывается в потом вывода - qcout.
    параметры: path - путь до сущности, которая будет обрабатываться в соответсвии с алгоритмом.
*/


class FilePercentageStrategy
{
public:

    explicit FilePercentageStrategy();
    virtual ~FilePercentageStrategy();

    uint64_t getTotalSize(QString const& path, QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden) const;

    virtual void DoAndPrint(QString const& path) = 0;
};

