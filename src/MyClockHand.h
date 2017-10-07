#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_

#include "CGF/CGFobject.h"

class MyClockHand: public CGFobject {
	float angle;
	int type;
public:
	MyClockHand(int type);
	void draw();
	void setAngle(float angle);
};

#endif /* MYCLOCKHAND_H_ */
