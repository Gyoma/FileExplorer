#include <ui_FileExplorer.h>
#include <QWidget>
#include <QFileSystemModel>
#include <include/StrategyContext.h>
#include <include/FileExplorerTableModel.h>

namespace Ui
{
    class FileExplorer;
}

class FileExplorer : public QWidget
{
    Q_OBJECT

public:

    enum class StrategyType
    {
        byFolder = 0,
        byType = 2
    };

    FileExplorer(QWidget* parent = nullptr, FileExplorer::StrategyType strat_type = StrategyType::byFolder);

public slots:
    void setGroupingStrategy(qint32 const& index);
    void folderChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:

    QFileSystemModel* file_sistem;
    StrategyContext strat_context;
    FileExplorerTableModel* table_model;
    QString currentPath;
    Ui::FileExplorer* ui;
};