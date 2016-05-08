

#include "GameWindow.hpp"
#include "Collider.hpp"
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Particle.hpp"
#include <time.h>
#include <math.h>


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
    
    if (trackMouse) {
        mouseX = mouseX/(WINDOW_WIDTH/2) - 1;
        mouseY = 1 - mouseY/(WINDOW_HEIGHT/2);
        
        Particle *particle = new Particle(mouseX, mouseY);
        particle->setColor(sin(clock()), sin(clock()), sin(clock()));
        
        if (particles.size() >= MAX_PARTICLES) {
            delete particles[0];
            particles.erase(particles.begin());
        }
        
        particles.push_back(particle);
    }
    
    // Call particle movement funcitons:
    if (particleVortexAtCursor_b) particleVortexAtCursor(mouseX, mouseY);
    if (circularParticleEmitterAtCenter_b) circularParticleEmitterAtCenter();
    if (reverseEmitterAtCenter_b) reverseEmitterAtCenter();
    if (emitterAtCenter_b) emitterAtCenter();
    if (particleRing_b) particleRing();
}




void GameWindow::particleVortexAtCursor(float mouseX, float mouseY) {
    
    float moveX;
    float moveY;
    
    for (int i = 0; i < particles.size(); i++) {
        Particle *particle = particles[i];
        Location *loc = particle->getLocation();
        moveX = mouseX - loc->getX();
        moveY = mouseY - loc->getY();
        particle->getTrajectory()->set(moveX, moveY);
        particle->getTrajectory()->scale(0.05);
    }
}





void GameWindow::circularParticleEmitterAtCenter() {
    
    Particle *particle = new Particle(0, 0);
    particle->setRandomColor();
    
    if (particles.size() >= MAX_PARTICLES) {
        delete particles[0];
        particles.erase(particles.begin());
    }
    
    particles.push_back(particle);
    
    float moveX;
    float moveY;
    float x;
    float y;
    long particleCount = particles.size();
    
    for (int i = 0; i < particleCount; i++) {
        
        x = cos(i);
        y = sin(i);
        
        Particle *particle = particles[i];
        Location *loc = particle->getLocation();
        moveX = x - loc->getX();
        moveY = y - loc->getY();
        particle->getTrajectory()->set(moveX, moveY);
        particle->getTrajectory()->scale(0.05);
    }
}




void GameWindow::reverseEmitterAtCenter() {
    time_t seconds = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
    long time = static_cast<long>(seconds);
    float x = sin(time);
    float y = cos(time);
    
    Particle *particle = new Particle(x, y);
    particle->setRandomColor();
    
    if (particles.size() >= MAX_PARTICLES) {
        delete particles[0];
        particles.erase(particles.begin());
    }
    
    particles.push_back(particle);
    
    // Call particle movement funcitons:
    particleVortexAtCursor(0, 0);
}



void GameWindow::emitterAtCenter() {
    float x = rand() % 200 - 99;
    float y = rand() % 200 - 99;
    
    Particle *particle = new Particle(0, 0);
    Vector2 *traj = particle->getTrajectory();
    particle->setRandomColor();
    traj->set(x, y);
    traj->normalize();
    traj->scale(0.03);
    
    if (particles.size() >= MAX_PARTICLES) {
        delete particles[0];
        particles.erase(particles.begin());
    }
    
    particles.push_back(particle);
    
    for (int i = 0; i < particles.size(); i++) {
        Vector2 *traj = particles[i]->getTrajectory();
        traj->scale(0.98);
    }
}



void GameWindow::particleRing() {
    Particle *particle = new Particle(-1, 0);
    Vector2 *traj = particle->getTrajectory();
    traj->set(0, 1);
    traj->scale(0.03);
    
    if (particles.size() >= MAX_PARTICLES) {
        delete particles[0];
        particles.erase(particles.begin());
    }
    
    particles.push_back(particle);
    
    for (int i = 0; i < particles.size(); i++) {
        long time = clock();
        particles[i]->getLocation()->set(0.09*cos(time), 0.09*sin(time));
        
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
        
        if (collidingWith->size() > 0) gameObjects[i]->collisionAction(collidingWith);
        delete collidingWith;
    }
}


void GameWindow::printStatus() {
    cout << "circularParticleEmitterAtCenter \t" << circularParticleEmitterAtCenter_b << endl;
    cout << "emitterAtCenter \t" << emitterAtCenter_b << endl;
    cout << "particleVortexAtCursor \t" << particleVortexAtCursor_b << endl;
    cout << "reverseEmitterAtCenter_b \t" << reverseEmitterAtCenter_b << endl;
    cout << "particleRing \t" << particleRing_b << endl;
    cout << "Track mouse \t" << trackMouse << endl << endl;
}