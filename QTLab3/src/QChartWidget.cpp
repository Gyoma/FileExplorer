#include <include/QChartWidget.h>
#include <algorithm>

QChartWidget::QChartWidget(QWidget* parent, QVector<QPair<QString, uint64_t>> const& data) :
    QWidget(parent),
    files_size(data)
{}

void QChartWidget::setFilesSize(QVector<QPair<QString, uint64_t>> const& Files_size)
{
    files_size = Files_size;
}

void QChartWidget::sort()
{
    if (files_size.size() > 1)
        std::sort(files_size.begin(), files_size.end() - 1, [](QPair<QString, uint64_t>& l, QPair<QString, uint64_t>& r) {return l.second > r.second; });
}

QChart* QChartWidget::createBarChart()
{
    const auto chart = new QChart;
    const auto series = new QBarSeries;
    float total_percent = 0.0;
    QString label;
    float percent;
    bool finish = false;

    // Проходим по всем данным
    for (size_t i = 0; !finish && i < files_size.size() - 1; ++i)
    {
        if (total_percent <= 95.0)
        {
            percent = float(files_size[i].second) / files_size[files_size.size() - 1].second * 100;
            total_percent += percent;
            // Выбираем имена и процентное соотношение
            label = files_size[i].first + " - " + QString::number(percent, 'g', 3) + "%";
        }
        else
        {
            percent = 100.0 - total_percent;
            label = "others - " + QString::number(percent, 'g', 3) + "%";
            finish = true;
        }
        // Создаём set
        QBarSet* set = new QBarSet(label);
        // Заполняем значениями (процентными соотношениями)
        set->append(percent);
        // Добавляем в серию
        series->append(set);
    }

    // Добавляем серию в QChart
    chart->addSeries(series);
    // Выставляем тему 
    chart->setTheme(QChart::ChartTheme::ChartThemeQt);
    // Говорим отображать легенду справа
    chart->legend()->setAlignment(Qt::AlignRight);

    // Возвращаем QChart
    return chart;
}

QChart* QChartWidget::createPieChart()
{
    const auto chart = new QChart;
    const auto series = new QPieSeries;
    float total_percent = 0.0;
    QString label;
    float percent;
    bool finish = false;

    // Проходим по всем данным
    for (size_t i = 0; !finish && i < files_size.size() - 1; ++i)
    {
        if (total_percent <= 95.0)
        {
            percent = float(files_size[i].second) / files_size[files_size.size() - 1].second * 100;
            total_percent += percent;
            // Выбираем имена и процентное соотношение
            label = files_size[i].first + " - " + QString::number(percent, 'g', 3) + "%";
        }
        else
        {
            percent = 100.0 - total_percent;
            label = "others - " + QString::number(percent, 'g', 3) + "%";
            finish = true;
        }
        // Создаём set
        QPieSlice* slice = new QPieSlice(label, percent);
        // Добавляем в серию
        series->append(slice);
    }

    // Добавляем серию в QChart
    chart->addSeries(series);
    // Выставляем тему 
    chart->setTheme(QChart::ChartTheme::ChartThemeQt);
    // Говорим отображать легенду справа
    chart->legend()->setAlignment(Qt::AlignRight);

    // Возвращаем QChart
    return chart;
}

QChart* QChartWidget::createStackedBarChart()
{
    const auto chart = new QChart;
    const auto series = new QStackedBarSeries;
    float total_percent = 0.0;
    QString label;
    float percent;
    bool finish = false;

    // Проходим по всем данным
    for (size_t i = 0; !finish && i < files_size.size() - 1; ++i)
    {
        if (total_percent <= 95.0)
        {
            percent = float(files_size[i].second) / files_size[files_size.size() - 1].second * 100;
            total_percent += percent;
            // Выбираем имена и процентное соотношение
            label = files_size[i].first + " - " + QString::number(percent, 'g', 3) + "%";
        }
        else
        {
            percent = 100.0 - total_percent;
            label = "others - " + QString::number(percent, 'g', 3) + "%";
            finish = true;
        }
        // Создаём set
        QBarSet* set = new QBarSet(label);
        // Заполняем значениями (процентными соотношениями)
        set->append(percent);
        // Добавляем в серию
        series->append(set);
    }

    // Добавляем серию в QChart
    chart->addSeries(series);
    // Выставляем тему 
    chart->setTheme(QChart::ChartTheme::ChartThemeQt);
    // Говорим отображать легенду справа
    chart->legend()->setAlignment(Qt::AlignRight);

    // Возвращаем QChart
    return chart;
}
