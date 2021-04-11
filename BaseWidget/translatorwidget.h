//
//  translatorwidget.h
//  BaseWidget
//
//  Created by Roman Podymov on 11/04/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#ifndef TRANSLATORWIDGET_H
#define TRANSLATORWIDGET_H

#include "widgetdata.h"
#include <QApplication>
#include <QWidget>
#include <QTranslator>

class TranslatorWidget : public QWidget {
    Q_OBJECT

public:
    TranslatorWidget(QWidget *parent = nullptr);
    void loadTranslations(const QApplication*, QString);

protected:
    QTranslator translator;
};

#endif // TRANSLATORWIDGET_H
