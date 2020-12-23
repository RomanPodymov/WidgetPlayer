//
//  main.cpp
//  WidgetPlayer
//
//  Created by Roman Podymov on 06/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "mainwidget.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(weatherwidgetresources);
    QApplication a(argc, argv);
    QTranslator translator;
    translator.load(":/translations/strings");
    a.installTranslator(&translator);
    MainWidget w(a);
    w.show();
    return a.exec();
}
