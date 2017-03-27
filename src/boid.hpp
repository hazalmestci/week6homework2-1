//
//  boid.hpp
//  week6homework2-1
//
//  Created by Hazal Mestci on 2/28/17.
//
//

#pragma once
#include "ofMain.h"

class boid{
public:
    boid();
    void update();
    void drawBoid();
    void move();
    
    ofVec2f pos, vel;
    ofVec2f v1, v2, v3;
    
    int size = 1;
};
