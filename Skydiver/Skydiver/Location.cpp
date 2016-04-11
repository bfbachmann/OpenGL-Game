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
    
    std::cout << "\tDefualt locaiton created" << std::endl;
}


Location::Location(float newX, float newY) {
    x = newX;
    y = newY;
    
    std::cout << "\tNew location (" << x << ", " << y << ")" << std::endl;
}


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


void Location::moveUp() {
    y = y - 1.0;
}


void Location::moveDown() {
    y = y + 1.0;
} 


void Location::moveLeft() {
    x = x- 1.0;
}


void Location::moveRight() {
    x = x + 1.0;
}


void Location::set(float newX, float newY) {
    x = newX;
    y = newY;
}
