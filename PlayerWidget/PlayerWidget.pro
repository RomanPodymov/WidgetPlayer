TEMPLATE = lib

QT       += core gui widgets multimediawidgets

CONFIG += c++11 staticlib

SOURCES += \
    playerwidget.cpp \
    playerwidgetadditionaldata.cpp

HEADERS += \
    playerwidget.h \
    playerwidgetadditionaldata.h

INCLUDEPATH += \
    ../BaseWidget

LIBS += \
    -L../BaseWidget -lBaseWidget
