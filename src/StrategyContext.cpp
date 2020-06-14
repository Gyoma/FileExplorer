#include <include/StrategyContext.h>

StrategyContext::StrategyContext(FilePercentageStrategy* Strategy) :
    strategy(Strategy)
{}

void StrategyContext::setStrategy(FilePercentageStrategy* Strategy)
{
    delete strategy;
    strategy = Strategy;
}

QVector<QPair<QString, uint64_t>> StrategyContext::Do(QString const& path)
{
    if (strategy)
        return strategy->Do(path);

    return QVector<QPair<QString, uint64_t>>();
}

StrategyContext::~StrategyContext()
{
    delete strategy;
}
