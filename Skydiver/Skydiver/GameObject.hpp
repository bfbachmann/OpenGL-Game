//
//  GameObject.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-09.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Location.hpp"

class Collider;

class GameObject {
private:
    Location *location;
    Collider *collider;
    
public:
    
    GameObject();
    ~GameObject();
    virtual void render() = 0;
    void addCollider(Collider * newCollider);
    Collider *getCollider() { return collider; }
    Location *getLocation() { return location; }
};

#endif /* GameObject_hpp */
