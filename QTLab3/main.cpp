#include <QtCore/QCoreApplication>
#include <QDir>
#include "FolderPercentageStrategy.h"
#include "TypePercentageStrategy.h"
#include "StrategyContext.h"

using namespace std;

int main(int argc, char *argv[])
{
#if defined( _DEBUG )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    QCoreApplication a(argc, argv);

    StrategyContext context(new FolderPercentageStrategy);
    context.DoAndPrint(QDir::currentPath());

    qcout << endl;

    context.setStrategy(new TypePercentageStrategy);
    context.DoAndPrint(QDir::currentPath());

    return a.exec();
}
