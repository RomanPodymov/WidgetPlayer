TEMPLATE = app

QT       += core gui widgets network

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    mainwidget.h

TRANSLATIONS += \
    Translations/Translations_App_en.ts \
    Translations/Translations_App_cs.ts

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

RESOURCES += \
    resources.qrc

DISTFILES += \
    Configurations/local_configuration.json
