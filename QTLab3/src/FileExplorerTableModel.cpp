#include <include/FileExplorerTableModel.h>
#include <QLocale>

FileExplorerTableModel::FileExplorerTableModel(QObject* parent, QVector<QPair<QString, uint64_t>> const& Files_size) :
    QAbstractTableModel(parent),
    files_size(Files_size)
{}

void FileExplorerTableModel::setFilesSize(QVector<QPair<QString, uint64_t>> const& Files_size)
{
    files_size = Files_size;
}

int FileExplorerTableModel::rowCount(const QModelIndex&) const
{
    return files_size.size() - 1;
}

int FileExplorerTableModel::columnCount(const QModelIndex&) const
{
    return 3;
}

QVariant FileExplorerTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        switch (section)
        {
        case 0: 
            return QString("File Name");
        case 1: 
            return QString("Size");
        case 2: 
            return QString("Percentage");
        }
    }

    return QVariant();
}

QVariant FileExplorerTableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole && index.isValid() && index.row() <= files_size.size())
    {
        switch (index.column())
        {
        case 0:
            return QString(files_size[index.row()].first);
        case 1:
            return QLocale(QLocale::English).formattedDataSize(files_size[index.row()].second);
        case 2:
            double percent = double(files_size[index.row()].second) / files_size[files_size.size() - 1].second * 100;
            return (percent >= 1 ? QString::number(percent) : "< 1") + " %";
        }
    }

    return QVariant();
}
