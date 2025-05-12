#include "MissionData/ObjectiveBase.hpp"

ObjectiveBase::ObjectiveBase(u32 unk1, u32 languageStringId, u8 eventId) {
    EventId          = eventId;
    LanguageStringId = languageStringId;
}
