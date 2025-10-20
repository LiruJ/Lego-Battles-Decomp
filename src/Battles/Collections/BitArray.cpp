#include "Collections/BitArray.hpp"

u32 Battles::BitArray::FUN_020ee9bc(s32 param_2) {}

bool Battles::BitArray::GetValueAt(u32 index) {

    u32 mask = 1 << (index & 0b00000111);
    u8 data  = Data[index >> 3];

    return data & mask;
}
