//
//  foreignexchangerateswidgetadditionaldata.h
//  ForeignExchangeRatesWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef FOREIGNEXCHANGERATESWIDGETADDITIONALDATA_H
#define FOREIGNEXCHANGERATESWIDGETADDITIONALDATA_H

#include "widgetdata.h"

class ForeignExchangeRatesWidgetAdditionalData final: public AdditionalWidgetData {
    Q_OBJECT
    friend class ForeignExchangeRatesWidget;

public:
    ForeignExchangeRatesWidgetAdditionalData(QString baseCurrency, QString targetCurrency);
    bool operator == (const AdditionalWidgetData& rhs) const;

private:
    QString baseCurrency;
    QString targetCurrency;
};

#endif // FOREIGNEXCHANGERATESWIDGETADDITIONALDATA_H
