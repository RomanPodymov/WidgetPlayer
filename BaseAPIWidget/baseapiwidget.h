//
//  baseapiwidget.h
//  BaseAPIWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef BASEAPIWIDGET_H
#define BASEAPIWIDGET_H

#include "basewidget.h"
#include <QPointer>
#include <QLabel>

using APIQueryItems = QMap<QString, QString>;

class BaseAPIWidget: public BaseWidget {
    Q_OBJECT

public:
    BaseAPIWidget(WidgetData::Row, WidgetData::Row::Item, QString, APIQueryItems, QWidget *parent = nullptr);

protected:
    virtual void parseRensonse(QString) = 0;

private:
    void update();
    void afterAPIReply();

private slots:
    void onAPIReply(QNetworkReply*);

protected:
    const QPointer<QLabel> valueLabel;

protected:
    const QString apiDomainAndEndpoint;
    const APIQueryItems apiQueryItems;
};

#endif // BASEAPIWIDGET_H
