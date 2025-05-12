#ifndef MISSION_OBJECTIVES_H
#define MISSION_OBJECTIVES_H

#include "MissionData/ObjectiveBase.hpp"

class MissionObjectives {
public:
    void *Unk1;
    void *List1;
    void *Array1;
    void *List2;

    MissionObjectives();

    void AddObjective(ObjectiveBase *objective, s32 index, u32 someIndex);

    virtual ~MissionObjectives() {}
} missionObjectives;
#endif // !MISSION_OBJECTIVES_H