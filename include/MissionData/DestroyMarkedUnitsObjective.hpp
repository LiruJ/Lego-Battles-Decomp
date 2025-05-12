#ifndef DESTROY_MARKED_UNITS_OBJECTIVE_H
#define DESTROY_MARKED_UNITS_OBJECTIVE_H

#include "MissionData/ObjectiveBase.hpp"

class DestroyMarkedUnitsObjective : public ObjectiveBase {
public:
    DestroyMarkedUnitsObjective(u8 eventId, u32 languageStringId, u8 markerId, u32 unk3);

    u32 Unk1;
    s32 Unk2;
    s32 MarkerId;
    void *Unk3; // EventListener.
};
#endif // !DESTROY_MARKED_UNITS_OBJECTIVE_H