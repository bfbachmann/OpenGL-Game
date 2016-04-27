//
//  GameWindow.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-26.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include <stdio.h>
#include "MainCharacter.hpp"
#include <vector>


using namespace std;


class GameWindow {
public:
    vector<GameObject*> gameObjects;
    
    GameWindow();
    ~GameWindow();
    void render();
    void detectCollisions();
};


#endif /* GameWindow_hpp */
