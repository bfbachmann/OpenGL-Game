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
#include "Collider.hpp"
#include <vector>


GameObject::GameObject() {
    location = new Location();
    usePhyscis = true;
}


GameObject::GameObject(float newX, float newY) {
    location = new Location(newX, newY);
    usePhyscis = true;
}


GameObject::~GameObject() {
    delete location;
    if (collider) {
        delete collider;
    }
}


void GameObject::setLocation(float x, float y) {
    location->set(x, y);
}


void GameObject::addCollider(Collider *newCollider) {
    collider = newCollider;
    collider->setParent(this);
}


void GameObject::collisionAction(std::vector<Collider*> *colliders) {
    if (colliders->size() == 0) return;
    
    std::cout << "A GameObject has collided!" << endl;
}

