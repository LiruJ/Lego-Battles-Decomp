#include "Battles/Save/ConquestData.hpp"
#include "Battles/Save/BitStream.hpp"

void Battles::Save::ConquestData::UpdateMatchStats(u32 gameMode) {

    u32 maximumWins = 0x0000FFFFU;

    switch (gameMode) {
        case 0: {
            if (CurrentConquestData.TotalFreePlayMatchesWon < maximumWins) {
                CurrentConquestData.TotalFreePlayMatchesWon++;
            }
            break;
        }
        case 1: {
            if (CurrentConquestData.TotalFreePlayMatchesWon < maximumWins) {
                CurrentConquestData.TotalFreePlayMatchesWon++;
            }
            break;
        }
        case 2: {
            if (CurrentConquestData.TotalHeroHuntMatchesWon < maximumWins) {
                CurrentConquestData.TotalHeroHuntMatchesWon++;
            }
            if (CurrentConquestData.TotalFreePlayMatchesWon < maximumWins) {
                CurrentConquestData.TotalFreePlayMatchesWon++;
            }
            break;
        }
        case 3: {
            if (CurrentConquestData.TotalGoldRushMatchesWon < maximumWins) {
                CurrentConquestData.TotalGoldRushMatchesWon++;
            }
            if (CurrentConquestData.TotalFreePlayMatchesWon < maximumWins) {
                CurrentConquestData.TotalFreePlayMatchesWon++;
            }
            break;
        }
        case 5: {
            if (CurrentConquestData.TotalMultiplayerMatchesWon < maximumWins) {
                CurrentConquestData.TotalMultiplayerMatchesWon++;
            }
            // TODO: Work out where it's getting player count from.
            if ((2 < *(u8 *) (0x020A80C8 + 0x12)) && CurrentConquestData.Total3PlayerMatchesWon < maximumWins) {
                CurrentConquestData.Total3PlayerMatchesWon++;
            }
            break;
        }
        case 6: {
            if (CurrentConquestData.TotalHeroHuntMatchesWon < maximumWins) {
                CurrentConquestData.TotalHeroHuntMatchesWon++;
            }
            if (CurrentConquestData.TotalMultiplayerMatchesWon < maximumWins) {
                CurrentConquestData.TotalMultiplayerMatchesWon++;
            }
            // TODO: Work out where it's getting player count from.
            if ((2 < *(u8 *) (0x020A80C8 + 0x12)) && CurrentConquestData.Total3PlayerMatchesWon < maximumWins) {
                CurrentConquestData.Total3PlayerMatchesWon++;
            }
            break;
        }
        case 7: {
            if (CurrentConquestData.TotalGoldRushMatchesWon < maximumWins) {
                CurrentConquestData.TotalGoldRushMatchesWon++;
            }
            if (CurrentConquestData.TotalMultiplayerMatchesWon < maximumWins) {
                CurrentConquestData.TotalMultiplayerMatchesWon++;
            }
            // TODO: Work out where it's getting player count from.
            if ((2 < *(u8 *) (0x020A80C8 + 0x12)) && CurrentConquestData.Total3PlayerMatchesWon < maximumWins) {
                CurrentConquestData.Total3PlayerMatchesWon++;
            }
            break;
        }
    }
}

u32 Battles::Save::ConquestData::Get115() {
    return 0x73;
}

u32 Battles::Save::ConquestData::Save() {

    u32 bitWriteResult = WritePaddingToNextByte();
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    u32 truncatedValue = TruncValue(CurrentConquestData.TotalBricksCollected, 32);
    bitWriteResult     = WriteBits(&truncatedValue, 32);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Unk1, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.HeroesDefeated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Unk2, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Unk3, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Unk4, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Unk5, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.SpecialsDefeated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.AlwaysZero, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.UnitsDestroyed, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TowersDestroyed, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.BuildingsDestroyed, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TotalFreePlayMatchesWon, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TotalMultiplayerMatchesWon, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.Total3PlayerMatchesWon, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TotalGoldRushMatchesWon, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TotalHeroHuntMatchesWon, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.MeleeUnitsCreated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.RangedUnitsCreated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.MountedUnitsCreated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.SpecialUnitsCreated, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.TowersBuilt, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.FarmsBuilt, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    truncatedValue = TruncValue((u32) CurrentConquestData.PointsHealed, 16);
    bitWriteResult = WriteBits(&truncatedValue, 16);
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    s32 someCounter = 0;
    do {
        truncatedValue = TruncValue((u32) CurrentConquestData.Unk6, 14);
        bitWriteResult = WriteBits(&truncatedValue, 14);
        if (bitWriteResult != 0) {
            return bitWriteResult;
        }
        someCounter++;
    } while (someCounter < 35);

    someCounter = 0;
    u8 *somePtr = (u8 *) 0x020a862c;
    do {
        truncatedValue = TruncValue((u32) (somePtr + 0x27), 1);
        bitWriteResult = WriteBits(&truncatedValue, 1);
        if (bitWriteResult != 0) {
            return bitWriteResult;
        }
        someCounter++;
        somePtr += 0x28;
    } while (someCounter < 25);

    bitWriteResult = WritePaddingToNextByte();
    if (bitWriteResult != 0) {
        return bitWriteResult;
    }

    return bitWriteResult;
}