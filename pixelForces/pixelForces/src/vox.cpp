#include "Vox.h"
Vox::Vox(){
}

void Vox::setup(){
	v = ofVec3f(0, g, 0);
	nivelPiso = ofGetHeight()-150;
}

void Vox::setup(ofVec3f pt) {
	pos = pt;
	v = ofVec3f(0, g, 0);
	nivelPiso = ofGetHeight() - 150;
}
void Vox::setup(ofVec3f pt, int t) {
	tam = t;
	pos = pt;
	v = ofVec3f(0, g, 0);
	nivelPiso = ofGetHeight() - 150;
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
	if (b3d) {
		ofDrawBox(pos, tam);
	}
	else {
		ofDrawRectangle(pos, tam, tam);
	}
}
