include (../WidgetPlayerCommon.pri)

TEMPLATE = app

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
