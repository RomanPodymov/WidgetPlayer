#include <QtTest>
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
    void cleanupTestCase();
};

WidgetPlayerTests::WidgetPlayerTests() {

}

WidgetPlayerTests::~WidgetPlayerTests() {

}

void WidgetPlayerTests::initTestCase() {

}

void WidgetPlayerTests::testWidgetAdditionalData() {
    ForeignExchangeRatesWidgetAdditionalData foreignExchangeRatesWidgetAdditionalData("CZK", "USD");
    WeatherWidgetAdditionalData weatherWidgetAdditionalData("CZK", "USD");
    QVERIFY(foreignExchangeRatesWidgetAdditionalData != weatherWidgetAdditionalData);
}

void WidgetPlayerTests::cleanupTestCase() {

}

QTEST_MAIN(WidgetPlayerTests)

#include "tst_widgetplayertests.moc"
