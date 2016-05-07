

#include "GameWindow.hpp"
#include "Collider.hpp"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.hpp"



using namespace std;



GameWindow::GameWindow() {
    
}



void GameWindow::render(GLFWwindow *gw) {
    
    double xpos;
    double ypos;
    
    glfwGetCursorPos(gw, &xpos, &ypos);
    manageTrackingParticles((float) xpos, (float) ypos);
    detectCollisions();
    
    for (int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->render();
    }
    
    for (int i = 0; i < particles.size(); i++) {
        particles[i]->render();
    }

}



GameWindow::~GameWindow() {
    
    for (int i = 0; i < gameObjects.size(); i++) {
        delete gameObjects[i];
    }
}


/* 
 * Generates particles at current mouse location until MAX_PARTICLES
 * has been reached, then deletes the oldest particle and adds a new one
 * each time it is called.
 */
void GameWindow::manageTrackingParticles(float mouseX, float mouseY) {
    
    mouseX = mouseX/320.0 - 1;
    mouseY = 1 - mouseY/240.0;
    
    Particle *particle = new Particle(mouseX, mouseY);

    if (!(particles.size() < MAX_PARTICLES)) {
        delete particles[0];
        particles.erase(particles.begin());
    }
    
    particles.push_back(particle);
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
        
        if (collidingWith->size() > 0) gameObjects[i]->collisionAction(collidingWith);
        delete collidingWith;
    }
}