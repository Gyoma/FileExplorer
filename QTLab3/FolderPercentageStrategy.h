#pragma once
#include "FilePercentageStrategy.h"

class FolderPercentageStrategy : public FilePercentageStrategy
{
public:

    explicit FolderPercentageStrategy();
    ~FolderPercentageStrategy();

    void process(QString const& path) override;
};

