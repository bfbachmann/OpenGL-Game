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


GameObject::GameObject() {
    collider = NULL;
    location = NULL;
}


GameObject::~GameObject() {
    delete location;
}


void GameObject::addCollider(Collider *newCollider) {
    collider = newCollider;
    collider->setParent(this);
}

