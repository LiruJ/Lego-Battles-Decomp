#ifndef VECTOR2U8_H
#define VECTOR2U8_H

#include "types.h"

namespace Battles {
    class Vector2u8 {
    public:
        u8 X;
        u8 Y;

        virtual ~Vector2u8() {}
        Vector2u8();
        Vector2u8(u8 x, u8 y);
        Vector2u8(Vector2u8 *vector);
    };
} // namespace Battles
#endif // !VECTOR2U8_H