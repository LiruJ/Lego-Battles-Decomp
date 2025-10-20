#ifndef CONQUEST_DATA_H
#define CONQUEST_DATA_H

#include "types.h"
namespace Battles {
    namespace Save {
        struct ConquestData {
            u32 TotalBricksCollected;
            u16 Unk1;
            u16 HeroesDefeated;
            u16 Unk2;
            u16 Unk3;
            u16 Unk4;
            u16 Unk5;
            u16 SpecialsDefeated;
            u16 AlwaysZero;
            u16 UnitsDestroyed;
            u16 TowersDestroyed;
            u16 BuildingsDestroyed;
            u16 TotalFreePlayMatchesWon;
            u16 TotalGoldRushMatchesWon;
            u16 TotalHeroHuntMatchesWon;
            u16 TotalMultiplayerMatchesWon;
            u16 Total3PlayerMatchesWon;
            u16 MeleeUnitsCreated;
            u16 RangedUnitsCreated;
            u16 MountedUnitsCreated;
            u16 SpecialUnitsCreated;
            u16 TowersBuilt;
            u16 FarmsBuilt;
            u16 PointsHealed;
            u16 Unk6;

            void UpdateMatchStats(u32 gameMode);
            u32 Get115();

            u32 Save();
        } CurrentConquestData;
    } // namespace Save
} // namespace Battles

#endif // !CONQUEST_DATA_H
