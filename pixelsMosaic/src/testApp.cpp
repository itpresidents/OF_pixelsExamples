#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    myGrabber.setVerbose(true);
    myGrabber.initGrabber(640, 480);
    widthGrabb = myGrabber.getWidth();
    heightGrabb = myGrabber.getHeight();
    sizeMosaic =10;
    
    
	
}

//--------------------------------------------------------------
void testApp::update(){
    myGrabber.update();
    if (myGrabber.isFrameNew()) {
        int totalPixels = widthGrabb*heightGrabb*3;
        myPixels = myGrabber.getPixelsRef();
        
	}
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int y=0; y<heightGrabb;y=y+sizeMosaic){
        for (int x=0; x<widthGrabb;x=x+sizeMosaic){
            ofColor myColor=myPixels.getColor(x, y);
            ofSetColor(myColor.r,myColor.g, myColor.b);
            ofFill();
            ofRect(x, y, sizeMosaic, sizeMosaic);
        }
    }
	
	ofSetColor(0);
	ofDrawBitmapString("press l or s", 30, heightGrabb + 30);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'l')sizeMosaic++;
    if((key == 's')&& (sizeMosaic>1))sizeMosaic--;
	
	
    
}