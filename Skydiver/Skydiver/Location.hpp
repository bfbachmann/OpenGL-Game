//
//  Location.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-09.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef Location_hpp
#define Location_hpp

#include <iostream>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Location {
private:
    float x;
    float y;
    
public:
    Location();
    Location(float x, float y);
    float getX() { return x; }
    float getY() { return y; }
    void moveTowards(Location *destination);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool equals(Location *otherLocation);
    void set(float newX, float newY);
};

#endif /* Location_hpp */
