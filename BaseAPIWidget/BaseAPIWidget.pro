include (../WidgetPlayerCommon.pri)

TEMPLATE = lib

CONFIG += staticlib

SOURCES += \
    baseapiwidget.cpp

HEADERS += \
    baseapiwidget.h

INCLUDEPATH += \
    ../BaseWidget

LIBS += \
    -L../BaseWidget -lBaseWidget
