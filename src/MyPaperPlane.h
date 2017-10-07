#ifndef MYPAPERPLANE_H_
#define MYPAPERPLANE_H_

#include "CGF/CGFobject.h"

class MyPaperPlane: public CGFobject {
	float x;
	float y;
	float z;
	float angle;
	int phase;

public:
	MyPaperPlane(float x, float y, float z);
	void draw();
	void update(long m);
	void setX (float x);
	void setY (float y);
	void setAngle(float angle);
};

#endif /* MYPAPERPLANE_H_ */
