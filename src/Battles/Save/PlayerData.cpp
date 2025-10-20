#include "Battles/Save/PlayerData.hpp"
#include "Battles/Save/BitStream.hpp"
#include "Battles/Save/ConquestData.hpp"

void Battles::Save::PlayerData::Initialise() {

    CurrentPlayerData.SlotIndex = InvalidSlotIndexValue;
    CurrentPlayerData.IsLoaded  = false;
}

void Battles::Save::PlayerData::InitialiseStats() {
    CurrentPlayerData.Unk6        = true;
    CurrentPlayerData.BlueStuds   = 0;
    CurrentPlayerData.PlayTime    = 0;
    CurrentPlayerData.SFXVolume   = 0x7F;
    CurrentPlayerData.MusicVolume = 0x32;
    CurrentPlayerData.Unk7        = true;
    CurrentPlayerData.Unk5        = 0;
    CurrentPlayerData.IsLoaded    = true;
}

u32 Battles::Save::PlayerData::Save(s32 param_1, u32 param_2, u32 param_3, u32 *dest, s32 param_5) {

    u32 uVar5 = (u32) param_1;
    if (param_1 != 0) {
        dest = 0;

        CurrentPlayerData.Unk5 = 0;
        CurrentPlayerData.UnlockedMissions.FUN_020ee9bc(91);
    }

    ResetBitStream();

    if (uVar5 == 3) {
        uVar5 = 0;
    }
    if (uVar5 != 0) {
        return uVar5;
    }

    u8 byteWriteResult = WriteBytes((u8 *) CurrentPlayerData.Name, 11);
    if (byteWriteResult != 0) {
        return (u32) byteWriteResult;
    }

    u32 unkPtr = 0x02148aa8;

    u32 truncatedValue = TruncValue(CurrentPlayerData.Unk6, 1);
    u32 bitWriteResult = WriteBits(&truncatedValue, 1);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.BlueStuds, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.PlayTime, 32);
    bitWriteResult = WriteBits(&truncatedValue, 32);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.SFXVolume, 7);
    bitWriteResult = WriteBits(&truncatedValue, 7);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.MusicVolume, 7);
    bitWriteResult = WriteBits(&truncatedValue, 7);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.Unk7, 1);
    bitWriteResult = WriteBits(&truncatedValue, 1);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue(CurrentPlayerData.LanguageIndex, 3);
    bitWriteResult = WriteBits(&truncatedValue, 3);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    // Save the player's army.
    u32 currentArmyTroop = 0;
    do {
        truncatedValue = TruncValue((u32) CurrentPlayerData.ArmyTroops[currentArmyTroop], 16);
        bitWriteResult = WriteBits(&truncatedValue, 16);
        if (bitWriteResult != 0) {
            return bitWriteResult;
        }
        currentArmyTroop++;
    } while (currentArmyTroop < 4);
    currentArmyTroop = 0;
    do {
        truncatedValue = TruncValue((u32) CurrentPlayerData.ArmySpecials[currentArmyTroop], 16);
        bitWriteResult = WriteBits(&truncatedValue, 16);
        if (bitWriteResult != 0) {
            return bitWriteResult;
        }
        currentArmyTroop++;
    } while (currentArmyTroop < 5);

    truncatedValue = TruncValue(CurrentPlayerData.Unk9, 1);
    bitWriteResult = WriteBits(&truncatedValue, 1);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    // Missing a save here for something OOB.

    if (CurrentPlayerData.UnlockedMissions.BitCount != 0) {
        u32 currentMissionIndex = 0;
        do {
            bool missionPassed = CurrentPlayerData.UnlockedMissions.GetValueAt(currentMissionIndex);

            truncatedValue = TruncValue((u32) missionPassed, 1);
            bitWriteResult = WriteBits(&truncatedValue, 1);
            if (bitWriteResult != 0) {
                return bitWriteResult;
            }

            currentMissionIndex++;
        } while (currentMissionIndex < CurrentPlayerData.UnlockedMissions.BitCount);
    }

    bitWriteResult = CurrentConquestData.Save();
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    bitWriteResult = 0; // SaveUnlockableManager
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    bitWriteResult = WritePaddingToNextByte();
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    return bitWriteResult;
}

u32 Battles::Save::PlayerData::GetSaveSlotMaxCount() {
    return 2;
}
