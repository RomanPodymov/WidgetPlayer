//
//  videowidget.h
//  VideoWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "basewidget.h"
#include <QPointer>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class VideoWidget final: public BaseWidget {
    Q_OBJECT

public:
    VideoWidget(const QApplication*, WidgetData::Row, WidgetData::Row::Item, QWidget *parent = nullptr);
    CREATE_WIDGET(VideoWidget)
    void setupSize(QSize rootScreenSize);

private:
    const QPointer<QVideoWidget> videoWidget;
    const QPointer<QMediaPlayer> mediaPlayer;
    const QPointer<QMediaPlaylist> mediaPlaylist;
};

#endif // VIDEOWIDGET_H
