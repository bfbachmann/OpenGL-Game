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
#include <vector>
#include "Collider.hpp"


using namespace std;


MainCharacter::MainCharacter(float x, float y) {
    moveSpeed = 0.02;
    location = new Location(x, y);
    up = down = left = right = false;
}


void MainCharacter::render() {
    
    updateLocation();
        
    float x = location->getX();
    float y = location->getY();
    
    glBegin(GL_TRIANGLES);
    
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(x-0.2f, y-0.1f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(x+0.2f, y-0.1f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(x, y+0.2f);
    
    glEnd();
    glFlush();
}


void MainCharacter::updateMovement(Direction dir, bool go) {
    if (dir == Direction::up) {
        up = go;
    } else if (dir == Direction::down) {
        down = go;
    } else if (dir == Direction::left) {
        left = go;
    } else if (dir == Direction::right) {
        right = go;
    }
}


void MainCharacter::updateLocation() {
    if (up) {
        location->moveUp(moveSpeed);
    }
    if (down) {
        location->moveDown(moveSpeed);
    }
    if (left) {
        location->moveLeft(moveSpeed);
    }
    if (right) {
        location->moveRight(moveSpeed);
    }
}



void MainCharacter::collisionAction(vector<Collider*> colliders) {
    cout << "Number of colliders: " << colliders.size() << endl;
    cout << "Main character collision with following objects:" << endl;
    
    for (int i = 0; i < colliders.size(); i++) {
        colliders[i]->getLocation()->print("GameObject");
        cout << "\t at " << endl;
        colliders[i]->contactPoint(*this)->print("Collider");
    }
}



MainCharacter::~MainCharacter() {
    delete location;
}