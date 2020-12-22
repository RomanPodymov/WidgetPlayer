//
//  basewidget.h
//  WidgetPlayer
//
//  Created by Roman Podymov on 07/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include "widgetdata.h"
#include <QWidget>
#include <QNetworkAccessManager>

class BaseWidget : public QWidget {
    Q_OBJECT

public:
    BaseWidget(WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);
    void setupSize(QSize rootScreenSize);

public slots:
    void onRootScreenSizeChanged(QSize);

protected:
    void loadBackgroundImage();

private slots:
    void onBackgroundImageReply(QNetworkReply*);

protected:
    const QSharedPointer<QNetworkAccessManager> networkAccessManager;
    const WidgetData::Row row;
    const WidgetData::Row::Item item;
};

#endif // BASEWIDGET_H
