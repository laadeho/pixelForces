
#ifndef _VOX
#define _VOX
#include "ofMain.h"

class Vox {

    public:

    void setup();
	void setup(ofVec3f);
	void setup(ofVec3f, int);
	void update();
	void draw();
	void draw(ofVec3f, int, ofColor);

	Vox();
	
	ofVec3f v, pos;
	float g = 5;
	int nivelPiso;
	bool vive = true;
	int tam = 10;
	bool b3d;

	private: 

};
#endif