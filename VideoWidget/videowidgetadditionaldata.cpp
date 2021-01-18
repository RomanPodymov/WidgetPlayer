//
//  videowidgetadditionaldata.cpp
//  VideoWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#include "videowidgetadditionaldata.h"

bool VideoWidgetAdditionalData::operator == (const AdditionalWidgetData& rhs) const {
    const VideoWidgetAdditionalData* videoWidgetAdditionalData = qobject_cast<const VideoWidgetAdditionalData*>(&rhs);
    if (videoWidgetAdditionalData == nullptr) {
        return false;
    }
    return videoURL == videoWidgetAdditionalData->videoURL;
}

VideoWidgetAdditionalData::VideoWidgetAdditionalData(QString videoURL):
    videoURL(videoURL) {

}
