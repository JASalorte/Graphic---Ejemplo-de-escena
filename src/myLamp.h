#ifndef MYLAMP_H_
#define MYLAMP_H_

#include "CGF/CGFobject.h"

class myLamp: public CGFobject {
	int slices;
	double stacks, radius;
	bool inv;
public:
	myLamp(int slice, double stack, double radio, bool inverse);
	void draw();
};

#endif /* MYLAMP_H_ */