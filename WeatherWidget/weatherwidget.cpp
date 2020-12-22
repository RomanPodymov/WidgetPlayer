//
//  weatherwidget.cpp
//  WidgetPlayer
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

WeatherWidget::WeatherWidget(WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): BaseWidget(row, item, parent),
    currentTemperatureLabel(new QLabel(this)) {
    QPointer<QVBoxLayout> rootLayout(new QVBoxLayout());
    rootLayout->setAlignment(Qt::AlignLeading | Qt::AlignTop);
    setLayout(rootLayout);
    rootLayout->addWidget(currentTemperatureLabel);
    QPalette currentTemperatureLabelPalette = currentTemperatureLabel->palette();
    currentTemperatureLabelPalette.setColor(currentTemperatureLabel->foregroundRole(), item.textColor);
    currentTemperatureLabel->setPalette(currentTemperatureLabelPalette);
    QObject::connect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onWeatherAPIReply(QNetworkReply*)));
    update();
}

void WeatherWidget::update() {
    QUrl weatherURL("http://api.openweathermap.org/data/2.5/weather");
    QUrlQuery weatherQuery;
    const auto& weatherWidgetAdditionalData = qSharedPointerCast<WeatherWidgetAdditionalData>(item.additionalWidgetData);
    weatherQuery.addQueryItem("q", weatherWidgetAdditionalData->location);
    weatherQuery.addQueryItem("APPID", weatherWidgetAdditionalData->APIkey);
    weatherQuery.addQueryItem("units", "metric");
    weatherURL.setQuery(weatherQuery);
    networkAccessManager->get(QNetworkRequest(weatherURL));
}

void WeatherWidget::parseRensonse(QString response) {
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& mainData = jsonObject["main"].toObject();
    const auto& mainDataTemp = mainData["temp"].toDouble();

    currentTemperatureLabel->setText(QString::number(mainDataTemp));
}

void WeatherWidget::afterWeatherAPIReply() {
    QObject::disconnect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onWeatherAPIReply(QNetworkReply*)));
    loadBackgroundImage();
}

void WeatherWidget::onWeatherAPIReply(QNetworkReply *reply) {
    if (reply->error()) {
        afterWeatherAPIReply();
        return;
    }

    parseRensonse(reply->readAll());
    afterWeatherAPIReply();
}
