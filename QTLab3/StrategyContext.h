#pragma once
#include "FilePercentageStrategy.h"

class StrategyContext
{
public:

    explicit StrategyContext(FilePercentageStrategy* Strategy = nullptr);
    
    void setStrategy(FilePercentageStrategy* Strategy);
    void process(QString const& path);

    ~StrategyContext();

private:

    FilePercentageStrategy* strategy;
};

