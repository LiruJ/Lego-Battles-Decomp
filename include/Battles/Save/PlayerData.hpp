#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H

#include "Collections/BitArray.hpp"
#include "types.h"

namespace Battles {
    namespace Save {
        struct PlayerData {
            static const u8 InvalidSlotIndexValue = 0xFF;

            u8 SlotIndex;
            bool IsLoaded;
            u16 Unk1;

            void *Unk2;
            void *Unk3;
            void *Unk4;

            BitArray UnlockedMissions;
            u32 Unk5;
            bool Unk6;

            char Name[11];
            u8 SFXVolume;
            u8 MusicVolume;
            bool Unk7;
            u8 Unk8;

            u32 LanguageIndex;
            u16 ArmyTroops[4];
            u16 ArmySpecials[5];

            bool Unk9;
            u8 Unk10;
            u16 BlueStuds;

            u16 Unk11;
            u32 PlayTime;

            static void Initialise();
            static void InitialiseStats();

            u32 Save(s32 param_1, u32 param_2, u32 param_3, u32 *dest, s32 param_5);

            u32 GetSaveSlotMaxCount();
        } CurrentPlayerData;
    } // namespace Save
} // namespace Battles

#endif // !PLAYER_DATA_H
