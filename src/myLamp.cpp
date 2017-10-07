#include "myLamp.h"
#include <math.h>

myLamp::myLamp(int slice, double stack, double radio, bool inverse) {
	slices = slice;
	stacks = stack * 2;
	radius = radio;
	inv = inverse;
}

void myLamp::draw() {

	double PI = acos(-1.0);

	float X1, Y1, X2, Y2, Z1, Z2;
	float inc1, inc2, inc3, inc4, Radius1, Radius2;
	int radius = 1;

	for (int i = 0; i < slices; i++) {
		for (int j = 0; j < (stacks / 2); j++) {

			inc1 = (i / (float) slices) * 2 * PI;
			inc2 = ((i + 1) / (float) slices) * 2 * PI;

			inc3 = (j / (float) stacks) * PI;
			inc4 = ((j + 1) / (float) stacks) * PI;

			X1 = sin(inc1);
			Y1 = cos(inc1);
			X2 = sin(inc2);
			Y2 = cos(inc2);

			Radius1 = radius * cos(inc3);
			Radius2 = radius * cos(inc4);

			Z1 = radius * sin(inc3);
			Z2 = radius * sin(inc4);
			if (inv) {
				glBegin(GL_POLYGON);
				glNormal3f(-X2, -Z1, -Y2);
				glVertex3f(Radius1 * X2, Z1, Radius1 * Y2);
				glNormal3f(-X2, -Z2, -Y2);
				glVertex3f(Radius2 * X2, Z2, Radius2 * Y2);
				glNormal3f(-X1, -Z2, -Y1);
				glVertex3f(Radius2 * X1, Z2, Radius2 * Y1);
				glNormal3f(-X1, -Z1, -Y1);
				glVertex3f(Radius1 * X1, Z1, Radius1 * Y1);
				glEnd();
			} else {
				glBegin(GL_POLYGON);
				glNormal3f(X2, Z1, Y2);
				glVertex3f(Radius1 * X2, Z1, Radius1 * Y2);
				glNormal3f(X2, Z2, Y2);
				glVertex3f(Radius2 * X2, Z2, Radius2 * Y2);
				glNormal3f(X1, Z2, Y1);
				glVertex3f(Radius2 * X1, Z2, Radius2 * Y1);
				glNormal3f(X1, Z1, Y1);
				glVertex3f(Radius1 * X1, Z1, Radius1 * Y1);
				glEnd();
			}

		}

	}

	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	for (int i = 0; i < slices; ++i) {
		glVertex3f(radius * cos(i * 2 * PI / slices), 0,
				radius * sin(i * 2 * PI / slices));
	}

	glEnd();
}