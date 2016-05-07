

#include "GameObject.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Collider.hpp"
#include <vector>


GameObject::GameObject() {
    location = new Location();
    usePhyscis = true;
}

/* Create a new gameObject at locaiton (newX, newY) */
GameObject::GameObject(float newX, float newY) {
    location = new Location(newX, newY);
    usePhyscis = true;
}


GameObject::~GameObject() {
    delete location;
//    if (collider != NULL) {
//        delete collider;
//    }
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

