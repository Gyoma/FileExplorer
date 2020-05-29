#include <QtCore/QCoreApplication>
#include <QDir>
#include "FolderPercentageStrategy.h"
#include "TypePercentageStrategy.h"
#include "StrategyContext.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //создание контекста, передаем стратегию группировки по файлам и папкам
    StrategyContext context(new FolderPercentageStrategy);
    //выполняется алгоритм стратегии и печается результат
    context.DoAndPrint(QDir::currentPath() + "/main.cpp");

    qcout << endl;

    //устанавливается новая стратегия - группировки по типам
    context.setStrategy(new TypePercentageStrategy);
    context.DoAndPrint(QDir::currentPath() + "/main.cpp");

    return a.exec();
}
