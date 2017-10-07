#include "MyPaperPlane.h"

MyPaperPlane::MyPaperPlane(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
	phase = 0;
	angle = 15;
}
void MyPaperPlane::setX(float x) {
	this->x += x;
}

void MyPaperPlane::setY(float y) {
	this->y += y;
}

void MyPaperPlane::setAngle(float angle) {
	this->angle += angle;
}

void MyPaperPlane::update(long m) {
	switch (phase) {
	case 0:
		if (x > 4.8)
			setX(-0.05);
		else
			phase = 1;
		break;
	case 1:
		if (x > 0.4) {
			if (x > 4) {
				setAngle(1);
				setY(-0.01);
			}
			if (x < 4.5 && x > 2.5) {
				if (angle > 0)
					setAngle(-0.6);
				setY(-0.005);
			}

			if (x < 2.5) {
				setAngle(-1);
				setY(0.010);
			}
			if (x < 1.5) {
				setY(0.015);
			}
			setX(-0.05);
		} else {
			phase = 2;
		}
		break;
	case 2:
		if (x > 0.2) {
			setAngle(-6);
			setX(-0.025);
			setY(0.01);
		} else {
			phase = 3;
		}
		break;
	case 3:
		if (y > 0.2) {
			setY(-0.15);
		}
		if (angle > -180) {
			setAngle(-6);
		}
		if (x < 0.3) {
			setX(0.025);
		}

		break;

	}
}

void MyPaperPlane::draw() {

	glPushMatrix();

	glTranslatef(x, y, z);
	glRotatef(90, -1, 0, 0);
	glRotatef(90, 0, 0, -1);
	glRotatef(angle, 1, 0, 0);
	glScaled(0.3, 0.3, 0.3);

	glNormal3f(0, 0, -1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -1, 0);
	glVertex3f(-1, 0.8, 0);
	glVertex3f(-0.2, 1, 0);
	glEnd();

	glNormal3f(0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1, 0.8, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(-0.2, 1, 0);
	glEnd();

	glNormal3f(0, 0, 1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -1, 0);
	glVertex3f(1, 0.8, 0);
	glVertex3f(0.2, 1, 0);
	glEnd();

	glNormal3f(0, 0, -1);
	glBegin(GL_TRIANGLES);
	glVertex3f(1, 0.8, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(0.2, 1, 0);
	glEnd();

	glNormal3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -1, 0);
	glVertex3f(0.2, 1, 0);
	glVertex3f(0, 0.8, -0.5);
	glEnd();

	glNormal3f(-1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.2, 1, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(0, 0.8, -0.5);
	glEnd();

	glNormal3f(-1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -1, 0);
	glVertex3f(-0.2, 1, 0);
	glVertex3f(0, 0.8, -0.5);
	glEnd();

	glNormal3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.2, 1, 0);
	glVertex3f(0, -1, 0);
	glVertex3f(0, 0.8, -0.5);
	glEnd();

	glPopMatrix();

}
