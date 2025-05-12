#include "MissionScripts/Mission01.hpp"

#include "Battles/ScriptingMacros/Timer.hpp"

#include "UI/Dialog.hpp"
#include "UI/Effects.hpp"

#include "MissionData/DestroyMarkedUnitsObjective.hpp"
#include "MissionData/MissionObjectives.hpp"
#include "MissionData/RetrieveMarkedUnitsObjective.hpp"
#include "MissionData/TriggerAreaObjective.hpp"

#include "Team/TeamManager.hpp"

#include "global.h"

const u8 EVENT_ID_START_TIMER_ELAPSED       = 0x84;
const u8 EVENT_ID_BARRACKS_DESTROYED        = 0x85;
const u8 EVENT_ID_CRIMINAL_LEADER_RETRIEVED = 0x86;
const u8 EVENT_ID_CRIMINAL_LEADER_DESTROYED = 0x88;
const u8 EVENT_ID_PLAYER_BASE_DESTROYED     = 0x89;

const u32 LANGUAGE_ID_BUST_OUT_CRIMINAL_LEADER = 0xa77;
const u32 LANGUAGE_ID_GET_CRIMINAL_LEADER_BASE = 0xa7a;

// Alien mission "Criminal Minds".

THUMB void Mission01::OnEvent(CampaignMissionBase *mission, s32 eventId) {
    OnMissionEvent(mission, eventId);
}

THUMB void Mission01::OnMissionEvent(CampaignMissionBase *mission, s32 eventId) {
    MissionObjectives *objectives = &missionObjectives;
    ObjectiveBase *objective;

    if (eventId < EVENT_ID_START_TIMER_ELAPSED) {
        if ((eventId < 4) && (eventId > -1)) {
            if (eventId == 0) {
                SetTeamStartingBricks(0, 1000);
                SetTeamFriendly(1, 1);
                SetTeamEnemy(1, 0);
                SetTeamNeutral(0, 2);
                SetTeamNeutral(2, 0);
            } else if (eventId == 1) {
                u32 t = 0x14;

                // Language string is "Bust out the Space Criminal Leader".
                // Marker ID 9 is for the barracks.
                objective = new DestroyMarkedUnitsObjective(EVENT_ID_BARRACKS_DESTROYED, LANGUAGE_ID_BUST_OUT_CRIMINAL_LEADER,
                                                            9, 0x14);
                objectives->AddObjective(objective, 0, t);

                objectives = &missionObjectives;
                t          = 0x14;

                // No language string.
                // Marker ID 12 is for the player's base.
                objective = new DestroyMarkedUnitsObjective(EVENT_ID_PLAYER_BASE_DESTROYED, 0, 12, 0x14);
                objectives->AddObjective(objective, 1, t);

                DoYetAnotherMarkerThing(10, 2);
                DoSomethingWithMarker(9);
                Battles::ScriptingMacros::CurrentTimer.AddNewTimeNode(EVENT_ID_START_TIMER_ELAPSED, 2000, 0, 0, 0);
            } else if (eventId == 3) {
                u32 t = 4;

                // Language string is "Get the Space Criminal Leader back to Base".
                // Marker ID 11 is for the space criminal leader.
                objective = new RetrieveMarkedUnitsObjective(EVENT_ID_CRIMINAL_LEADER_RETRIEVED,
                                                             LANGUAGE_ID_GET_CRIMINAL_LEADER_BASE, 11);
                objectives->AddObjective(objective, 0, t);

                objectives = &missionObjectives;

                // Language string is "Get the Space Criminal Leader back to Base".
                // Trigger ID 4 is for the trigger area over the player's base.
                // The trigger contains the ID 11, referring to the marker ID.
                objective = new TriggerAreaObjective(0x87, 0xa7a, 4);
                objectives->AddObjective(objective, 1, t);

                objectives = &missionObjectives;
                u32 u      = 0x14;

                // No language string.
                // Marker ID 11 is for the space criminal leader.
                objective = new DestroyMarkedUnitsObjective(EVENT_ID_CRIMINAL_LEADER_DESTROYED, 0, 11, 0x14);
                t         = 1;
                objectives->AddObjective(objective, 1, u);

                DoSomethingWithMarker(12);
                DoSomethingWithMarker(11);

                // There is no marker with the ID of 10 on the map, but interestingly the space criminal leader spawns on event
                // ID 2.
                DoAnotherMarkerThing(10, 2, t, u);

                Battles::Vector2s16 vector = Battles::Vector2s16(0, 0);
                // "Get the Space Criminal Leader back to Base"
                OpenMissionDialog(LANGUAGE_ID_GET_CRIMINAL_LEADER_BASE, &vector, 4000, u);
            }
        } else if (eventId >= EVENT_ID_PLAYER_BASE_DESTROYED) {
            if (eventId == EVENT_ID_START_TIMER_ELAPSED) {
                Battles::Vector2s16 vector = Battles::Vector2s16(0, 0);
                // "Bust out the Space Criminal Leader"
                OpenMissionDialog(0xa7a, &vector, 4000, 0);
            } else if (eventId == EVENT_ID_BARRACKS_DESTROYED) {
                mission->Unk8();
            } else if (eventId == EVENT_ID_CRIMINAL_LEADER_RETRIEVED) {
                // Create arrows over the criminal space leader and the base.
                MakeArrowForMarker(12);
                MakeArrowForMarker(11);
                FUN_02049ad4_Unk();
            } else if (eventId == EVENT_ID_CRIMINAL_LEADER_DESTROYED) {
                FailMission();
            } else if (eventId == EVENT_ID_PLAYER_BASE_DESTROYED) {
                FailMission();
            }
        }
    }

    mission->InvokeMapEventWithId(eventId);
}
