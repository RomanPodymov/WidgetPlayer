include (../WidgetPlayerCommon.pri)

TEMPLATE = lib

CONFIG += staticlib

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
    ../BaseWidget \
    ../BaseAPIWidget

LIBS += \
    -L../BaseWidget -lBaseWidget \
    -L../BaseAPIWidget -lBaseAPIWidget

RESOURCES += \
    weatherwidgetresources.qrc
