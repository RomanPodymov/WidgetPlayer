include (../WidgetPlayerCommon.pri)

TEMPLATE = lib

CONFIG += staticlib

SOURCES += \
    foreignexchangerateswidget.cpp \
    foreignexchangerateswidgetadditionaldata.cpp

HEADERS += \
    foreignexchangerateswidget.h \
    foreignexchangerateswidgetadditionaldata.h

INCLUDEPATH += \
    ../BaseWidget \
    ../BaseAPIWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../BaseAPIWidget -lBaseAPIWidget
