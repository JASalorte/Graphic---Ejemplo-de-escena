#ifndef MY_CLOCK_H
#define MY_CLOCK_H

#include "CGF/CGFobject.h"
#include "CGFappearance.h"
#include "MyClockHand.h"

class myClock: public CGFobject {

	int slices;
	double stacks;
	bool smooth;
	long initialTime, startState, dif;
	CGFappearance* clockAppearance;
	CGFappearance* clockborderAppearance;
	CGFappearance* clockbackAppearance;
	MyClockHand* seconds;
	MyClockHand* minutes;
	MyClockHand* hours;
	CGFappearance* material;

public:
	myClock(int slides, float stacks, bool smooth);
	void update(long m);
	void saveState();
	void reset();
	void draw();
	void pause();

	void setInitialTime(long initialTime) {
		this->initialTime = initialTime;
	}
};
#endif
