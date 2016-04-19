//
//  MainCharacter.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-10.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "MainCharacter.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>


MainCharacter::MainCharacter(float x, float y) {
    location = new Location(x, y);
    
    std::cout << "Main character created." << std::endl;
}


void MainCharacter::render() {
        
    float x = location->getX();
    float y = location->getY();
    
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(x-0.2f, y-0.1f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(x+0.2f, y-0.1f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(x+0.f, y+0.2f);
    
    glEnd();
    glFlush();
}


MainCharacter::~MainCharacter() {
    delete location;
}