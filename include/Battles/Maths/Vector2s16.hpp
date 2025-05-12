#ifndef VECTOR2S16_H
#define VECTOR2S16_H

#include "types.h"

namespace Battles {
    class Vector2s16 {
    public:
        s16 X;
        s16 Y;

        Vector2s16(s16 x, s16 y);

        virtual ~Vector2s16() {}
    };
} // namespace Battles
#endif // !VECTOR2S16_H