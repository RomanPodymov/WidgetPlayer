TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = \
    BaseWidget \
    BaseAPIWidget \
    ForeignExchangeRatesWidget \
    WeatherWidget \
    App

App.depends = ForeignExchangeRatesWidget WeatherWidget
BaseAPIWidget.depends = BaseWidget
ForeignExchangeRatesWidget.depends = BaseAPIWidget
WeatherWidget.depends = BaseAPIWidget
