//
//  Collider.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-24.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Location.hpp"
#include "GameObject.hpp"


class Collider {
public:
    virtual void setParent(GameObject* newParent) = 0;
    virtual bool isColliding(GameObject *otherObject) = 0;
    virtual Location *contactPoint(Collider *otherCollider) = 0;
    virtual Location *getLocation() = 0;
    virtual vector<float> *getBounds() = 0;
};

#endif /* Collider_hpp */
