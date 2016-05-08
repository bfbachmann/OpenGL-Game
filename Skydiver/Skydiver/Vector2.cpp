

#include "Vector2.hpp"
#include <Math.h>

void Vector2::scale(float factor) {
    x *= factor;
    y *= factor;
}


float Vector2::magnitude() {
    return sqrt(x*x + y*y);
}



void Vector2::normalize() {
    float mag = magnitude();
    x /= mag;
    y /= mag;
}
