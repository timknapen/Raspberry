#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255,255,255);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	
	float frame = ofGetFrameNum()/2;
	float h = sinf( PI * (frame / 30) );
	
	ofSetColor((int)(10*frame) % 255,0,50);
	
	ofPushMatrix();
	{
		ofTranslate( (int)(frame * 10) % ofGetWidth(), ofGetHeight()/2 * (1 + h/2));
		ofEllipse(0, 0, 50, 50);
	}
	ofPopMatrix();
	
	ofSetColor(0);
	ofDrawBitmapString("Framerate: "+ofToString(ofGetFrameRate(), 0), 15, 15);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
	
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
void ofApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
	
}