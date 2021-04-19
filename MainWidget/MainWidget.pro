include (../WidgetPlayerCommon.pri)

TEMPLATE = lib

CONFIG += staticlib

SOURCES += \
    mainwidget.cpp

HEADERS += \
    mainwidget.h

TRANSLATIONS += \
    Translations/Translations_MainWidget_en.ts \
    Translations/Translations_MainWidget_cs.ts

INCLUDEPATH += \
    ../BaseWidget \
    ../BaseAPIWidget \
    ../ForeignExchangeRatesWidget \
    ../VideoWidget \
    ../WeatherWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../BaseAPIWidget -lBaseAPIWidget \
    -L../ForeignExchangeRatesWidget -lForeignExchangeRatesWidget \
    -L../VideoWidget -lVideoWidget \
    -L../WeatherWidget -lWeatherWidget

RESOURCES += \
    mainwidgetresources.qrc

DISTFILES += \
    Configurations/local_configuration.json
