include (../WidgetPlayerCommon.pri)

TEMPLATE = lib

CONFIG += staticlib

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
