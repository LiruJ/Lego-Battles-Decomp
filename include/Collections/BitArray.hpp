#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

#include "types.h"
namespace Battles {
    class BitArray {
    public:
        u32 BitCount;
        u32 ByteCount;
        u8 *Data;

        u32 FUN_020ee9bc(s32 param_2);
        bool GetValueAt(u32 index);

        virtual ~BitArray() {}
    };
} // namespace Battles

#endif // !BIT_ARRAY_H
