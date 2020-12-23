//
//  mainwidget.h
//  App
//
//  Created by Roman Podymov on 06/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "widgetdata.h"
#include <QApplication>
#include <QPointer>
#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QResizeEvent>

enum WidgetState { unknown, loading, content, error };

class MainWidget: public QWidget {
    Q_OBJECT

public:
    MainWidget(QApplication& application, QWidget *parent = nullptr);
    ~MainWidget();

signals:
    void rootScreenSizeChanged(QSize);

protected:
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);

private:
    void switchWidgetState(WidgetState);
    static QJsonObject readLocalConfigurationJSON();
    void update(WidgetState, bool);
    void update();
    WidgetData parseRensonse(QString);
    void updateUI(WidgetData);
    static void clearLayout(QLayout* layout);

private:
    const QPointer<QLabel> stateLabel;

private:
    QApplication& application;
    const QSharedPointer<QNetworkAccessManager> networkAccessManager;
    WidgetState widgetState;
    const QJsonObject localConfiguration;
    const QString widgetsConfigurationURL;
    const QString weatherAPIkey;
    WidgetData widgetData;
    const quint8 maxRequestErrorCount;
    quint8 requestErrorCount;
};
#endif // MAINWIDGET_H
