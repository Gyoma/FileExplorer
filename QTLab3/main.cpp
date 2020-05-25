#include <QtCore/QCoreApplication>
#include <QDir>
#include "FolderPercentageStrategy.h"
#include "TypePercentageStrategy.h"
#include "StrategyContext.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if defined( _DEBUG )
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    StrategyContext context(new FolderPercentageStrategy);
    context.process(QDir::currentPath());

    //qcout << endl;

    //context.setStrategy(new TypePercentageStrategy);
    //context.process(QDir::currentPath());

    return a.exec();
}
