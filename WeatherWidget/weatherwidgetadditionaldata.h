//
//  weatherwidgetadditionaldata.h
//  WeatherWidget
//
//  Created by Roman Podymov on 22/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef WEATHERWIDGETADDITIONALDATA_H
#define WEATHERWIDGETADDITIONALDATA_H

#include "widgetdata.h"

class WeatherWidgetAdditionalData final: public AdditionalWidgetData {
    Q_OBJECT
    friend class WeatherWidget;

public:
    WeatherWidgetAdditionalData(QString APIkey, QString location);
    bool operator == (const AdditionalWidgetData& rhs) const;

private:
    QString APIkey;
    QString location;
};

#endif // WEATHERWIDGETADDITIONALDATA_H
