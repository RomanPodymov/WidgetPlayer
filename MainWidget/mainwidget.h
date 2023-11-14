//
//  mainwidget.h
//  MainWidget
//
//  Created by Roman Podymov on 06/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "basewidget.h"
#include "translatorwidget.h"
#include "widgetdata.h"
#include <QApplication>
#include <QPointer>
#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QResizeEvent>

enum WidgetState { unknown, loading, content, error };

class MainWidget final: public TranslatorWidget {
    Q_OBJECT

public:
    MainWidget(const QApplication*, QWidget *parent = nullptr);
    void update();

signals:
    void rootScreenSizeChanged(QSize);
    void newDataReceived();

protected:
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void switchWidgetState(WidgetState);
    static QJsonObject readLocalConfigurationJSON();
    void update(WidgetState, bool);
    WidgetData parseRensonse(QString);
    void updateUI(WidgetData);
    static QPointer<BaseWidget> createRowWidget(const QApplication*, const WidgetData::Row& row, const WidgetData::Row::Item& item);
    static void clearLayout(QLayout* layout);

private:
    const QPointer<const QApplication> application;
    const QPointer<QLabel> stateLabel;

private:
    const QSharedPointer<QNetworkAccessManager> networkAccessManager;
    WidgetState widgetState;
    const QJsonObject localConfiguration;
    const QString widgetsConfigurationURL;
    const QString weatherAPIkey;
    const QString exchangeAPIkey;
    WidgetData widgetData;
    const quint8 maxRequestErrorCount;
    quint8 requestErrorCount;
};
#endif // MAINWIDGET_H
