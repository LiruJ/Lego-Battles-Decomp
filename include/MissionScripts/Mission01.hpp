#ifndef MISSION01_H
#define MISSION01_H

#include "types.h"

#include "Missions/CampaignMissionBase.hpp"

class Mission01 {
public:
    void OnEvent(CampaignMissionBase *mission, s32 eventId);
    void OnMissionEvent(CampaignMissionBase *mission, s32 eventId);

private:
};
#endif // !MISSION01_H