//
//  playerwidget.h
//  PlayerWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#ifndef PLAYERWIDGET_H
#define PLAYERWIDGET_H

#include "basewidget.h"
#include <QPointer>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class PlayerWidget final: public BaseWidget {
    Q_OBJECT

public:
    PlayerWidget(WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);
    void setupSize(QSize rootScreenSize);

private:
    const QPointer<QVideoWidget> videoWidget;
    const QPointer<QMediaPlayer> mediaPlayer;
    const QPointer<QMediaPlaylist> mediaPlaylist;
};

#endif // PLAYERWIDGET_H
