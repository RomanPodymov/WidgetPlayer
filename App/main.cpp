//
//  main.cpp
//  App
//
//  Created by Roman Podymov on 06/12/2020.
//  Copyright © 2020 WidgetPlayer. All rights reserved.
//

#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    Q_INIT_RESOURCE(weatherwidgetresources);
    Q_INIT_RESOURCE(mainwidgetresources);
    QApplication a(argc, argv);
    MainWidget w(&a);
    w.show();
    return a.exec();
}
