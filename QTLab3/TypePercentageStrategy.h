#pragma once
#include "FilePercentageStrategy.h"
#include <QHash>


class TypePercentageStrategy : public FilePercentageStrategy
{
public:

    explicit TypePercentageStrategy();
    ~TypePercentageStrategy();

    void process(QString const& path) override;

private:
    QHash<QString, double> types_list;
};

