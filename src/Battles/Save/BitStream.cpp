#include "Battles/Save/BitStream.hpp"

void Battles::Save::ResetBitStream() {}

u32 Battles::Save::FUN_020ee9bc(s32 param_1, s32 param_2) {
    return u32();
}

u32 Battles::Save::TruncToBits(u32 value, s32 bitCount) {
    u32 a = (0x20U - bitCount) & 0xff;

    return (u32) (value << a) >> a;
}

u32 Battles::Save::TruncValue(u32 value, s32 bitCount) {
    return u32();
}

u8 Battles::Save::WriteBytes(u8 *source, s32 count) {}

u8 Battles::Save::WriteBits(u32 *source, s32 count) {
    return u8();
}

u8 Battles::Save::WritePaddingToNextByte() {

    u32 writeReturnCode;
    u8 loadCounter = 1; // PTR_SomeSaveData_0204bbd4->CurrentBitCount;
    if (loadCounter == 8) {

    } else if (loadCounter != 0) {
        u32 tempZero    = 0;
        writeReturnCode = WriteBits(&tempZero, (u32) (u8) (8 - loadCounter));
        WritePaddingToNextByte();
        if (writeReturnCode != 0) {
            return (u8) writeReturnCode;
        }
    }

    return 0;
}
