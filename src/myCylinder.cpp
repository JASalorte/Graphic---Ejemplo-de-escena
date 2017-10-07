#include "myCylinder.h"
#include <math.h>

//Calcula el modulo de un vector  (longitud)
GLfloat Modulo(GLfloat x, GLfloat y, GLfloat z) {
	GLfloat len;

	len = x * x + y * y + z * z;
	return (sqrt(len));
}

//Normaliza el vector a mudulo 1
GLvoid Normaliza(GLfloat *x, GLfloat *y, GLfloat *z) {
	GLfloat len;

	len = Modulo(*x, *y, *z);
	len = 1.0 / len;
	(*x) *= len;
	(*y) *= len;
	(*z) *= len;
}

GLvoid CalculateVectorNormal(GLfloat fVert1[], GLfloat fVert2[],
		GLfloat fVert3[], GLfloat *fNormalX, GLfloat *fNormalY,
		GLfloat *fNormalZ) {
	GLfloat Qx, Qy, Qz, Px, Py, Pz;

	Qx = fVert2[0] - fVert1[0];
	Qy = fVert2[1] - fVert1[1];
	Qz = fVert2[2] - fVert1[2];
	Px = fVert3[0] - fVert1[0];
	Py = fVert3[1] - fVert1[1];
	Pz = fVert3[2] - fVert1[2];

	*fNormalX = Py * Qz - Pz * Qy;
	*fNormalY = Pz * Qx - Px * Qz;
	*fNormalZ = Px * Qy - Py * Qx;

}

struct face {
	GLfloat vector1[3];
	GLfloat vector2[3];
	GLfloat vector3[3];
};

struct face unidad;

myCylinder::myCylinder(int slice, float stack, bool smooth) {
	slices = slice;
	stacks = stack;
	this->smooth = smooth;
}

void myCylinder::draw() {
	GLfloat fNormalX, fNormalY, fNormalZ;

	double teta = (2 * acos(-1.0)) / slices;
	float increment = 1 / (slices * 1.0);
	float incrementAltu = 1 / stacks;
	float ini = 1;
	float alt = 0;

	float a, b, c, d;

	for (int i = 0; i < slices; i++) {
		for (int j = 0; j < stacks; ++j) {
			glBegin(GL_POLYGON);

			float CosAngleMin = cos(i * teta), StackMin = j / stacks,
					SinAngleMin = sin(i * teta), CosAngleMax = cos(
							(i + 1) * teta), StackMax = (j + 1) / stacks,
					SinAngleMax = sin((i + 1) * teta);

			if (smooth) {
				glNormal3f(CosAngleMin, 0, SinAngleMin);
			} else {
				unidad.vector1[0] = cos(0 * teta);
				unidad.vector1[1] = 0;
				unidad.vector1[2] = sin(0 * teta);

				unidad.vector2[0] = cos(1 * teta);
				unidad.vector2[1] = 0;
				unidad.vector2[2] = sin(1 * teta);

				unidad.vector3[0] = cos(1 * teta);
				unidad.vector3[1] = 1;
				unidad.vector3[2] = sin(1 * teta);

				CalculateVectorNormal(unidad.vector2, unidad.vector1,
						unidad.vector3, &fNormalX, &fNormalY, &fNormalZ);
				Normaliza(&fNormalX, &fNormalY, &fNormalZ);

				glNormal3f(fNormalX, fNormalY, fNormalZ);
			}

			a = ini - (i * increment);
			b = alt + (j * incrementAltu);
			c = alt + ((j + 1) * incrementAltu);
			d = ini - ((i + 1) * increment);

			glTexCoord2f(a, b);
			glVertex3f(CosAngleMin, StackMin, SinAngleMin);

			glTexCoord2f(a, c);
			glVertex3f(CosAngleMin, StackMax, SinAngleMin);

			//--

			glNormal3f(CosAngleMax, 0, SinAngleMax);

			glTexCoord2f(d, c);
			glVertex3f(CosAngleMax, StackMax, SinAngleMax);

			glTexCoord2f(d, b);
			glVertex3f(CosAngleMax, StackMin, SinAngleMax);

			glEnd();
		}
	}

	//La cara de abajo
	glBegin(GL_POLYGON);

	glNormal3f(0, -1, 0);

	for (int i = 0; i < slices; ++i) {
		c = cos(i * teta);
		d = sin(i * teta);

		a = (float) (0.5 + c / 2);
		b = (float) (0.5 + d / 2);

		glTexCoord2f(a, b);
		glVertex3f(c, 0, d);
	}

	glEnd();

	//La cara de arriba
	glBegin(GL_POLYGON);

	glNormal3f(0, 1, 0);

	for (int i = slices; i > 0; i--) {

		c = cos(i * teta);
		d = sin(i * teta);

		a = (float) (0.5 + c / 2);
		b = (float) (0.5 + d / 2);

		glTexCoord2f(b, a);
		glVertex3f(c, 1, d);
	}
	glEnd();

}