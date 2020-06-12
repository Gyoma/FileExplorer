#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include <QApplication>
#include <QDir>
#include <QString>
#include <QTextStream>
#include <include/FolderPercentageStrategy.h>
#include <include/TypePercentageStrategy.h>
#include <include/StrategyContext.h>
#include <include/FileExplorer.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FileExplorer exp;

    exp.show();

    return a.exec();
}
