#pragma once
#include "FilePercentageStrategy.h"

class FolderPercentageStrategy : public FilePercentageStrategy
{
public:

    explicit FolderPercentageStrategy();
    ~FolderPercentageStrategy();

    void DoAndPrint(QString const& path) override;
};

