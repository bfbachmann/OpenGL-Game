

#include "Particle.hpp"
#include <math.h>

Particle::Particle(float xpos, float ypos) {
    location = new Location(xpos, ypos);
    trajectory = new Vector2(0, 0);
    color.red = color.blue = color.green = 1.0;
}


void Particle::setColor(float red, float blue, float green) {
    if (red < 0.2 && green < 0.2 && blue < 0.2) { red = green = blue = 1; }
    color.red = red;
    color.blue = blue;
    color.green = green;
}


void Particle::setRandomColor() {
    setColor(sin(clock()), cos(clock()), sin(clock()));
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