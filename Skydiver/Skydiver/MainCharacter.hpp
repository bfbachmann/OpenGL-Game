//
//  MainCharacter.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-10.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef MainCharacter_hpp
#define MainCharacter_hpp

#include <iostream>
#include "GameObject.hpp"
#include "Location.hpp"

enum Direction {up, down, left, right};

class MainCharacter : public GameObject {
private:
    Location *location;
    bool up;
    bool down;
    bool left;
    bool right;
    float moveSpeed;
    
public:
    MainCharacter(float x, float y);
    ~MainCharacter();
    
    void render();
    Location *getLocation() { return location; }
    void updateMovement(enum Direction, bool);
    void updateLocation();
};


#endif /* MainCharacter_hpp */
