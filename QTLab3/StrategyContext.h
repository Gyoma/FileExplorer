#pragma once
#include "FilePercentageStrategy.h"

//Контекст, где хран¤тс¤ указатели на стратегии
class StrategyContext
{
public:

    explicit StrategyContext(FilePercentageStrategy* Strategy = nullptr);
    
    void setStrategy(FilePercentageStrategy* Strategy);
    void DoAndPrint(QString const& path);

    ~StrategyContext();

private:

    FilePercentageStrategy* strategy;
};

