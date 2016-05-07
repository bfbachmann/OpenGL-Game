

#include "BoxCollider.hpp"
#include <math.h>
#include "Location.hpp"


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
    
    //if (!parent->isMoving()) return false;
    
    BoxCollider *cadidateCollider = dynamic_cast<BoxCollider*>(candidate->getCollider());
    
    if (!cadidateCollider) return false;
    
    Location *parentLocation = this->getLocation();
    Location *candidateLocation = candidate->getLocation();
    
    float parentX = parentLocation->getX();
    float parentY = parentLocation->getY();
    
    float candidateX = candidateLocation->getX();
    float candidateY = candidateLocation->getY();
    
    vector<float> *candidateBounds = cadidateCollider->getBounds();
    
    float canxRange = (*candidateBounds)[0];
    float canyRange = (*candidateBounds)[1];
    
    delete candidateBounds;
    
    if ((fabs(parentX - candidateX) <= xRange + canxRange) && (fabs(parentY - candidateY) <= yRange + canyRange)) {
        return true;
    }
    return false;
}



Direction BoxCollider::contactPoint(Collider *otherCollider) {
    
    if (!otherCollider) {
        cout << "Error: requested contact point for NULL collider" << endl;
    }

    Location *location = getLocation();
    vector<float> *bounds = getBounds();
    Location *otherColliderLocation = otherCollider->getLocation();
    vector<float> *otherColliderBounds = otherCollider->getBounds();

    float otherX = otherColliderLocation->getX();
    float otherY = otherColliderLocation->getY();
    float x = location->getX();
    float y = location->getY();
    
    float otherUpperXbound = otherX + (*otherColliderBounds)[0];
    float otherLowerXbound = otherX - (*otherColliderBounds)[0];
    float otherUpperYbound = otherY + (*otherColliderBounds)[1];
    float otherLowerYbound = otherY - (*otherColliderBounds)[1];
    
    float upperXbound = x + (*bounds)[0];
    float lowerXbound = x - (*bounds)[0];
    float upperYbound = y + (*bounds)[1];
    float lowerYbound = y - (*bounds)[1];
    
    delete bounds;
    delete otherColliderBounds;
    
    float deltaX = otherX - x;
    float deltaY = otherY - y;
    
    float xOverlap;
    float yOverlap;
    
    bool up = false;
    bool left = false;
    
    if (deltaX > 0) {
        //other collider is to our right
        xOverlap = upperXbound - otherLowerXbound;
    } else {
        xOverlap = otherUpperXbound - lowerXbound;
        left = true;
    }
    
    if (deltaY > 0) {
        //other collider is above us
        yOverlap = upperYbound - otherLowerYbound;
        up = true;
    } else {
        yOverlap = otherUpperYbound - lowerYbound;
    }
    
    if (xOverlap > yOverlap) {
        if (up) return Direction::up;
        return Direction::down;
    } else {
        if (left) return Direction::left;
        return Direction::right;
    }
    

/*
    if ((otherLowerXbound <= upperXbound && otherLowerXbound >= lowerXbound) || (otherUpperXbound <= upperXbound && otherUpperXbound >= lowerXbound) ||
           (lowerXbound <= otherUpperXbound && lowerXbound >= otherLowerXbound) || (upperXbound <= otherUpperXbound && upperXbound >= otherLowerXbound)) {
        
        //we know the two colliders are touching on their top and bottom sides
        
        if (deltaY > 0) {
            //contact on this collider's top face
            
            cout << "Top face" << endl;
            return Direction::up;
        } else {
            //contact on this collider's bottom face
            
            cout << "Bottom face" << endl;
            return Direction::down;
        }
        
    }
    
    else {
        //we know the two colliders are touching on ther left and right sides
        
        if (deltaX > 0) {
            //contact on this collider's right face
            
            cout << "Right face" << endl;
            return Direction::right;
        } else {
            //contact on this collider's left face
            
            cout << "Left face" << endl;
            return Direction::left;
        }
    }
*/
}

BoxCollider::~BoxCollider() {

}
