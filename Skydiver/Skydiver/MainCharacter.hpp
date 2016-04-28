//
//  MainCharacter.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-10.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef MainCharacter_hpp
#define MainCharacter_hpp

#include <iostream>
#include "GameObject.hpp"
#include "Location.hpp"
#include <vector>


using namespace std;


enum Direction {up, down, left, right};


class MainCharacter : public GameObject {
private:
    bool up, upLock;
    bool down, downLock;
    bool left, leftLock;
    bool right, rightLock;
    float moveSpeed;
    
public:
    MainCharacter(float x, float y);
    ~MainCharacter();
    
    void render() override;
    void updateMovement(enum Direction, bool);
    void setMovementLock(enum Direction dir, bool lock);
    void updateLocation();
    void collisionAction(vector<Collider*> *colliders) override;
    void collisionMechanics(vector<Collider*> *colliders) override;
};


#endif /* MainCharacter_hpp */
