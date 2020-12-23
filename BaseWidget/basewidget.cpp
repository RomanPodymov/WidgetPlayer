//
//  basewidget.cpp
//  BaseWidget
//
//  Created by Roman Podymov on 07/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "basewidget.h"
#include <QNetworkReply>

BaseWidget::BaseWidget(WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): QWidget(parent),
    networkAccessManager(new QNetworkAccessManager()),
    row(row),
    item(item) {

}

void BaseWidget::setupSize(QSize rootScreenSize) {
    switch (row.heightValueType) {
        case WidgetData::WidgetSizeValueType::absolute:
            setFixedHeight(row.height.absolute.value);
            break;
        case WidgetData::WidgetSizeValueType::percentage:
            setFixedHeight(rootScreenSize.height() * (row.height.percentage.value/100));
            break;
        default:
            break;
    }
    switch (item.widthValueType) {
        case WidgetData::WidgetSizeValueType::absolute:
            setFixedWidth(item.width.absolute.value);
            break;
        case WidgetData::WidgetSizeValueType::percentage:
            setFixedWidth(rootScreenSize.width() * (item.width.percentage.value/100));
            break;
        default:
            break;
    }
}

void BaseWidget::onRootScreenSizeChanged(QSize rootScreenSize) {
    setupSize(rootScreenSize);
}

void BaseWidget::loadBackgroundImage() {
    if (item.backgroundImage.isEmpty()) {
        return;
    }

    QObject::connect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onBackgroundImageReply(QNetworkReply*)));
    networkAccessManager->get(QNetworkRequest(item.backgroundImage));
}

void BaseWidget::onBackgroundImageReply(QNetworkReply* reply) {
    if (reply->error()) {
        QObject::disconnect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onBackgroundImageReply(QNetworkReply*)));
        return;
    }

    QPixmap pixmap;
    pixmap.loadFromData(reply->readAll());
    pixmap = pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    auto paletteValue = palette();
    paletteValue.setBrush(QPalette::Window, pixmap);
    setAutoFillBackground(true);
    setPalette(paletteValue);

    QObject::disconnect(networkAccessManager.get(), SIGNAL(finished(QNetworkReply*)), this, SLOT(onBackgroundImageReply(QNetworkReply*)));
}
