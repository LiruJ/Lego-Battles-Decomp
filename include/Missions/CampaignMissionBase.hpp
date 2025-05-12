#ifndef CAMPAIGN_MISSION_BASE_H
#define CAMPAIGN_MISSION_BASE_H

#include "types.h"

void FailMission() {}

class CampaignMissionBase {
public:
    void InvokeMapEventWithId(s32 eventId);

    virtual void Unk1() {}
    virtual void Unk2() {}
    virtual void Unk3() {}
    virtual void Unk4() {}
    virtual void Unk5() {}
    virtual void Unk6() {}
    virtual void Unk7() {}
    virtual void Unk8() {}
};
#endif // !CAMPAIGN_MISSION_BASE_H