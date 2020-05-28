#pragma once
#include <QString>
#include <QList>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>

static QTextStream qcout(stdout);

class FilePercentageStrategy
{
public:

    struct FileInfo
    {
        QString name;
        double percent;
    };

    explicit FilePercentageStrategy();
    virtual ~FilePercentageStrategy();

    uint64_t getTotalSize(QString const& path, QDir::Filters filters = QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden);

    virtual void DoAndPrint(QString const& path) = 0;
};

