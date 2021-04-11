//
//  basewidget.h
//  BaseWidget
//
//  Created by Roman Podymov on 07/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include "widgetdata.h"
#include "translatorwidget.h"
#include <QApplication>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QTranslator>

#define CREATE_WIDGET(CLASS_NAME) \
    static CLASS_NAME* create(const QApplication* application, WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent = nullptr) { \
        return new CLASS_NAME(application, row, item, parent); \
    }

class BaseWidget : public TranslatorWidget {
    Q_OBJECT

public:
    BaseWidget(const QApplication*, WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);
    virtual void setupSize(QSize rootScreenSize);
    static void showAlert(QString);

public slots:
    void onRootScreenSizeChanged(QSize);

protected:
    void loadBackgroundImage();

private slots:
    void onBackgroundImageReply(QNetworkReply*);

public:
    QTranslator translator;

protected:
    const QSharedPointer<QNetworkAccessManager> networkAccessManager;
    const WidgetData::Row row;
    const WidgetData::Row::Item item;
};

using CreateWidgetFunction = std::function<BaseWidget*(const QApplication*, WidgetData::Row, WidgetData::Row::Item, QWidget*)>;

#endif // BASEWIDGET_H
