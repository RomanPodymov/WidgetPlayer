//
//  foreignexchangerateswidgetadditionaldata.cpp
//  ForeignExchangeRatesWidget
//
//  Created by Roman Podymov on 23/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "foreignexchangerateswidgetadditionaldata.h"

bool ForeignExchangeRatesWidgetAdditionalData::operator == (const AdditionalWidgetData& rhs) const {
    const ForeignExchangeRatesWidgetAdditionalData* foreignExchangeRatesWidgetAdditionalData = qobject_cast<const ForeignExchangeRatesWidgetAdditionalData*>(&rhs);
    if (foreignExchangeRatesWidgetAdditionalData == nullptr) {
        return false;
    }
    return baseCurrency == foreignExchangeRatesWidgetAdditionalData->baseCurrency && targetCurrency == foreignExchangeRatesWidgetAdditionalData->targetCurrency;
}

ForeignExchangeRatesWidgetAdditionalData::ForeignExchangeRatesWidgetAdditionalData(QString baseCurrency, QString targetCurrency):
    baseCurrency(baseCurrency),
    targetCurrency(targetCurrency) {

}
