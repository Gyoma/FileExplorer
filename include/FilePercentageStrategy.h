#pragma once
#include <QString>
#include <QVector>
#include <QTextStream>
#include <QDir>

//аналог потоку вывода std::cout для вывода объектов классов qt
static QTextStream qcout(stdout);

/*
    FilePercentageStrategy - интерфейс всех стратегий.
    
    getTotalSize - метод получения размера сущности (файла, папки) в байтах.
    параметры: path - путь до сущности, filters - фильтры сущностей, которые учитывается при подсчете размера.

    Do - чистый виртуальный метод. Через этот метод выполняется алгоритм соответсвующей стратегии,
    результат выписывается в поток вывода - qcout.
    параметры: path - путь до сущности, которая будет обрабатываться в соответсвии с алгоритмом.
*/


class FilePercentageStrategy
{
public:

    explicit FilePercentageStrategy();
    virtual ~FilePercentageStrategy();

    uint64_t getTotalSize(QString const& path, QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden) const;

    virtual QVector<QPair<QString, uint64_t>> Do(QString const& path) = 0;
};

