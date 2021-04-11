//
//  foreignexchangerateswidget.h
//  ForeignExchangeRatesWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef FOREIGNEXCHANGERATESWIDGET_H
#define FOREIGNEXCHANGERATESWIDGET_H

#include "baseapiwidget.h"

class ForeignExchangeRatesWidget final: public BaseAPIWidget {
    Q_OBJECT

public:
    ForeignExchangeRatesWidget(const QApplication*, WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);

protected:
    void parseRensonse(QString);
};

#endif // FOREIGNEXCHANGERATESWIDGET_H
