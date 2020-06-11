#pragma once
#include <QWidget>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QPieSeries>
#include <QPieSlice>
#include <QStackedBarSeries>

using namespace QtCharts;

class QChartWidget : public QWidget
{
    Q_OBJECT
public:

    explicit QChartWidget(QWidget* parent = nullptr, QVector<QPair<QString, uint64_t>> const& data = QVector<QPair<QString, uint64_t>>());

    void setFilesSize(QVector<QPair<QString, uint64_t>> const& Files_size);
    void sort();

    QChart* createBarChart();
    QChart* createPieChart();
    QChart* createStackedBarChart();

private:
    QVector<QPair<QString, uint64_t>> files_size;
};

