//
//  MainCharacter.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-10.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "MainCharacter.hpp"


MainCharacter::MainCharacter(float x, float y) {
    location = new Location(x, y);
    
    std::cout << "Main character created." << std::endl;
}


void MainCharacter::render() {
        
    int x = location->getX();
    int y = location->getY();
    
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(x-0.6f, y-0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(x+0.6f, y-0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(x+0.f, y+0.6f, 0.f);
    
    glEnd();
}


MainCharacter::~MainCharacter() {
    delete location;
}