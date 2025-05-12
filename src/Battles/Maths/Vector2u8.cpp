#include "Battles/Maths/Vector2u8.hpp"

Battles::Vector2u8::Vector2u8() {
    X = 0;
    Y = 0;
}

Battles::Vector2u8::Vector2u8(u8 x, u8 y) {
    X = x;
    Y = y;
}

Battles::Vector2u8::Vector2u8(Vector2u8 *vector) {
    X = vector->X;
    Y = vector->Y;
}