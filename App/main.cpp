//
//  main.cpp
//  App
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
    if (!translator.load(":/translations/strings")) {
        BaseWidget::showAlert("Failed to load /translations/strings");
        exit(EXIT_FAILURE);
    }
    a.installTranslator(&translator);
    MainWidget w(&a);
    w.show();
    return a.exec();
}
