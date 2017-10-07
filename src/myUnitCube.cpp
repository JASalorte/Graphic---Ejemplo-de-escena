#include "myUnitCube.h"

void myUnitCube::draw() 
{
	glPushMatrix();
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2d(0,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0.5,0.5,0);
		//glRectf(0.5,0,0,0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0.5);
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0.5,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0,0.5,0);
		//glRectf(0.5,0.5,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90,0,1,0);
	glBegin(GL_QUADS);
		glNormal3f(0,0,1);
		glTexCoord2d(0,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0.5,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0,0.5,0);
		//glRectf(0.5,0.5,0,0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5,0,0);
	glRotatef(-90,0,1,0);
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2d(0,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0.5,0.5,0);
		//glRectf(0.5,0,0,0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90,1,0,0);
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2d(0,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0.5,0.5,0);
		//glRectf(0.5,0,0,0.5);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0.5,0);
	glRotatef(90,1,0,0);
	glBegin(GL_QUADS);
		glNormal3f(0,0,-1);
		glTexCoord2d(0,0);
		glVertex3f(0.5,0,0);
		glTexCoord2d(1,0);
		glVertex3f(0,0,0);
		glTexCoord2d(1,1);
		glVertex3f(0,0.5,0);
		glTexCoord2d(0,1);
		glVertex3f(0.5,0.5,0);
		//glRectf(0.5,0,0,0.5);
	glEnd();
	glPopMatrix();





		

	// ---- END Primitive drawing section
}