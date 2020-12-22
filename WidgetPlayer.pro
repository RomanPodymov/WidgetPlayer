TEMPLATE = subdirs

CONFIG += ordered

SUBDIRS = BaseWidget \
    WeatherWidget \
    App

App.depends = WeatherWidget
