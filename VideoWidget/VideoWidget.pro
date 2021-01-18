TEMPLATE = lib

QT       += core gui widgets multimediawidgets

CONFIG += c++11 staticlib

SOURCES += \
    videowidget.cpp \
    videowidgetadditionaldata.cpp

HEADERS += \
    videowidget.h \
    videowidgetadditionaldata.h

INCLUDEPATH += \
    ../BaseWidget

LIBS += \
    -L../BaseWidget -lBaseWidget
