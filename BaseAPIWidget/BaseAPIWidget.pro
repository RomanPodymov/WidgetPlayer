TEMPLATE = lib

QT       += core gui widgets network

CONFIG += c++11 staticlib

SOURCES += \
    baseapiwidget.cpp

HEADERS += \
    baseapiwidget.h

INCLUDEPATH += \
    ../BaseWidget

LIBS += \
    -L../BaseWidget -lBaseWidget
