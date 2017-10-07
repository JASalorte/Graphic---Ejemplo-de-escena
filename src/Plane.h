#pragma once

#include "CGF/CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int n, float si, float ti, float sf, float tf);
	~Plane(void);
	void draw();
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
	float si, ti, sf, tf;
};

