//
//  BoxCollider.hpp
//  Skydiver
//
//  Created by Bruno Bachmann on 2016-04-24.
//  Copyright © 2016 Bruno Bachmann. All rights reserved.
//

#ifndef BoxCollider_hpp
#define BoxCollider_hpp

#include <stdio.h>
#include "Collider.hpp"


class BoxCollider : public Collider {
private:
    float xRange;
    float yRange;
    
public:
    BoxCollider();
    ~BoxCollider();
    
    void setBounds(float width, float height);
    bool isColliding(GameObject) override;
    Location *contactPoint(GameObject) override;
    std::vector<float> *getBounds();
};


#endif /* BoxCollider_hpp */
