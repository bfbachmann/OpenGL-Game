//
//  GameWindow.cpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-26.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#include "GameWindow.hpp"
#include "Collider.hpp"
#include <vector>



using namespace std;



GameWindow::GameWindow() {
    
}



void GameWindow::render() {   
    
    detectCollisions();
    
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->render();
    }
    
}



GameWindow::~GameWindow() {
    
    for (int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}



void GameWindow::detectCollisions() {
    
    //TODO: MAKE THIS FASTER
    for (int i = 0; i < gameObjects.size(); i++) {
        
        vector<Collider*> *collidingWith = new vector<Collider*>;
        
        for (int j = 0; j < gameObjects.size(); j++) {
            
            if (j != i && gameObjects[i]->getCollider()->isColliding(gameObjects[j])) {
                collidingWith->push_back(gameObjects[j]->getCollider());
            }
        }
        
        gameObjects[i]->collisionAction(collidingWith);
        delete collidingWith;
    }
}