

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include <stdio.h>
#include "Particle.hpp"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_PARTICLES 200

using namespace std;


class GameWindow {
private:
    vector<Particle*> particles;
    
public:
    vector<GameObject*> gameObjects;
    
    GameWindow();
    ~GameWindow();
    void manageTrackingParticles(float mouseX, float mouseY);
    void render(GLFWwindow *gw);
    void detectCollisions();
};


#endif /* GameWindow_hpp */
