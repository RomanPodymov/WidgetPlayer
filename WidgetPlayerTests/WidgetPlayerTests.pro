QT += testlib

CONFIG += qt testcase

TEMPLATE = app

SOURCES += tst_widgetplayertests.cpp

INCLUDEPATH += \
    ../BaseWidget \
    ../BaseAPIWidget \
    ../ForeignExchangeRatesWidget \
    ../WeatherWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../BaseAPIWidget -lBaseAPIWidget \
    -L../ForeignExchangeRatesWidget -lForeignExchangeRatesWidget \
    -L../WeatherWidget -lWeatherWidget
