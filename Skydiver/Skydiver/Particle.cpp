

#include "Particle.hpp"
#include <math.h>

Particle::Particle(float xpos, float ypos) {
    location = new Location(xpos, ypos);
    trajectory = new Vector2(0, 0);
    color.red = color.blue = color.green = 1.0;
}


void Particle::setColor(float red, float blue, float green) {
    color.red = red;
    color.blue = blue;
    color.green = green;
}


void Particle::setRandomColor() {
    float time = clock();
    setColor(sin(time), cos(time), sin(time));
}


void Particle::render() {
    
    updateLocation();
    
    float x = location->getX();
    float y = location->getY();
    
    glBegin(GL_QUADS);
    
    glColor3f(color.red, color.blue, color.green);
    
    glVertex2f(x-0.002f, y-0.002f);
    glVertex2f(x-0.002f, y+0.002f);
    glVertex2f(x+0.002f, y+0.002f);
    glVertex2f(x+0.002f, y-0.002f);
    
    glEnd();
    glFlush();

}


void Particle::updateLocation() {
    float x = location->getX();
    float y = location->getY();
    
    location->set(x + trajectory->getX(), y + trajectory->getY());
}


Particle::~Particle() {
    delete location;
}