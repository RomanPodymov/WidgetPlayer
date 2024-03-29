//
//  videowidget.cpp
//  VideoWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#include "videowidget.h"
#include "videowidgetadditionaldata.h"

VideoWidget::VideoWidget(const QApplication* application, WidgetData::Row row, WidgetData::Row::Item item, QWidget *parent): BaseWidget(application, row, item, parent),
    videoWidget(new QVideoWidget(this)),
    mediaPlayer(new QMediaPlayer(this)) {
    const auto& videoWidgetAdditionalData = qSharedPointerCast<VideoWidgetAdditionalData>(item.additionalWidgetData);
    mediaPlayer->setSource(QUrl(videoWidgetAdditionalData->videoURL));
    mediaPlayer->setVideoOutput(videoWidget);
    mediaPlayer->play();
}

void VideoWidget::setupSize(QSize rootScreenSize) {
    BaseWidget::setupSize(rootScreenSize);
    videoWidget->setGeometry(geometry());
}
