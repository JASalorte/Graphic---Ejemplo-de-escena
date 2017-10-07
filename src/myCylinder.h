#ifndef MY_CYLINDER_H
#define MY_CYLINDER_H

#include "CGF/CGFobject.h"

class myCylinder: public CGFobject {

	int slices;
	double stacks; 
	bool smooth;

public:
	myCylinder(int slides, float stacks, bool smooth);
	void draw();
	

};

#endif