#include "ofApp.h"
#include "ofxWin8Touch.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	v.setup();
	ofxWin8TouchSetup();
	ofRegisterTouchEvents(this);
	ofSetVerticalSync(true);
}

bool checkDead(Vox &v) {
	return v.vive;
}

//--------------------------------------------------------------
void ofApp::update(){
	v.update();
	for (auto &vt : vs) {
		vt.update();
	}
	for (int i = 0; i < vs.size(); i++) {
		Vox vt;
		vt = vs.at(i);
		if (!vt.vive) {
			vs.erase(vs.begin()+i);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	v.draw();
	for (auto &vt : vs) {
		vt.draw();
	}

	for (auto &i : touchMap) {
		auto &touch = i.second;
		/*
		ofPushMatrix();
		ofTranslate(touch.x, touch.y);
		ofRotate(90 - touch.angle);
		ofRect(-touch.width / 2, -touch.height / 2, touch.width, touch.height);
		ofEllipse(0, 0, touch.width * 5, touch.height * 5);
		ofDrawBitmapString(ofVAArgsToString("%d", touch.id), 0, 0);
		ofPopMatrix();
		*/
		
		Vox vt;
		vt.setup(ofVec3f(touch.x, touch.y, ofRandom(-10, 10)), 5);
		vs.push_back(vt);
		}

	for (int i = 0; i < vs.size(); i++) {
		Vox vt;
		vt = vs.at(i);
		if (!vt.vive) {
			vs.erase(vs.begin() + i);
		}
	}
	ofPushStyle();
	ofSetLineWidth(2);
	ofSetColor(255, 50);
	ofNoFill();
	for (auto &v : vs) {
		for (auto &vp : vs) {
			float d = ofDist(v.pos.x, v.pos.y, vp.pos.x, vp.pos.y);
			if (d < 150) {
				ofDrawLine(v.pos.x, v.pos.y, vp.pos.x, vp.pos.y);
			}
		}
	}
	ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == ' ') {
		for (int i = 0; i < 150; i++) {
			Vox vt;
			vt.setup(ofVec3f(ofGetMouseX() + ofRandom(-100, 100), ofGetMouseY() + ofRandom(-100, 100), +ofRandom(-100, 100)));
			vs.push_back(vt);
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
	Vox vt;
	vt.setup(ofVec3f(ofGetMouseX(), ofGetMouseY(), 0));
	vs.push_back(vt);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	Vox vt;
	vt.setup(ofVec3f(ofGetMouseX(), ofGetMouseY(),0));
	vs.push_back(vt);
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
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch) {
	touchMap[touch.id] = touch;
}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch) {

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch) {
	touchMap.erase(touch.id);
}