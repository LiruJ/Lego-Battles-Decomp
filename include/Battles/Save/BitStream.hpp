#ifndef BIT_STREAM_H
#define BIT_STREAM_H

#include "types.h"
namespace Battles {
    namespace Save {
        void ResetBitStream();

        u32 FUN_020ee9bc(s32 param_1, s32 param_2);

        u32 TruncToBits(u32 value, s32 bitCount);
        u32 TruncValue(u32 value, s32 bitCount);

        u8 WriteBytes(u8 *source, s32 count);

        u8 WriteBits(u32 *source, s32 count);

        u8 WritePaddingToNextByte();
    } // namespace Save
} // namespace Battles

#endif // !BIT_STREAM_H
