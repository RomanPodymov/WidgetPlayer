//
//  playerwidgetadditionaldata.cpp
//  PlayerWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#include "playerwidgetadditionaldata.h"

bool PlayerWidgetAdditionalData::operator == (const AdditionalWidgetData& rhs) const {
    const PlayerWidgetAdditionalData* playerWidgetAdditionalData = qobject_cast<const PlayerWidgetAdditionalData*>(&rhs);
    if (playerWidgetAdditionalData == nullptr) {
        return false;
    }
    return videoURL == playerWidgetAdditionalData->videoURL;
}

PlayerWidgetAdditionalData::PlayerWidgetAdditionalData(QString videoURL):
    videoURL(videoURL) {

}
