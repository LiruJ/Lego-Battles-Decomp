#include "MissionData/RetrieveMarkedUnitsObjective.hpp"

// Technically this actually calls the ListItem base constructor, not the ObjectiveBase.
RetrieveMarkedUnitsObjective::RetrieveMarkedUnitsObjective(u8 eventId, u32 languageStringId, u8 unk2) :
    ObjectiveBase(10, languageStringId, eventId) {
    Unk7 = (void *) 0;
    Unk8 = (void *) 0;

    Unk9  = unk2;
    Unk10 = unk2;
}
