#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    player.loadMovie("fingers.mov");
    player.setLoopState(OF_LOOP_NORMAL);
    player.play();
    ofSetFrameRate(30);
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    //player.draw(0, 0);
    
    if(player.isFrameNew()) {
        
        int skip = 15;
        //int circleSize = 10;
        ofPixels pixels = player.getPixelsRef();
        for(int y = 0; y < player.getHeight(); y+= skip) {
            for(int x = 0; x < player.getWidth(); x+= skip) {
                ofColor color = pixels.getColor(x, y);
                
                int brightness = color.getBrightness();
                float circSize = ofMap(brightness, 0, 255, 2, 10);
                ofSetColor(color.r, 0, 0);
                ofEllipse(x, y, circSize, circSize);
                
                ofSetColor(0, color.g, 0);
                ofEllipse(x + skip/3, y + skip/3, circSize, circSize);
                
                ofSetColor(0, 0, color.b);
                ofEllipse(x-skip/3, y+skip/3, circSize, circSize);
				
                
            }
        }
    }
	
}
