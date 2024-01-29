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
    const QApplication* application, WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent
): BaseAPIWidget(application, row, item, "https://api.apilayer.com/fixer/convert", [item]{
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    return QMap<QString, QString>(
        {
            {"from", foreignExchangeRatesWidgetAdditionalData->baseCurrency},
            {"to", foreignExchangeRatesWidgetAdditionalData->targetCurrency},
            {"amount", "1"}
        }
    );
}(), [item]{
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    return foreignExchangeRatesWidgetAdditionalData->APIkey;
}(), parent) {

}

void ForeignExchangeRatesWidget::parseRensonse(QString response) {
    const auto& foreignExchangeRatesWidgetAdditionalData = qSharedPointerCast<ForeignExchangeRatesWidgetAdditionalData>(item.additionalWidgetData);
    const auto& jsonResponse = QJsonDocument::fromJson(response.toUtf8());
    const auto& jsonObject = jsonResponse.object();
    const auto& result = jsonObject["result"];
    const auto& targetCurrencyRate = result.toDouble();
    valueLabel->setText(QString::number(targetCurrencyRate) + " " + foreignExchangeRatesWidgetAdditionalData->targetCurrency);
}
