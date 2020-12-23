TEMPLATE = lib

QT       += core gui widgets network

CONFIG += c++11 staticlib

SOURCES += \
    weatherwidget.cpp \
    weatherwidgetadditionaldata.cpp

HEADERS += \
    weatherwidget.h \
    weatherwidgetadditionaldata.h

TRANSLATIONS += \
    Translations/Translations_WeatherWidget_en.ts \
    Translations/Translations_WeatherWidget_cs.ts

INCLUDEPATH += \
    ../BaseWidget

RESOURCES += \
    weatherwidgetresources.qrc
