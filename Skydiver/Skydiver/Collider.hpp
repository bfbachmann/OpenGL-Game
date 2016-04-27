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
    virtual bool isColliding(GameObject) = 0;
    virtual Location *contactPoint(GameObject) = 0;
    virtual Location *getLocation() = 0;
};

#endif /* Collider_hpp */
