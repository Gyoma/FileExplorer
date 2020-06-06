#pragma once
#include <QAbstractTableModel>

class FileExplorerTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    FileExplorerTableModel(QObject* parent = nullptr, QVector<QPair<QString, uint64_t>> const& Files_size = QVector<QPair<QString, uint64_t>>());

    void setFilesSize(QVector<QPair<QString, uint64_t>> const& Files_size);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

private:
    QVector<QPair<QString, uint64_t>> files_size;
};

