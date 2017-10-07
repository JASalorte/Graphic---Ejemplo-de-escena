#ifndef MYCHAIR_H
#define MYCHAIR_H

#include "CGFobject.h"
#include "CGFappearance.h"

class myChair: public CGFobject {
public:
	float angle;
	float transX, transZ;
	myChair();
	void draw();
	CGFappearance* materialWoods;
    CGFappearance* materialMetal;
	CGFappearance* tableAppearance;
	CGFappearance* MetalAppearance;
};

#endif