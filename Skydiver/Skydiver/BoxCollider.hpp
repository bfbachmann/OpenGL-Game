

#ifndef BoxCollider_hpp
#define BoxCollider_hpp

#include <stdio.h>
#include "Collider.hpp"


class BoxCollider : public Collider {
private:
    float xRange;
    float yRange;
    
public:
    GameObject *parent;
    
    BoxCollider(float width, float height, GameObject *newParent);
    ~BoxCollider();
    
    void setParent(GameObject* newParent) override { parent = newParent; }
    void setBounds(float width, float height);
    Location *getLocation() override { return parent->getLocation(); }
    bool isColliding(GameObject *otherObject) override;
    Direction contactPoint(Collider *otherCollider) override;
    std::vector<float> *getBounds() override;
};


#endif /* BoxCollider_hpp */
