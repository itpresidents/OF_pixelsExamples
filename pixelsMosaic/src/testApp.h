#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);

		
	
	ofVideoGrabber myGrabber;
	int widthGrabb, heightGrabb, sizeMosaic;
	ofPixels myPixels; 
};
