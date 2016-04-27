//
//  BoxCollider.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-24.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "BoxCollider.hpp"
#include <math.h>


using namespace std;


BoxCollider::BoxCollider(float width, float height, GameObject *newParent) {
    setBounds(width, height);
    this->setParent(newParent);
}


void BoxCollider::setBounds(float width, float height) {
    xRange = width/2;
    yRange = height/2;
}


vector<float> *BoxCollider::getBounds() {
    return new vector<float> { xRange, yRange };
}



bool BoxCollider::isColliding(GameObject *candidate) {
    
    BoxCollider *cadidateCollider = dynamic_cast<BoxCollider*>(candidate->getCollider());
    
    if (!cadidateCollider) return false;
    
    Location *parentLocation = this->getLocation();
    Location *candidateLocation = candidate->getLocation();
    
    float parentX = parentLocation->getX();
    float parentY = parentLocation->getY();
    
    float candidateX = candidateLocation->getX();
    float candidateY = candidateLocation->getY();
    
    vector<float> candidateBounds = *cadidateCollider->getBounds();
    
    float canxRange = candidateBounds[0];
    float canyRange = candidateBounds[1];
    
    if ((fabs(parentX - candidateX) <= xRange + canxRange) && (fabs(parentY - candidateY) <= yRange + canyRange)) {
        return true;
    }
    return false;
}



Location *BoxCollider::contactPoint(Collider *otherCollider) {
    
    if (!otherCollider) {
        cout << "Error: requested contact point for NULL collider" << endl;
    }
    
    if (!otherCollider->isColliding(parent)) {
        cout << "Error: requested contact point for gameobject that is not colliding" << endl;
        throw;
    }
    
    Location *otherColliderLocation = otherCollider->getLocation();
    
    float x = (getLocation()->getX() + otherColliderLocation->getX())/2;
    float y = (getLocation()->getY() + otherColliderLocation->getY())/2;
    
    return new Location(x, y);

}