//
//  weatherwidget.h
//  WeatherWidget
//
//  Created by Roman Podymov on 08/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef WEATHERWIDGET_H
#define WEATHERWIDGET_H

#include "baseapiwidget.h"

class WeatherWidget final: public BaseAPIWidget {
    Q_OBJECT

public:
    WeatherWidget(const QApplication*, WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);
    CREATE_WIDGET(WeatherWidget)

protected:
    void parseRensonse(QString);

private:
    static QString createTemperatureString(int);
};

#endif // WEATHERWIDGET_H
