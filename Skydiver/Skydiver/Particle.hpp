

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "MainCharacter.hpp"
#include "GameObject.hpp"
#include "Location.hpp"


class Particle {
private:
    Location *location;
public:
    Particle(float xpos, float ypos);
    ~Particle();
    void render();
};

#endif /* Particle_hpp */