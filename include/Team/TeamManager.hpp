#ifndef TEAM_MANAGER_H
#define TEAM_MANAGER_H

#include "types.h"

void SetTeamStartingBricks(u32 teamIndex, u32 bricks);
void SetTeamFriendly(u32 teamIndex1, u32 teamIndex2);
void SetTeamEnemy(u32 teamIndex1, u32 teamIndex2);
void SetTeamNeutral(u32 teamIndex1, u32 teamIndex2);

void DoSomethingWithMarker(u8 markerId);
void DoAnotherMarkerThing(u32 markerId, u32 eventId, u32 unk1, u32 unk2);
void DoYetAnotherMarkerThing(u32 markerId, u8 eventId);

s8 GetInvalidFactionIndex();
#endif // !TEAM_MANAGER_H