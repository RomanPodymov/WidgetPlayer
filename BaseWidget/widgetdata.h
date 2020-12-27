//
//  widgetdata.h
//  BaseWidget
//
//  Created by Roman Podymov on 07/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef WIDGETDATA_H
#define WIDGETDATA_H

#include <QList>
#include <QString>
#include <QSharedPointer>
#include <QJsonObject>
#include <QColor>

class AdditionalWidgetData: public QObject {
    Q_OBJECT

public:
    virtual bool operator == (const AdditionalWidgetData& rhs) const = 0;
    bool operator != (const AdditionalWidgetData& rhs) const;
};

struct WidgetData {
    enum WidgetType { unknown, foreignexchangerates, weather };

    enum WidgetSizeValueType { absolute, percentage };

    union WidgetSizeValue {
        struct Absolute {
            double value;
        } absolute;

        struct Percentage {
            double value;
        } percentage;
    };

    struct Row {
        struct Item {
            Item(QString, QString, QString, QString);

            WidgetType widgetType;
            WidgetSizeValueType widthValueType;
            WidgetSizeValue width;
            QUrl backgroundImage;
            QColor textColor;
            QSharedPointer<AdditionalWidgetData> additionalWidgetData;
        };

        Row(QString);

        QList<Item> items;
        WidgetSizeValueType heightValueType;
        WidgetSizeValue height;
    };

    WidgetData();

private:
    static WidgetType widgetTypeFromString(QString);
    static WidgetSizeValueType widgetSizeValueType(QString);
    static WidgetSizeValue widgetSizeValue(QString);

public:
    int updateIntervalInSeconds;
    QList<Row> rows;
};

bool operator == (const WidgetData& lhs, const WidgetData& rhs);
bool operator == (const WidgetData::Row& lhs, const WidgetData::Row& rhs);
bool operator == (const WidgetData::Row::Item& lhs, const WidgetData::Row::Item& rhs);

bool operator != (const WidgetData& lhs, const WidgetData& rhs);
bool operator != (const WidgetData::Row& lhs, const WidgetData::Row& rhs);
bool operator != (const WidgetData::Row::Item& lhs, const WidgetData::Row::Item& rhs);

#endif // WIDGETDATA_H
