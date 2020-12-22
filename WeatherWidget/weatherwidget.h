//
//  weatherwidget.h
//  WidgetPlayer
//
//  Created by Roman Podymov on 08/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include "basewidget.h"
#include <QPointer>
#include <QLabel>

class WeatherWidget: public BaseWidget {
    Q_OBJECT

public:
    WeatherWidget(WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);

private:
    void update();
    void parseRensonse(QString);
    void afterWeatherAPIReply();

private slots:
    void onWeatherAPIReply(QNetworkReply*);

private:
    QPointer<QLabel> currentTemperatureLabel;
};

#endif // WEATHERWIDGET_H
