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


class MainCharacter : public GameObject {
private:
    Location *location;
    
public:
    MainCharacter(float x, float y);
    ~MainCharacter();
    
    void render();
    Location *getLocation() { return location; }
};


#endif /* MainCharacter_hpp */
