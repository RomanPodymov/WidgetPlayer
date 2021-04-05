QT += testlib widgets network multimediawidgets

CONFIG += qt testcase

TEMPLATE = app

SOURCES += widgetplayertests.cpp

INCLUDEPATH += \
    ../BaseWidget \
    ../BaseAPIWidget \
    ../ForeignExchangeRatesWidget \
    ../MainWidget \
    ../VideoWidget \
    ../WeatherWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../BaseAPIWidget -lBaseAPIWidget \
    -L../ForeignExchangeRatesWidget -lForeignExchangeRatesWidget \
    -L../MainWidget -lMainWidget \
    -L../VideoWidget -lVideoWidget \
    -L../WeatherWidget -lWeatherWidget
