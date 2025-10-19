#include "Battles/Save/SaveHasher.hpp"
#include "Memory/Memory.hpp"

u32 *Battles::Save::InitialiseAndCalculateSaveHash(u32 *dest, u32 *source, s32 length) {
    InitialiseSaveChecksum(dest);
    CalculateSaveChecksum(dest, source, length);
    return dest;
}

u32 *Battles::Save::Unk1(u32 *dest, s32 length) {
    InitialiseSaveChecksum(dest);
    Unk5(dest, (s8 *) length);
    return dest;
}

u32 *Battles::Save::Unk2(u32 *dest, s32 length) {
    InitialiseSaveChecksum(dest);
    // FUN_020F1FA0(length);
    Unk5(dest, (s8 *) length);
    return dest;
}

u32 *Battles::Save::Unk3(u32 *dest) {
    InitialiseSaveChecksum(dest);
    return dest;
}

void Battles::Save::InitialiseSaveChecksum(u32 *dest) {
    *dest   = 0U;
    dest[1] = 0XFFFFFFFFU;
    return;
}

void Battles::Save::InitialiseSaveHashValues() {

    if (hashValues != NULL) {
        return;
    }
    hashValues = Main::AllocateMemory(0x400);

    u32 currentIndex = 0;

    u32 key = 0xEDB88320;
    do {
        s32 hashCounter = 8;
        u32 hashedValue = currentIndex;

        do {
            bool isOdd = (hashedValue & 1) == 1;
            if (isOdd) {
                hashedValue = key ^ (hashedValue >> 1);
            } else {
                hashedValue >>= 1;
            }
            hashCounter--;
        } while (0 < hashCounter);

        hashValues[currentIndex] = hashedValue;
        currentIndex++;

    } while (currentIndex < 256);
}

u32 Battles::Save::CalculateSaveChecksum(u32 *dest, u32 *source, s32 length) {

    s32 currentByteIndex = 0;

    if (0 < length) {
        do {
            u8 *currentByte = (u8 *) (source + currentByteIndex);
            currentByteIndex++;

            u32 valueIndex = (dest[1] & 0xFF) ^ (u32) *currentByte;
            u32 hashValue  = hashValues[valueIndex];
            dest[1]        = hashValue ^ (dest[1] >> 8);
            dest[0]++;
        } while (currentByteIndex < length);
    }

    return ~dest[1];
}

u32 Battles::Save::Unk5(u32 *dest, s8 *source) {

    u32 currentData;
    if (source != 0) {
        currentData = (u32) *source;
    }
    if (currentData != 0) {
        do {
            u32 valueIndex = ((dest[1] & 0xFFU) ^ currentData) & 0xFF;
            u32 hashValue  = hashValues[valueIndex];
            dest[1]        = hashValue ^ (dest[1] >> 8);
            dest[0]++;
            source++;
            currentData = (u32) *source;
        } while (currentData != 0);
    }

    return ~dest[1];
}
