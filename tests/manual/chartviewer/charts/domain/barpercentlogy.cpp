/******************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Charts module.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
******************************************************************************/

#include "charts.h"
#include <QtCharts/QChart>
#include <QtCharts/QPercentBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QBarCategoryAxis>

class BarPercentLogY: public Chart
{
public:
    QString name() { return "PercentBar"; }
    QString category()  { return QObject::tr("Domain"); }
    QString subCategory() { return "Vertical Log"; }

    QChart *createChart(const DataTable &table)
    {
        QChart *chart = new QChart();
        chart->setTitle("PercentBar: BarCateogry X, Log Y");

        QString name("Series ");
        QPercentBarSeries *series = new QPercentBarSeries(chart);
        QLogValueAxis *logvalueaxis = new QLogValueAxis();
        logvalueaxis->setBase(2);
        QBarCategoryAxis *barcategory = new QBarCategoryAxis();
        for (int i(0); i < table.count(); i++) {
            QBarSet *set = new QBarSet("Bar set " + QString::number(i));
            foreach (Data data, table[i])
                *set << data.first.y();
            series->append(set);
        }
        chart->addSeries(series);

        int count = series->barSets().first()->count();


        for (int i = 0; i < count; i++) {
            barcategory->append("BarSet " + QString::number(i));
        }

        chart->setAxisY(logvalueaxis, series);
        chart->setAxisX(barcategory, series);

        return chart;
    }
};

DECLARE_CHART(BarPercentLogY);
