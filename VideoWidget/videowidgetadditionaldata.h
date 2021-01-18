//
//  videowidgetadditionaldata.h
//  VideoWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#ifndef VIDEOWIDGETADDITIONALDATA_H
#define VIDEOWIDGETADDITIONALDATA_H

#include "widgetdata.h"

class VideoWidgetAdditionalData final: public AdditionalWidgetData {
    Q_OBJECT
    friend class VideoWidget;

public:
    VideoWidgetAdditionalData(QString);
    bool operator == (const AdditionalWidgetData& rhs) const;

private:
    QString videoURL;
};

#endif // VIDEOWIDGETADDITIONALDATA_H
