//
//  translatorwidget.cpp
//  BaseWidget
//
//  Created by Roman Podymov on 11/04/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#include "translatorwidget.h"
#include "basewidget.h"

TranslatorWidget::TranslatorWidget(QWidget *parent): QWidget(parent) {

}

void TranslatorWidget::loadTranslations(const QApplication* application, QString fileName) {
    if (!translator.load(fileName)) {
        BaseWidget::showAlert("Failed to load " + fileName);
        exit(EXIT_FAILURE);
    }
    application->installTranslator(&translator);
}
