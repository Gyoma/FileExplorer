#pragma once
#include "FilePercentageStrategy.h"
#include <QHash>


class TypePercentageStrategy : public FilePercentageStrategy
{
public:

    explicit TypePercentageStrategy();
    ~TypePercentageStrategy();

    void DoAndPrint(QString const& path) override;

private:

    //Хэш-таблица типов файлов, значением выступаем общий размер файлов с таким типов в папке
    QHash<QString, uint64_t> types_list;
};

