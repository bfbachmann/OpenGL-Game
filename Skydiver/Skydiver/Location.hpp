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
    int x;
    int y;
    
public:
    Location();
    Location(int x, int y);
    int getX() { return x; }
    int getY() { return y; }
    void moveTowards(Location *destination);
    bool equals(Location *otherLocation);
    void set(int newX, int newY);
};

#endif /* Location_hpp */
