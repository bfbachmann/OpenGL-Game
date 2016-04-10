//
//  GameObject.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-09.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "GameObject.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


GameObject::GameObject() {
    location = new Location();
}


void GameObject::render() {
    
    std::cout << "GameObject rendered at " << location->getX() << ", " << location->getY() << std::endl;
    
    int x = location->getX();
    int y = location->getY();

    
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 1.f);
    glVertex2f(-x/2, -y/2);
    glColor3f(0.f, 1.f, 1.f);
    glVertex2f(-x/2, y/2);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(x, y);
    glColor3f(1.f, 0.f, 1.f);
    glVertex2f(x/2, -y/2);
    glEnd();
}


Location *GameObject::getLocation() {
    return location;
}
