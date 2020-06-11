#pragma once
#include <include/FilePercentageStrategy.h>
#include <QHash>


class TypePercentageStrategy : public FilePercentageStrategy
{
public:

    explicit TypePercentageStrategy();
    ~TypePercentageStrategy();

    QVector<QPair<QString, uint64_t>> Do(QString const& path) override;
};

