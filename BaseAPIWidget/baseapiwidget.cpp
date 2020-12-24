//
//  baseapiwidget.cpp
//  BaseAPIWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "baseapiwidget.h"
#include "widgetdata.h"
#include <QNetworkReply>
#include <QUrlQuery>
#include <QVBoxLayout>
#include <QJsonDocument>

BaseAPIWidget::BaseAPIWidget(WidgetData::Row row, WidgetData::Row::Item item, QString apiDomainAndEndpoint, APIQueryItems apiQueryItems, QWidget *parent): BaseWidget(row, item, parent),
    valueLabel(new QLabel(this)),
    apiDomainAndEndpoint(apiDomainAndEndpoint),
    apiQueryItems(apiQueryItems) {
    QPointer<QVBoxLayout> rootLayout(new QVBoxLayout());
    rootLayout->setAlignment(Qt::AlignLeading | Qt::AlignTop);
    setLayout(rootLayout);
    rootLayout->addWidget(valueLabel);
    QPalette valueLabelPalette = valueLabel->palette();
    valueLabelPalette.setColor(valueLabel->foregroundRole(), item.textColor);
    valueLabel->setPalette(valueLabelPalette);
    QObject::connect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onAPIReply(QNetworkReply*)));
    update();
}

void BaseAPIWidget::update() {
    QUrl url(apiDomainAndEndpoint);
    QUrlQuery query;
    for (auto apiQueryItem : apiQueryItems.keys()) {
        query.addQueryItem(apiQueryItem, apiQueryItems.value(apiQueryItem));
    }
    url.setQuery(query);
    networkAccessManager->get(QNetworkRequest(url));
}

void BaseAPIWidget::afterAPIReply() {
    QObject::disconnect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onAPIReply(QNetworkReply*)));
    loadBackgroundImage();
}

void BaseAPIWidget::onAPIReply(QNetworkReply *reply) {
    if (reply->error()) {
        afterAPIReply();
        return;
    }

    parseRensonse(reply->readAll());
    afterAPIReply();
}
