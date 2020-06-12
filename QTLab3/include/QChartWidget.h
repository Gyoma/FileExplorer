#pragma once
#include <QWidget>
#include <QChart>
#include <QBarSeries>
#include <QBarSet>
#include <QPieSeries>
#include <QPieSlice>
#include <QStackedBarSeries>

using namespace QtCharts;

/*
QChartWidget - Написанный виджет для создания диаграмм. Наследуется от QWidget.
files_size - структура для храния названия файлов и их размеров.
*/

class QChartWidget : public QWidget
{
    Q_OBJECT
public:

    explicit QChartWidget(QWidget* parent = nullptr, QVector<QPair<QString, uint64_t>> const& data = QVector<QPair<QString, uint64_t>>());

    //установка данных в files_size
    void setFilesSize(QVector<QPair<QString, uint64_t>> const& Files_size);
    //сортировка данных
    void sort();

    //столбачая гистограмма
    QChart* createBarChart();
    //круговая
    QChart* createPieChart();
    //гистограмма с накоплением
    QChart* createStackedBarChart();

private:
    QVector<QPair<QString, uint64_t>> files_size;
};

