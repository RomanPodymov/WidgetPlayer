//
//  playerwidget.cpp
//  PlayerWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#include "playerwidget.h"
#include "playerwidgetadditionaldata.h"

PlayerWidget::PlayerWidget(WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): BaseWidget(row, item, parent),
    videoWidget(new QVideoWidget(this)),
    mediaPlayer(new QMediaPlayer()),
    mediaPlaylist(new QMediaPlaylist()) {
    const auto& playerWidgetAdditionalData = qSharedPointerCast<PlayerWidgetAdditionalData>(item.additionalWidgetData);
    mediaPlaylist->addMedia(QUrl(playerWidgetAdditionalData->videoURL));
    mediaPlayer->setPlaylist(mediaPlaylist);
    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->play();
}

void PlayerWidget::setupSize(QSize rootScreenSize) {
    BaseWidget::setupSize(rootScreenSize);
    videoWidget->setGeometry(geometry());
}
