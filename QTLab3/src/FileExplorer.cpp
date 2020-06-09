#include <include/FileExplorer.h>
#include <include/FolderPercentageStrategy.h>
#include <include/TypePercentageStrategy.h>

FileExplorer::FileExplorer(QWidget* parent, FileExplorer::StrategyType strat_type) :
    QWidget(parent),
    ui(new Ui::FileExplorer),
    file_sistem(new QFileSystemModel(this)),
    table_model(new FileExplorerTableModel(this))
{
    //настраиваем UI
    ui->setupUi(this);
    //устанавливаем корневой путь в файловой модели
    file_sistem->setRootPath(QDir::homePath());
    //устанавливаем модель
    ui->treeView->setModel(file_sistem);
    //устанавливаем ратяжение колонок в qtreeview по размеру содержимого
    ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //устанавливаем модель
    ui->tableView->setModel(table_model);

    //устанавливаем соответсвующую стратегию
    if (strat_type == StrategyType::byFolder)
        strat_context.setStrategy(new FolderPercentageStrategy);
    else
        strat_context.setStrategy(new TypePercentageStrategy);

    //настраиваем сигнально-слотный механизм
    connect(ui->Strategy_cbox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FileExplorer::setGroupingStrategy);
    connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileExplorer::folderChanged);
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &FileExplorer::processFileSorting);
}

void FileExplorer::folderChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
    //обновляем текущий путь до новой выбранной папки
    current_path = file_sistem->filePath(selected.indexes()[0]);
    //обновляем данные в модели
    table_model->setFilesSize(strat_context.DoAndPrint(current_path));
    //обновляем отображение данных модели
    if (!processFileSorting(ui->checkBox->checkState()))
        emit table_model->layoutChanged();
}

bool FileExplorer::processFileSorting(int state)
{
    if (state == Qt::CheckState::Checked)
    {
        table_model->sort();
        emit table_model->layoutChanged();
        return true;
    }

    return false;
}

void FileExplorer::setGroupingStrategy(qint32 const& index)
{
    //устанавливаем соответсвующую страте
    switch (index)
    {
    case 0:
        strat_context.setStrategy(new FolderPercentageStrategy());
        break;
    case 1:
        strat_context.setStrategy(new TypePercentageStrategy());
        break;
    }

    //если папка не выбрана, то выходим
    if (current_path.isEmpty())
        return;

    //обновляем данные модели
    table_model->setFilesSize(strat_context.DoAndPrint(current_path));
    //обновляем содержимое
    if (!processFileSorting(ui->checkBox->checkState()))
        emit table_model->layoutChanged();
}