#include "MyClockHand.h"

MyClockHand::MyClockHand(int type) {
	// TODO Auto-generated constructor stub
	angle = 0;
	this->type = type;
}

void MyClockHand::setAngle(float angle) {
	this->angle = angle;
}

void MyClockHand::draw() {

	glPushMatrix();

	glRotatef(angle, 0, 0, -1);

	if (type == 0)
			glScalef(0.5, 0.9, 1);

	if (type == 1)
		glScalef(0.6, 0.8, 1);

	if (type == 2)
		glScalef(0.2, 1, 0.5);

	glNormal3f(-1, 1, 1);

	//Larga izquierda
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.15, 0, 0);
	glVertex3f(0, 0, 0.1);
	glVertex3f(0, 1, 0);
	glEnd();

	glNormal3f(1, 1, 1);

	//Larga derecha
	glBegin(GL_TRIANGLES);
	glVertex3f(0, 0, 0.1);
	glVertex3f(0.15, 0, 0);
	glVertex3f(0, 1, 0);
	glEnd();

	glNormal3f(-1, -1, 1);

	//Corta izquierda
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0, 0, 0.1);
	glVertex3f(-0.15, 0, 0);
	glEnd();

	glNormal3f(1, -1, 1);

	//Corta derecha
	glBegin(GL_TRIANGLES);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0.15, 0, 0);
	glVertex3f(0, 0, 0.1);
	glEnd();

	//Reverso
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);
	glVertex3f(0, 1, 0);
	glVertex3f(0.2, 0, 0);
	glVertex3f(0, -0.2, 00);
	glVertex3f(-0.2, 0, 0);
	glEnd();

	glRotatef(angle, 0, 0, 1);

	glPopMatrix();
}
