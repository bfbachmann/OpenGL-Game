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


class GameObject {
private:
    Location *location;
    
public:
    GameObject();
    void render();
    Location *getLocation();
};

#endif /* GameObject_hpp */
