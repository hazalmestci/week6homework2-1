
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    
    minDist = 50;
    for(int i = 0; i <NUMBOIDS; i++){
        myBoids.push_back(boid());
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
 //    ofPoint Mouse= ofPoint (mouseX, mouseY);
    
    
    for (int i = 0; i < NUMBOIDS; i++){
        myBoids[i].v1 = calculateV1(myBoids, i);
        myBoids[i].v2 = calculateV2(myBoids, i);
        myBoids[i].move();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < NUMBOIDS; i++){
    ofSetColor(ofRandom(200),ofRandom(170),ofRandom(200),ofRandom(250));
        myBoids[i].drawBoid();
          ofSetColor(ofRandom(150,255),ofRandom(150,255),ofRandom(150,255),ofRandom(150,255));
        ofSetFrameRate(50);
        ofCircle(i*2, i, 2);
    }
}


ofVec2f ofApp::calculateV1(vector<boid> Boids, int index){
    //PROCEDURE rule1(boid bJ)
    //Vector pcJ
    //FOR EACH BOID b
    //IF b != bJ THEN
    //			pcJ = pcJ + b.position
    //END IF
    //END
    
    //pcJ = pcJ / N-1
    
    //RETURN (pcJ - bJ.position) / 100
    
    //END PROCEDURE
    
    ofVec2f pCenter;
    
    for(int i = 0; i < Boids.size(); i++){
        if(i != index){
            pCenter += Boids[i].pos;
        }
    }
    pCenter = pCenter / (Boids.size() -1);
    return (pCenter - Boids[index].pos) / 300;
    
    
}

ofVec2f ofApp::calculateV2(vector<boid> Boids, int index){
    //    PROCEDURE rule2(boid bJ)
    //    Vector c = 0;
    //    FOR EACH BOID b
    //    IF b != bJ THEN
    //				IF |b.position - bJ.position| < 100 THEN
    //    c = c - (b.position - bJ.position)
    //				END IF
    //    END IF
    //    END
    //
    //    RETURN c
    //
    //    END PROCEDURE
    
    ofVec2f dist;
    
    for(int i = 0; i < Boids.size(); i++){
        if(i != index){
            if((Boids[i].pos).distance(Boids[index].pos) < 20){
                dist = dist - (Boids[i].pos - Boids[index].pos);
            }
        }
    }
    return dist/10;
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'a') {
        
        for (int i = 0; i < NUMBOIDS; i++){
            ofSetColor(150,0,160);
            myBoids[i].drawBoid();
        }
        
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
