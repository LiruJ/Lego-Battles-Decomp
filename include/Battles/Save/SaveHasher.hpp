#ifndef SAVE_HASHER_H
#define SAVE_HASHER_H

#include "types.h"
namespace Battles {
    namespace Save {
        static u32 *hashValues = NULL;

        u32 *InitialiseAndCalculateSaveHash(u32 *dest, u32 *source, s32 length);

        u32 *Unk1(u32 *dest, s32 length);
        u32 *Unk2(u32 *dest, s32 length);
        u32 *Unk3(u32 *dest);

        void InitialiseSaveChecksum(u32 *dest);

        void InitialiseSaveHashValues();

        u32 CalculateSaveChecksum(u32 *dest, u32 *source, s32 length);

        u32 Unk5(u32 *dest, s8 *source);
    } // namespace Save
} // namespace Battles
#endif // !SAVE_HASHER_H