#pragma once
#include "FilePercentageStrategy.h"

class FolderPercentageStrategy : public FilePercentageStrategy
{
public:

    explicit FolderPercentageStrategy();
    ~FolderPercentageStrategy();

    QVector<QPair<QString, uint64_t>> Do(QString const& path) override;
};

