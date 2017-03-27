//
//  boid.cpp
//  week6homework2-1
//
//  Created by Hazal Mestci on 2/28/17.
//
//

#include "boid.hpp"

boid::boid(){
    pos = ofVec2f(ofGetWindowWidth()/2 + ofRandom(-350 , 350), ofGetWindowHeight()/2 + ofRandom(-350,350));
    vel = ofVec2f(0);
}

void boid::update(){
    
}

void boid::drawBoid(){
    ofDrawCircle(pos, size);
    
}

void boid::move(){
    vel = vel + v1 + v2 + v3;
    pos = pos + vel;
}
