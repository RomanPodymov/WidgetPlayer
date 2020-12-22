//
//  weatherwidgetadditionaldata.cpp
//  WidgetPlayer
//
//  Created by Roman Podymov on 22/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "weatherwidgetadditionaldata.h"

bool WeatherWidgetAdditionalData::operator == (const AdditionalWidgetData& rhs) const {
    const WeatherWidgetAdditionalData* weatherWidgetAdditionalData = qobject_cast<const WeatherWidgetAdditionalData*>(&rhs);
    if (weatherWidgetAdditionalData == nullptr) {
        return false;
    }
    return APIkey == weatherWidgetAdditionalData->APIkey && location == weatherWidgetAdditionalData->location;
}

WeatherWidgetAdditionalData::WeatherWidgetAdditionalData(QString APIkey, QString location):
    APIkey(APIkey),
    location(location) {

}
