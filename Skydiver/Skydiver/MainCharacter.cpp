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
    setLocation(x, y);
    upLock = downLock = leftLock = rightLock = up = down = left = right = false;
    usePhyscis = true;
}


void MainCharacter::render() {
    
    updateLocation();
        
    float x = location->getX();
    float y = location->getY();
    
    glBegin(GL_QUADS);
    
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(x-0.1f, y-0.1f);
    
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(x-0.1f, y+0.1f);
    
    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(x+0.1f, y+0.1f);
    
    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(x+0.1f, y-0.1f);
    
    glEnd();
    glFlush();
}


void MainCharacter::updateMovement(Direction dir, bool go) {
    if (dir == Direction::up && !upLock) {
        up = go;
        
        if (go) {
            downLock = false;
        }
    } else if (dir == Direction::down && !downLock) {
        down = go;
        
        if (go) {
            upLock = false;
        }
    } else if (dir == Direction::left && !leftLock) {
        left = go;
        
        if (go) {
            rightLock = false;
        }
    } else if (dir == Direction::right && !rightLock) {
        right = go;
        
        if (go) {
            leftLock = false;
        }
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



void MainCharacter::collisionAction(vector<Collider*> *colliders) {
    
    cout << "Main character at " << endl;
    location->print("");
    cout << " collision with the following " << colliders->size() << " objects:" << endl;
    
    Collider *currentCollider;
    
    for (int i = 0; i < colliders->size(); i++) {
        currentCollider = (*colliders)[i];
        
        if (!currentCollider) {
            cout << "Error: requested collision action for NULL collider" << endl;
            throw;
        }
        
        currentCollider->getLocation()->print("GameObject");
    }
    
    cout << endl;
    
    collisionMechanics(colliders);
}




void MainCharacter::collisionMechanics(vector<Collider *> *colliders) {
    
    if (!usePhyscis) return;
    
    Collider *currentCollider;
    
    for (int i = 0; i < colliders->size(); i++) {
        
        currentCollider = (*colliders)[i];
        
        if (!currentCollider) {
            cout << "Error: requested collision mechanics for NULL collider" << endl;
            throw;
        }
        
        Direction dir = collider->contactPoint(currentCollider);
        
        setMovementLock(dir, true);
         
    }
    
    cout << endl;
}



void MainCharacter::setMovementLock(enum Direction dir, bool lock) {
    
    if (dir == Direction::up) {
        if (lock) up = false;
        upLock = lock;
    }
    
    else if (dir == Direction::down) {
        if (lock) down = false;
        downLock = lock;
    }
    
    else if (dir == Direction::left) {
        if (lock) left = false;
        leftLock = lock;
    }
    
    else {
        if (lock) right = false;
        rightLock = lock;
    }
    
}


bool MainCharacter::isMoving(Direction dir) {
    if ((dir == Direction::up && up) || (dir == Direction::down && down) || (dir == Direction::left && left) || (dir == Direction::right && right)) return true;
    return false;
}


MainCharacter::~MainCharacter() {
    delete location;
}