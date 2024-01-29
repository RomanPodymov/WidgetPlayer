//
//  widgetplayertests.cpp
//  WidgetPlayerTests
//
//  Created by Roman Podymov on 27/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include <QtTest>
#include <QSignalSpy>
#include "mainwidget.h"
#include "foreignexchangerateswidgetadditionaldata.h"
#include "weatherwidgetadditionaldata.h"

class WidgetPlayerTests: public QObject {
    Q_OBJECT

public:
    WidgetPlayerTests();
    ~WidgetPlayerTests();

private slots:
    void initTestCase();
    void testWidgetAdditionalData();
    void testMainWidgetNewDataReceived();
    void cleanupTestCase();
};

WidgetPlayerTests::WidgetPlayerTests() {
    Q_INIT_RESOURCE(mainwidgetresources);
    Q_INIT_RESOURCE(weatherwidgetresources);
}

WidgetPlayerTests::~WidgetPlayerTests() {

}

void WidgetPlayerTests::initTestCase() {

}

void WidgetPlayerTests::testWidgetAdditionalData() {
    ForeignExchangeRatesWidgetAdditionalData foreignExchangeRatesWidgetAdditionalData("", "CZK", "USD");
    WeatherWidgetAdditionalData weatherWidgetAdditionalData("CZK", "USD");
    QVERIFY(foreignExchangeRatesWidgetAdditionalData != weatherWidgetAdditionalData);
}

void WidgetPlayerTests::testMainWidgetNewDataReceived() {
    MainWidget mainWidget(nullptr, nullptr);
    QSignalSpy spy(&mainWidget, SIGNAL(newDataReceived()));
    mainWidget.update();
    QCOMPARE(spy.wait(5000), true);
}

void WidgetPlayerTests::cleanupTestCase() {

}

QTEST_MAIN(WidgetPlayerTests)

#include "widgetplayertests.moc"
