#include "Vox.h"
Vox::Vox(){
}

void Vox::setup(){
	g = 9.81;
	v = ofVec3f(0, g, 0);
	nivelPiso = 250;
}

void Vox::setup(ofVec3f pt) {
	pos = pt;
	v = ofVec3f(0, 10, 0);
	nivelPiso = 250;
}

void Vox::update(){
	pos += v;
	if (pos.y > nivelPiso) {
		vive = false;
	}
}

void Vox::draw(ofVec3f p, int t, ofColor c) {
	ofSetColor(c);
	ofFill();
	ofDrawBox(p, t);
}

void Vox::draw() {
	ofDrawBox(pos, 10);
}
