//
//  foreignexchangerateswidget.cpp
//  ForeignExchangeRatesWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "foreignexchangerateswidget.h"
#include "foreignexchangerateswidgetadditionaldata.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include <QVBoxLayout>
#include <QJsonDocument>

ForeignExchangeRatesWidget::ForeignExchangeRatesWidget(WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): BaseWidget(row, item, parent),
    currentRateLabel(new QLabel(this)) {
    QPointer<QVBoxLayout> rootLayout(new QVBoxLayout());
    rootLayout->setAlignment(Qt::AlignLeading | Qt::AlignTop);
    setLayout(rootLayout);
    rootLayout->addWidget(currentRateLabel);
    QPalette currentRateLabelPalette = currentRateLabel->palette();
    currentRateLabelPalette.setColor(currentRateLabel->foregroundRole(), item.textColor);
    currentRateLabel->setPalette(currentRateLabelPalette);
    QObject::connect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onAPIReply(QNetworkReply*)));
    update();
}

void ForeignExchangeRatesWidget::update() {
    QUrl url("https://api.exchangeratesapi.io/latest");
    QUrlQuery query;
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    query.addQueryItem("base", foreignExchangeRatesWidgetAdditionalData->baseCurrency);
    url.setQuery(query);
    networkAccessManager->get(QNetworkRequest(url));
}

void ForeignExchangeRatesWidget::parseRensonse(QString response) {
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& rates = jsonObject["rates"].toObject();
    const auto& targetCurrencyRate = rates[foreignExchangeRatesWidgetAdditionalData->targetCurrency].toDouble();
    currentRateLabel->setText(QString::number(targetCurrencyRate));
}

void ForeignExchangeRatesWidget::afterAPIReply() {
    QObject::disconnect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onAPIReply(QNetworkReply*)));
    loadBackgroundImage();
}

void ForeignExchangeRatesWidget::onAPIReply(QNetworkReply *reply) {
    if (reply->error()) {
        afterAPIReply();
        return;
    }

    parseRensonse(reply->readAll());
    afterAPIReply();
}
