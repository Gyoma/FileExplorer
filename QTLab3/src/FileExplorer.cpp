#include <include/FileExplorer.h>
#include <include/FolderPercentageStrategy.h>
#include <include/TypePercentageStrategy.h>

FileExplorer::FileExplorer(QWidget *parent, FileExplorer::StrategyType strat_type):
	QWidget(parent),
	ui(new Ui::FileExplorer),
	file_sistem(new QFileSystemModel(this)),
	table_model(new FileExplorerTableModel(this))
{
	ui->setupUi(this);
	file_sistem->setRootPath(QDir::homePath());
	ui->treeView->setModel(file_sistem);
	ui->treeView->header()->setSectionResizeMode(QHeaderView::ResizeToContents);

	if (strat_type == StrategyType::byFolder)
		strat_context.setStrategy(new FolderPercentageStrategy);
	else
		strat_context.setStrategy(new TypePercentageStrategy);

	connect(ui->Strategy_cbox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &FileExplorer::setGroupingStrategy);
	connect(ui->treeView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileExplorer::strategyChanged);
}

void FileExplorer::strategyChanged(const QItemSelection& selected, const QItemSelection& deselected)
{
	currentPath = file_sistem->filePath(selected.indexes()[0]);
	ui->tableView->setModel(new FileExplorerTableModel(this, strat_context.DoAndPrint(currentPath)));
}

void FileExplorer::setGroupingStrategy(qint32 const& index)
{
	switch (index)
	{
	case 0:
		strat_context.setStrategy(new FolderPercentageStrategy());
		break;
	case 1:
		strat_context.setStrategy(new TypePercentageStrategy());
		break;
	}

	if (currentPath.isEmpty())
		return;

	ui->tableView->setModel(new FileExplorerTableModel(this, strat_context.DoAndPrint(currentPath)));
}