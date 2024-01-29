//
//  widgetdata.cpp
//  BaseWidget
//
//  Created by Roman Podymov on 07/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "widgetdata.h"

bool AdditionalWidgetData::operator != (const AdditionalWidgetData& rhs) const {
    return !(*this == rhs);
}

WidgetData::WidgetData() {
    updateIntervalInSeconds = 10;
}

WidgetData::WidgetType WidgetData::widgetTypeFromString(QString typeString) {
    if (typeString == "rates") {
        return WidgetData::WidgetType::foreignexchangerates;
    } else if (typeString == "weather") {
        return WidgetData::WidgetType::weather;
    } else if (typeString == "player") {
        return WidgetData::WidgetType::player;
    } else {
        return WidgetData::WidgetType::unknown;
    }
}

WidgetData::WidgetSizeValueType WidgetData::widgetSizeValueType(QString sizeValueString) {
    if (sizeValueString.endsWith("%")) {
        return WidgetData::WidgetSizeValueType::percentage;
    } else {
        return WidgetData::WidgetSizeValueType::absolute;
    }
}

WidgetData::WidgetSizeValue WidgetData::widgetSizeValue(QString sizeValueString) {
    WidgetData::WidgetSizeValue result;
    switch (WidgetData::widgetSizeValueType(sizeValueString)) {
        case WidgetData::WidgetSizeValueType::percentage: {
            const auto sizeValue = QStringView{sizeValueString}.left(sizeValueString.size() - 1).toDouble();
            WidgetData::WidgetSizeValue::Percentage percentageData;
            percentageData.value = sizeValue;
            result.percentage = percentageData;
            break;
        }
        case WidgetData::WidgetSizeValueType::absolute: {
            const auto sizeValue = sizeValueString.toDouble();
            WidgetData::WidgetSizeValue::Absolute absoluteData;
            absoluteData.value = sizeValue;
            result.absolute = absoluteData;
            break;
        }
        default:
            break;
    }
    return result;
}

WidgetData::Row::Item::Item(QString typeString, QString widthString, QString backgroundURL, QString textColorString) {
    widgetType = WidgetData::widgetTypeFromString(typeString);
    widthValueType = WidgetData::widgetSizeValueType(widthString);
    width = WidgetData::widgetSizeValue(widthString);
    backgroundImage = QUrl(backgroundURL);
    if (textColorString.isEmpty()) {
        textColor = QColor(255, 255, 255);
    } else {
        textColor = QColor(textColorString);
    }
}

WidgetData::Row::Row(QString heightString) {
    heightValueType = WidgetData::widgetSizeValueType(heightString);
    height = WidgetData::widgetSizeValue(heightString);
}

bool operator == (const WidgetData& lhs, const WidgetData& rhs) {
    return lhs.updateIntervalInSeconds == rhs.updateIntervalInSeconds && lhs.rows == rhs.rows;
}

bool operator == (const WidgetData::Row& lhs, const WidgetData::Row& rhs) {
    if (lhs.heightValueType != rhs.heightValueType) {
        return false;
    }
    switch (lhs.heightValueType) {
        case WidgetData::WidgetSizeValueType::absolute:
            if (lhs.height.absolute.value != rhs.height.absolute.value) {
                return false;
            }
            break;
        case WidgetData::WidgetSizeValueType::percentage:
            if (lhs.height.percentage.value != rhs.height.percentage.value) {
                return false;
            }
            break;
    }
    return lhs.items == rhs.items;
}

bool operator == (const WidgetData::Row::Item& lhs, const WidgetData::Row::Item& rhs) {
    if (lhs.widthValueType != rhs.widthValueType) {
        return false;
    }
    switch (lhs.widthValueType) {
        case WidgetData::WidgetSizeValueType::absolute:
            if (lhs.width.absolute.value != rhs.width.absolute.value) {
                return false;
            }
            break;
        case WidgetData::WidgetSizeValueType::percentage:
            if (lhs.width.percentage.value != rhs.width.percentage.value) {
                return false;
            }
            break;
    }
    if (lhs.backgroundImage != rhs.backgroundImage || lhs.textColor != rhs.textColor) {
        return false;
    }
    const AdditionalWidgetData* lhsAdditionalWidgetData = lhs.additionalWidgetData.get();
    const AdditionalWidgetData* rhsAdditionalWidgetData = rhs.additionalWidgetData.get();
    if (lhsAdditionalWidgetData != nullptr && rhsAdditionalWidgetData != nullptr) {
        return *lhsAdditionalWidgetData == *rhsAdditionalWidgetData;
    } else {
        return lhsAdditionalWidgetData == nullptr && rhsAdditionalWidgetData == nullptr;
    }
}

bool operator != (const WidgetData &lhs, const WidgetData &rhs) {
    return !(lhs == rhs);
}

bool operator != (const WidgetData::Row& lhs, const WidgetData::Row& rhs) {
    return !(lhs == rhs);
}

bool operator != (const WidgetData::Row::Item& lhs, const WidgetData::Row::Item& rhs) {
    return !(lhs == rhs);
}
