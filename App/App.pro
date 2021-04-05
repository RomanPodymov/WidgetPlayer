TEMPLATE = app

QT       += core gui widgets network multimediawidgets

CONFIG += c++11

SOURCES += \
    main.cpp

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
