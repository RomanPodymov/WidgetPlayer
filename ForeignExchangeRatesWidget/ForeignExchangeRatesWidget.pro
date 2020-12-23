TEMPLATE = lib

QT       += core gui widgets network

CONFIG += c++11 staticlib

SOURCES += \
    foreignexchangerateswidget.cpp \
    foreignexchangerateswidgetadditionaldata.cpp

HEADERS += \
    foreignexchangerateswidget.h \
    foreignexchangerateswidgetadditionaldata.h

INCLUDEPATH += \
    ../BaseWidget
