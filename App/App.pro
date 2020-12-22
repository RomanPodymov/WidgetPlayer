TEMPLATE = app

QT       += core gui widgets network

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    mainwidget.h

TRANSLATIONS += \
    Translations/Translations_WidgetPlayer_en.ts \
    Translations/Translations_WidgetPlayer_cs.ts

INCLUDEPATH += \
    ../BaseWidget \
    ../WeatherWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../WeatherWidget -lWeatherWidget

RESOURCES += \
    resources.qrc

DISTFILES += \
    Configurations/local_configuration.json
