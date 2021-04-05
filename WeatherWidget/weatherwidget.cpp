//
//  weatherwidget.cpp
//  WeatherWidget
//
//  Created by Roman Podymov on 08/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "weatherwidget.h"
#include "weatherwidgetadditionaldata.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include <QVBoxLayout>
#include <QJsonDocument>

WeatherWidget::WeatherWidget(
    WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent
): BaseAPIWidget(row, item, "http://api.openweathermap.org/data/2.5/weather", [item]{
    const auto& weatherWidgetAdditionalData = qSharedPointerCast<WeatherWidgetAdditionalData>(item.additionalWidgetData);
    return QMap<QString,QString>(
        {
            {"q",weatherWidgetAdditionalData->location},
            {"APPID",weatherWidgetAdditionalData->APIkey},
            {"units","metric"}
        }
    );
}(), parent) {
    if (!translator.load(":/translations_weather/weather_strings")) {
        BaseWidget::showAlert("Failed to load /translations_weather/weather_strings");
        exit(EXIT_FAILURE);
    }
}

void WeatherWidget::parseRensonse(QString response) {
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& mainData = jsonObject["main"].toObject();
    const auto& mainDataTemp = mainData["temp"].toDouble();
    valueLabel->setText(WeatherWidget::createTemperatureString(mainDataTemp));
}

QString WeatherWidget::createTemperatureString(int value) {
    QString temperatureSign;
    if (value == 0) {
        temperatureSign = "";
    } else if (value < 0) {
        temperatureSign = "-";
    } else {
        temperatureSign = "+";
    }
    return temperatureSign + WeatherWidget::tr("%n degree(s)", "", abs(value));
}
