TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    BaseWidget \
    BaseAPIWidget \
    ForeignExchangeRatesWidget \
    VideoWidget \
    WeatherWidget \
    App \
    WidgetPlayerTests

App.depends = ForeignExchangeRatesWidget VideoWidget WeatherWidget
BaseAPIWidget.depends = BaseWidget
ForeignExchangeRatesWidget.depends = BaseAPIWidget
VideoWidget.depends = BaseWidget
WeatherWidget.depends = BaseAPIWidget
