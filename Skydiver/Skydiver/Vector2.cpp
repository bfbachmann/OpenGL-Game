

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


void Vector2::add(Vector2 *vec) {
    x = vec->getX() + x;
    y = vec->getY() + y;
}


void Vector2::add(float xval, float yval) {
    x = xval + x;
    y = yval + y;
}


Vector2::~Vector2() {

}
