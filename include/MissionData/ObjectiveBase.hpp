#ifndef OBJECTIVE_BASE_H
#define OBJECTIVE_BASE_H

#include "types.h"

class ObjectiveBase {
public:
    ObjectiveBase(u32 unk1, u32 languageStringId, u8 eventId);
    virtual ~ObjectiveBase() {}

    void *Unk1;
    void *Unk2;
    void *Unk3;
    u8 Unk4;
    u8 Unk5;
    u8 EventId;
    u8 Unk6;
    u32 LanguageStringId;
};
#endif // !OBJECTIVE_BASE_H