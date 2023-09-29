#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255);
	ofSetLineWidth(1.5);
}
//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(120);
	ofTranslate(0, 0, -70);
	ofRotateZ(ofGetFrameNum());

	auto radius = 250;
	int deg_span = 3;

	auto target_deg = ofGetFrameNum() % 360;
	for (int deg = 0; deg < 360; deg += deg_span) {

		auto location = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0);
		auto len = ofMap(ofNoise(glm::vec4(location * 0.005, ofGetFrameNum() * 0.05)), 0, 1, -200, 200);

		auto location_1 = glm::vec3((radius + len * 0.65) * cos(deg * DEG_TO_RAD), (radius + len * 0.65) * sin(deg * DEG_TO_RAD), 0);
		auto location_2 = glm::vec3((radius - len * 0.65) * cos(deg * DEG_TO_RAD), (radius - len * 0.65) * sin(deg * DEG_TO_RAD), 0);

		ofDrawLine(location_1, location_2);
		ofDrawSphere(location_1, 3);
		ofDrawBox(location_2, 4);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}