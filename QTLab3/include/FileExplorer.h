#include <ui_FileExplorer.h>
#include <QWidget>
#include <QFileSystemModel>
#include <include/StrategyContext.h>
#include <include/FileExplorerTableModel.h>

//forward declaration класса UI, который будет скомпилирован компил¤тором qt
namespace Ui
{
    class FileExplorer;
}

//класс, отвечающий за главное окно, здесь хран¤тс¤ все модели и все виды
class FileExplorer : public QWidget
{
    Q_OBJECT

public:

    //тип выбранной стратегии
    enum class StrategyType
    {
        byFolder = 0,
        byType = 2
    };

    FileExplorer(QWidget* parent = nullptr, FileExplorer::StrategyType strat_type = StrategyType::byFolder);

public slots:
    //слот изменени¤ стратегии
    void setGroupingStrategy(qint32 const& index);
    //слот изменени¤ папки
    void folderChanged(const QItemSelection& selected, const QItemSelection& deselected);

private:

    QFileSystemModel* file_sistem;
    //контекст стратегий
    StrategyContext strat_context;
    FileExplorerTableModel* table_model;
    //тукущий путь до выбранной папки
    QString current_path;
    Ui::FileExplorer* ui;
};