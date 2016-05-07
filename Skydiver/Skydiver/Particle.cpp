

#include "Particle.hpp"


Particle::Particle(float xpos, float ypos) {
    location = new Location(xpos, ypos);
}

void Particle::render() {
    
    float x = location->getX();
    float y = location->getY();
    
    glBegin(GL_QUADS);
    
    glColor3f(1.f, 1.f, 0.f);
    glVertex2f(x-0.002f, y-0.002f);
    
//    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(x-0.002f, y+0.002f);
    
//    glColor3f(0.f, 1.f, 0.f);
    glVertex2f(x+0.002f, y+0.002f);
    
//    glColor3f(0.f, 0.f, 1.f);
    glVertex2f(x+0.002f, y-0.002f);
    
    glEnd();
    glFlush();

}


Particle::~Particle() {
    delete location;
}