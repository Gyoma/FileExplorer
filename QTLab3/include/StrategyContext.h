#pragma once
#include "FilePercentageStrategy.h"

//Контекст, где хран¤тс¤ указатели на стратегии
class StrategyContext
{
public:

    explicit StrategyContext(FilePercentageStrategy* Strategy = nullptr);
    
    void setStrategy(FilePercentageStrategy* Strategy);
    QVector<QPair<QString, uint64_t>> DoAndPrint(QString const& path);

    ~StrategyContext();

private:

    FilePercentageStrategy* strategy;
};

