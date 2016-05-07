

#ifndef GameObject_hpp
#define GameObject_hpp

#include <iostream>
#include <unistd.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Location.hpp"
#include <vector>


using namespace std;

class Collider;


class GameObject {
public:
    Location *location;
    Collider *collider;
    bool usePhyscis;
    
    GameObject();
    GameObject(float newX, float newY);
    ~GameObject();
    
    void setLocation(float x, float y);
    virtual void render() = 0;
    void addCollider(Collider * newCollider);
    Collider *getCollider() { return collider; }
    Location *getLocation() { return location; }
    virtual void collisionAction(vector<Collider*> *colliders);
    virtual void collisionMechanics(vector<Collider*> *colliders) = 0;
    virtual bool isMoving(Direction dir) = 0;
    virtual bool isMoving() = 0;
};

#endif /* GameObject_hpp */
