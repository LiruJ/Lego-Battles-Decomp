#ifndef MISSION01_H
#define MISSION01_H

#include "global.h"
#include "types.h"

#include "Missions/CampaignMissionBase.hpp"

class Mission01 {
public:
    THUMB void OnEvent(CampaignMissionBase *mission, s32 eventId);
    THUMB void OnMissionEvent(CampaignMissionBase *mission, s32 eventId);

private:
};
#endif // !MISSION01_H