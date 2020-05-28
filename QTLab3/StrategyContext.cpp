#include "StrategyContext.h"

StrategyContext::StrategyContext(FilePercentageStrategy* Strategy) :
    strategy(Strategy)
{}

void StrategyContext::setStrategy(FilePercentageStrategy* Strategy)
{
    delete strategy;
    strategy = Strategy;
}

void StrategyContext::DoAndPrint(QString const& path)
{
    if (strategy)
        strategy->DoAndPrint(path);
}

StrategyContext::~StrategyContext()
{
    delete strategy;
}
