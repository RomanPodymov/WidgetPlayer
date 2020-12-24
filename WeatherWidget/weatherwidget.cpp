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

WeatherWidget::WeatherWidget(WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): BaseAPIWidget(row, item, parent) {

}

void WeatherWidget::parseRensonse(QString response) {
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& mainData = jsonObject["main"].toObject();
    const auto& mainDataTemp = mainData["temp"].toDouble();
    valueLabel->setText((mainDataTemp > 0 ? "+" : "-") + WeatherWidget::tr("%n degree(s)", "", abs(mainDataTemp)));
}

QString WeatherWidget::getAPIDomainAndEndpoint() {
    return "http://api.openweathermap.org/data/2.5/weather";
}

APIQueryItems WeatherWidget::getAPIQueryItems() {
    const auto& weatherWidgetAdditionalData = qSharedPointerCast<WeatherWidgetAdditionalData>(item.additionalWidgetData);
    return QMap<QString,QString>(
        {
            {"q",weatherWidgetAdditionalData->location},
            {"APPID",weatherWidgetAdditionalData->APIkey},
            {"units","metric"}
        }
    );
}
