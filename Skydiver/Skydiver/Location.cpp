//
//  Location.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-09.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "Location.hpp"


Location::Location() {
    x = 0;
    y = 0;
}


Location::Location(int newX, int newY) {
    x = newX;
    y = newY;
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


void Location::set(int newX, int newY) {
    x = newX;
    y = newY;
}
