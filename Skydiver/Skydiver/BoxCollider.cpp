//
//  BoxCollider.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-24.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "BoxCollider.hpp"


using namespace std;



void BoxCollider::setBounds(float width, float height) {
    xRange = width/2;
    yRange = height/2;
}


vector<float> *BoxCollider::getBounds() {
    return new vector<float> { xRange, yRange };
}



bool BoxCollider::isColliding(GameObject candidate) {
    
    BoxCollider *cadidateCollider = dynamic_cast<BoxCollider*>(candidate.getCollider());
    
    if (!cadidateCollider) return false;
    
    Location *parentLocation = getLocation();
    Location *candidateLocation = candidate.getLocation();
    
    float parentX = parentLocation->getX();
    float parentY = parentLocation->getY();
    
    float candidateX = candidateLocation->getX();
    float candidateY = candidateLocation->getY();
    
    vector<float> candidateBounds = *cadidateCollider->getBounds();
    
    float canxRange = candidateBounds[0];
    float canyRange = candidateBounds[1];
    
    float xMin = parentX - xRange;
    float xMax = parentX + xRange;
    float yMin = parentY + yRange;
    float yMax = parentY - yRange;
    
    float canxMin = candidateX - xRange;
    float canxMax = candidateX + xRange;
    float canyMin = candidateY + yRange;
    float canyMax = candidateY - yRange;
    
//    if (caxMin )
    return true;
}