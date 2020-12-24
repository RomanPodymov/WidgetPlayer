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

ForeignExchangeRatesWidget::ForeignExchangeRatesWidget(
    WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent
): BaseAPIWidget(row, item, "https://api.exchangeratesapi.io/latest", [item]{
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    return QMap<QString,QString>({{"base",foreignExchangeRatesWidgetAdditionalData->baseCurrency}});
}(), parent) {

}

void ForeignExchangeRatesWidget::parseRensonse(QString response) {
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& rates = jsonObject["rates"].toObject();
    const auto& targetCurrencyRate = rates[foreignExchangeRatesWidgetAdditionalData->targetCurrency].toDouble();
    valueLabel->setText(QString::number(targetCurrencyRate) + " " + foreignExchangeRatesWidgetAdditionalData->targetCurrency);
}
