
#ifndef _VOX
#define _VOX
#include "ofMain.h"

class Vox {

    public:

    void setup();
	void setup(ofVec3f);
	void update();
	void draw();
	void draw(ofVec3f, int, ofColor);

	Vox();
	
	ofVec3f v, pos;
	float g;
	int nivelPiso;
	bool vive = true;

	private: 

};
#endif