/*
 * MyRobot.h
 *
 *  Created on: 01/05/2014
 *      Author: Linkku
 */

#ifndef MYROBOT_H_
#define MYROBOT_H_

#include "CGF/CGFobject.h"
#include "CGFappearance.h"
#include <vector>

struct point {
	float x;
	float y;
	float z;
	point(float x1, float y1, float z1) :
			x(x1), y(y1), z(z1) {
	}
	point() :
			x(0), y(0), z(0) {
	}
	point(const point& a) {
		x = a.x;
		y = a.y;
		z = a.z;
	}

	point& operator=(const point& a) {
		x = a.x;
		y = a.y;
		z = a.z;
		return *this;
	}

	bool operator==(point a) const {
		if (a.x == x && a.y == y && a.z == z)
			return true;
		else
			return false;
	}
};

struct PolygonCGRA {
	point *polygonVertex;
	int size;
	PolygonCGRA(point p1, point p2, point p3, point p4) {
		size = 4;
		polygonVertex = new point[size];
		polygonVertex[0] = p1;
		polygonVertex[1] = p2;
		polygonVertex[2] = p3;
		polygonVertex[3] = p4;

	}
};

class MyRobot: public CGFobject {
public:
	MyRobot(float stack);
	void showMatrix();
	void turnLeft();
	void turnRight();
	void goFront();
	void goBack();
	void draw();
	int texture, mode;


private:
	int angle;
	float posX, posZ, stack;
	point **MVertex, **MNormal, **MTexture;
	CGFappearance* RobotAppearanceNormal, *RobotAppearance1, *RobotAppearance2;

};

#endif /* MYROBOT_H_ */
