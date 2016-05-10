

#ifndef Vector2_hpp
#define Vector2_hpp

#include <stdio.h>


class Vector2 {
private:
    float x, y;
    
public:
    Vector2(float xval, float yval) { x = xval; y = yval; };
    ~Vector2();
    
    float getX() { return x; }
    float getY() { return y; }
    void set(float newX, float newY) { x = newX; y = newY; }
    void scale(float factor);
    float magnitude();
    void normalize();
    void add(Vector2 *vec);
    void add(float xval, float yval);
};

#endif /* Vector2_hpp */
