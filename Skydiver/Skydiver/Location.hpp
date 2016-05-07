

#ifndef Location_hpp
#define Location_hpp

#include <iostream>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>


enum Direction {up, down, left, right};


class Location {
private:
    float x;
    float y;
    bool up;
    bool down;
    bool left;
    bool right;
    
public:
    Location();
    Location(float x, float y);
    float getX() { return x; }
    float getY() { return y; }
    void moveTowards(Location *destination);
    void moveUp(float);
    void moveDown(float);
    void moveLeft(float);
    void moveRight(float);
    bool equals(Location *otherLocation);
    void set(float newX, float newY);
    void set(Location loc);
    void print(std::string name);
};

#endif /* Location_hpp */
