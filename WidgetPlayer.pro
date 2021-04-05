TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    BaseWidget \
    BaseAPIWidget \
    ForeignExchangeRatesWidget \
    MainWidget \
    VideoWidget \
    WeatherWidget \
    App \
    WidgetPlayerTests

App.depends = MainWidget
BaseAPIWidget.depends = BaseWidget
ForeignExchangeRatesWidget.depends = BaseAPIWidget
MainWidget.depends = ForeignExchangeRatesWidget VideoWidget WeatherWidget
VideoWidget.depends = BaseWidget
WeatherWidget.depends = BaseAPIWidget
