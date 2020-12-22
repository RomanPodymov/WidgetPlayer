TEMPLATE = lib

QT       += core gui widgets network

CONFIG += c++11 staticlib

SOURCES += \
    weatherwidget.cpp \
    weatherwidgetadditionaldata.cpp

HEADERS += \
    weatherwidget.h \
    weatherwidgetadditionaldata.h

INCLUDEPATH += \
    ../BaseWidget
