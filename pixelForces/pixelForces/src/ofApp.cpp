#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	v.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
	v.update();
	for (auto &vt : vs) {
		vt.update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	v.draw();
	for (auto &vt : vs) {
		vt.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
