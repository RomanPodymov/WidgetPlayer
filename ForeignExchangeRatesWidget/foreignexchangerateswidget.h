//
//  foreignexchangerateswidget.h
//  ForeignExchangeRatesWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef FOREIGNEXCHANGERATESWIDGET_H
#define FOREIGNEXCHANGERATESWIDGET_H

#include "basewidget.h"
#include <QPointer>
#include <QLabel>

class ForeignExchangeRatesWidget: public BaseWidget {
    Q_OBJECT

public:
    ForeignExchangeRatesWidget(WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);

private:
    void update();
    void parseRensonse(QString);
    void afterAPIReply();

private slots:
    void onAPIReply(QNetworkReply*);

private:
    QPointer<QLabel> currentRateLabel;
};

#endif // FOREIGNEXCHANGERATESWIDGET_H
