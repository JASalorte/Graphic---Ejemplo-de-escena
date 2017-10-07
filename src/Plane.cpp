#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	this->si = 0;
		this->sf = 1;
		this->ti = 0;
		this->tf = 1;
	_numDivisions = 1;
}

Plane::Plane(int n, float si, float ti, float sf, float tf)
{
	this->si = si;
	this->sf = sf;
	this->ti = ti;
	this->tf = tf;
	_numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	float Sincrement, Tincrement;
	Sincrement = (sf-si) * 1.0 / _numDivisions;
	Tincrement = (tf-ti) * 1.0 / _numDivisions;

	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);
		int bz = 0;

		float a, b;

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				a = si + Sincrement * bx;
				glTexCoord2f(a, 0);
				glVertex3f(bx, 0, 0);
				for (bz = 0; bz<_numDivisions; bz++)
				{
					a = si + Sincrement * (bx + 1);
					b = ti + Tincrement * (bz);
					glTexCoord2f(a, b);
					glVertex3f(bx + 1, 0, bz);
					a = si + Sincrement * (bx);
					b = ti + Tincrement * (bz + 1);
					glTexCoord2f(a , b);
					glVertex3f(bx, 0, bz + 1);
				}
				a = si + Sincrement * (bx + 1);
				glTexCoord2f(a, 1);
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}
