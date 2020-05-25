#include "StrategyContext.h"

StrategyContext::StrategyContext(FilePercentageStrategy* Strategy) :
    strategy(Strategy)
{}

void StrategyContext::setStrategy(FilePercentageStrategy* Strategy)
{
    delete strategy;
    strategy = Strategy;
}

void StrategyContext::process(QString const& path)
{
    if (strategy)
        strategy->process(path);
}

StrategyContext::~StrategyContext()
{
    delete strategy;
}
