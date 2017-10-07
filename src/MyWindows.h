/*
 * MyWindows.h
 *
 *  Created on: 04/05/2014
 *      Author: Linkku
 */

#ifndef MYWINDOWS_H_
#define MYWINDOWS_H_

#include "CGFobject.h"
#include "CGFappearance.h"

class MyWindows: public CGFobject {
public:
	MyWindows(float x1, float y1, float x2, float y2);
	void draw();

private:
	float x1, x2, y1, y2;
	CGFappearance* WindowsTexture, *border;

	float ejeX[4];
	float ejeY[4];

	float ejeTX[4];
	float ejeTY[4];
};

#endif /* MYWINDOWS_H_ */
