#ifndef RETRIEVE_MARKED_UNITS_OBJECTIVE_H
#define RETRIEVE_MARKED_UNITS_OBJECTIVE_H

#include "MissionData/ObjectiveBase.hpp"

class RetrieveMarkedUnitsObjective : public ObjectiveBase {
public:
    RetrieveMarkedUnitsObjective(u8 eventId, u32 languageStringId, u8 unk2);

    void *Unk7;
    void *Unk8; // EventListener
    u8 Unk9;
    u8 Unk10;
    u16 Unk11;

private:
};
#endif // !RETRIEVE_MARKED_UNITS_OBJECTIVE_H