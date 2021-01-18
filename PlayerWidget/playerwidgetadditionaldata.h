//
//  playerwidgetadditionaldata.h
//  PlayerWidget
//
//  Created by Roman Podymov on 17/01/2021.
//  Copyright © 2021 WidgetPlayer. All rights reserved.
//

#ifndef PLAYERWIDGETADDITIONALDATA_H
#define PLAYERWIDGETADDITIONALDATA_H

#include "widgetdata.h"

class PlayerWidgetAdditionalData final: public AdditionalWidgetData {
    Q_OBJECT
    friend class PlayerWidget;

public:
    PlayerWidgetAdditionalData(QString);
    bool operator == (const AdditionalWidgetData& rhs) const;

private:
    QString videoURL;
};

#endif // PLAYERWIDGETADDITIONALDATA_H
