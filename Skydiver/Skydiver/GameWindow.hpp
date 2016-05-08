

#ifndef GameWindow_hpp
#define GameWindow_hpp

#include <stdio.h>
#include "Particle.hpp"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_PARTICLES 1000
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800

using namespace std;


class GameWindow {
private:
    vector<Particle*> particles;
    
public:
    vector<GameObject*> gameObjects;
    bool trackMouse = false;
    
    GameWindow();
    ~GameWindow();
    void manageTrackingParticles(float mouseX, float mouseY);
    void render(GLFWwindow *gw);
    void detectCollisions();
    void particleVortexAtCursor(float mouseX, float mouseY);
    void circularParticleEmitterAtCenter();
    void reverseEmitterAtCenter();
    void emitterAtCenter();
};


#endif /* GameWindow_hpp */
