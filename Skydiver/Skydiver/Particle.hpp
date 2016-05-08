

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "MainCharacter.hpp"
#include "GameObject.hpp"
#include "Location.hpp"
#include "Vector2.hpp"


typedef struct color {
    float red;
    float blue;
    float green;
} color3f;


class Particle {
private:
    color3f color;
    Location *location;
    Vector2 *trajectory;
public:
    Particle(float xpos, float ypos);
    ~Particle();
    
    void render();
    void updateLocation();
    void setColor(float red, float blue, float green);
    void setRandomColor();
    Location *getLocation() { return location; }
    Vector2 *getTrajectory() { return trajectory; }
};

#endif /* Particle_hpp */