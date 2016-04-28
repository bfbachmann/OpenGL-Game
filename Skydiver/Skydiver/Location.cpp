//
//  Location.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-09.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "Location.hpp"


Location::Location() {
    x = 0.0;
    y = 0.0;
    up = down = left = right = false;
}


Location::Location(float newX, float newY) {
    x = newX;
    y = newY;
}


//TODO: fix this
void Location::moveTowards(Location *destination) {
    if (destination->getX() > x) {
        x++;
    } else if (destination->getY() < x) {
        x--;
    } 
    
    if (destination->getY() > y) {
        y++;
    } else if (destination->getY() < y) {
        y--;
    } 
}



bool Location::equals(Location *otherLocation) {
    if (otherLocation->getX() == x && otherLocation->getY() == y) {
        return true;
    }
    return false;
}


void Location::moveUp(float amount) {
    y = y + amount;
}


void Location::moveDown(float amount) {
    y = y - amount;
} 


void Location::moveLeft(float amount) {
    x = x - amount;
}


void Location::moveRight(float amount) {
    x = x + amount;
}


void Location::set(float newX, float newY) {
    x = newX;
    y = newY;
}


void Location::set(Location loc) {
    x = loc.x;
    y = loc.y;
}


void Location::print(std::string name) {
    std::cout << "\t" << name << " location: (" << x << ", " << y << ")" << std::endl;
}
