/*
 * MyRobot.cpp
 *
 *  Created on: 01/05/2014
 *      Author: Linkku
 */

#include "MyRobot.h"
#include <math.h>
#include <iostream>

#define PI 3.1415

using namespace std;

//Calcula el modulo de un vector  (longitud)
float Module(float x, float y, float z) {
	GLfloat len;

	len = x * x + y * y + z * z;
	return (sqrt(len));
}

//Normaliza el vector a mudulo 1
void Normalize(float *x, float *y, float *z) {
	GLfloat len;

	len = Module(*x, *y, *z);
	len = 1.0 / len;
	(*x) *= len;
	(*y) *= len;
	(*z) *= len;
}

point CalculateSurfaceNormal(PolygonCGRA poli) {
	point Normal = point(0, 0, 0);
	point Current, Next;

	for (int i = 0; i < poli.size; i++) {
		Current = poli.polygonVertex[i];
		Next = poli.polygonVertex[(i + 1) % poli.size];

		Normal.x += (Current.y - Next.y) * (Current.z + Next.z);
		Normal.y += (Current.z - Next.z) * (Current.x + Next.x);
		Normal.z += (Current.x - Next.x) * (Current.y + Next.y);
	}

	Normalize(&Normal.x, &Normal.y, &Normal.z);

	return Normal;
}

MyRobot::MyRobot(float stack) {
	this->stack = stack;
	angle = 45;
	posX = posZ = 0;
	texture = 0;
	mode = 0;

	RobotAppearanceNormal = new CGFappearance("textures/robot1.jpg", GL_CLAMP,
			GL_CLAMP);
	RobotAppearance1 = new CGFappearance("textures/Metal.png", GL_CLAMP,
			GL_CLAMP);
	RobotAppearance2 = new CGFappearance("textures/marmol.png", GL_CLAMP,
			GL_CLAMP);

	MVertex = new point*[(int) (stack + 1)];
	MNormal = new point*[(int) (stack + 1)];
	MTexture = new point*[(int) (stack + 1)];
	for (int i = 0; i < stack + 1; i++) {
		MVertex[i] = new point[12 + 1];
		MNormal[i] = new point[12 + 1];
		MTexture[i] = new point[12 + 1];
	}

	float pos[12] = { 0.5, 0.5, 0.5, 0.5, 0.16, -0.16, -0.5, -0.5, -0.5, -0.5,
			-0.16, 0.16 };

	double pi = acos(-1.0);
	double teta = (2 * pi) / 12;
	double correction = 45 * acos(-1.0) / 180;
	int j = 0;
	//Cuerpo del robot
	for (int i = 0; i < 12; i++) {
		float CosAngleMin = cos(i * teta + correction) * 0.25;
		float SinAngleMin = sin(i * teta + correction) * 0.25;
		float CosAngleMax = cos((i + 1) * teta + correction) * 0.25;
		float SinAngleMax = sin((i + 1) * teta + correction) * 0.25;

		float dif1 = (pos[(3 + i + 1) % 12] - CosAngleMax) / stack;
		float dif2 = (pos[(3 + i) % 12] - CosAngleMin) / stack;
		float dif3 = (pos[i] - SinAngleMin) / stack;
		float dif4 = (pos[(i + 1) % 12] - SinAngleMax) / stack;

		while (j < stack) {

			float StackMin = (j / stack) + 0.3;
			float StackMax = ((j + 1) / stack) + 0.3;

			int var1 = (stack - j);
			int var2 = (stack - j - 1);

			point ini = point();

			if (MVertex[j][i] == ini)
				MVertex[j][i] = point(var1 * dif2 + CosAngleMin, StackMin,
						var1 * dif3 + SinAngleMin);

			if (MVertex[j + 1][i] == ini)
				MVertex[j + 1][i] = point(var2 * dif2 + CosAngleMin, StackMax,
						var2 * dif3 + SinAngleMin);

			//--
			if (MVertex[j + 1][i + 1] == ini)
				MVertex[j + 1][i + 1] = point(var2 * dif1 + CosAngleMax,
						StackMax, var2 * dif4 + SinAngleMax);

			if (MVertex[j][i + 1] == ini)
				MVertex[j][i + 1] = point(var1 * dif1 + CosAngleMax, StackMin,
						var1 * dif4 + SinAngleMax);

			j++;
		}
		j = 0;
	}

	point NormalAux[(int) stack][12];

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < stack; j++) {
			NormalAux[j][i] = CalculateSurfaceNormal(
					PolygonCGRA(MVertex[j][i], MVertex[j + 1][i],
							MVertex[j + 1][i + 1], MVertex[j][i + 1]));
		}
	}

	/*for (int i = 0; i < 12; i++) {
	 for (int j = 0; j < stack; j++) {
	 std::cout << NormalAux[j][i].x << " " << NormalAux[j][i].y << " "
	 << NormalAux[j][i].z << std::endl;
	 }
	 cout << endl;
	 }*/

	j = 0;

	for (int i = 0; i < 13; i++) {
		while (j < stack + 1) {

			if (j == 0) {
				MNormal[j][i] = point(
						(NormalAux[j][(11 + i) % 12].x
								+ NormalAux[j][(11 + i + 1) % 12].x) / 2,
						(NormalAux[j][(11 + i) % 12].y
								+ NormalAux[j][(11 + i + 1) % 12].y) / 2,
						(NormalAux[j][(11 + i) % 12].z
								+ NormalAux[j][(11 + i + 1) % 12].z) / 2);
			}

			if (j == (int) stack) {
				MNormal[j][i] = point(
						(NormalAux[j - 1][(11 + i) % 12].x
								+ NormalAux[j - 1][(11 + i + 1) % 12].x) / 2,
						(NormalAux[j - 1][(11 + i) % 12].y
								+ NormalAux[j - 1][(11 + i + 1) % 12].y) / 2,
						(NormalAux[j - 1][(11 + i) % 12].z
								+ NormalAux[j - 1][(11 + i + 1) % 12].z) / 2);
			}

			if (j > 0 && j < (int) stack) {
				MNormal[j][i] = point(
						(NormalAux[j][(11 + i) % 12].x
								+ NormalAux[j][(11 + i + 1) % 12].x
								+ NormalAux[j - 1][(11 + i) % 12].x
								+ NormalAux[j - 1][(11 + i + 1) % 12].x) / 4,
						(NormalAux[j][(11 + i) % 12].y
								+ NormalAux[j][(11 + i + 1) % 12].y
								+ NormalAux[j - 1][(11 + i) % 12].y
								+ NormalAux[j - 1][(11 + i + 1) % 12].y) / 4,
						(NormalAux[j][(11 + i) % 12].z
								+ NormalAux[j][(11 + i + 1) % 12].z
								+ NormalAux[j - 1][(11 + i) % 12].z
								+ NormalAux[j - 1][(11 + i + 1) % 12].z) / 4);
			}
			j++;
		}
		j = 0;
	}

	j = 0;
	for (int i = 0; i < 13; i++) {
		while (j < stack + 1) {
			MTexture[j][i] = point(
					MVertex[j][(9 - i) >= 0 ? 9 - i : 12 - (i % 9)].x + 0.5, 0,
					MVertex[j][(9 - i) >= 0 ? 9 - i : 12 - (i % 9)].z + 0.5);
			j++;
		}
		j = 0;
	}

	//showMatrix();
}

void MyRobot::showMatrix() {
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < stack + 1; j++) {
			std::cout << MTexture[j][i].x << " " << MTexture[j][i].z
					<< std::endl;
		}
		cout << endl;
	}
}

void MyRobot::turnLeft() {
	angle = (angle + 5) % 360;
}

void MyRobot::turnRight() {
	angle = (angle - 5) % 360;
}

void MyRobot::goFront() {
	posX += sin(angle * M_PI / 180) * 0.2;
	posZ += cos(angle * M_PI / 180) * 0.2;
}

void MyRobot::goBack() {
	posX -= sin(angle * M_PI / 180) * 0.2;
	posZ -= cos(angle * M_PI / 180) * 0.2;
}

void MyRobot::draw() {

	glTranslatef(posX, 0, posZ);
	glRotatef(angle, 0, 1, 0); //+ es girar a izquierda

	if (mode == 1)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glNormal3f(0, -1, 0);

//Cara de abajo
	glBegin(GL_QUADS);
	glVertex3f(-0.5, 0.3, -0.5);
	glVertex3f(0.5, 0.3, -0.5);
	glVertex3f(0.5, 0.3, 0.5);
	glVertex3f(-0.5, 0.3, 0.5);
	glEnd();

	float c, d;
	double pi = acos(-1.0);
	double teta = (2 * pi) / 12;
	double correction = 45 * pi / 180;

	if (texture == 0)
		RobotAppearanceNormal->apply();

	if (texture == 1)
		RobotAppearance1->apply();

	if (texture == 2)
		RobotAppearance2->apply();

//La cara de arriba
	/*glBegin(GL_POLYGON);

	glNormal3f(0, 1, 0);

	for (int i = 12; i > 0; i--) {

		c = cos((i * teta) + correction) * 0.25;
		d = sin((i * teta) + correction) * 0.25;

		a = (float) (0.5 + c);
		b = (float) (0.5 + d);

		glTexCoord2f(a, b);
		glVertex3f(c, 1.3, d);
	}
	glEnd();*/

	int j = 0;

	glBegin(GL_POLYGON);

	glNormal3f(0, 1, 0);


	for (int i = 12; i > 0; i--) {

		c = cos((i * teta) + correction) * 0.25;
		d = sin((i * teta) + correction) * 0.25;

		glTexCoord2f(cos((j * teta) + 315 * pi / 180) * 0.25 + 0.5, sin((j * teta) + 315 * pi / 180) * 0.25 + 0.5);
		glVertex3f(c, 1.3, d);
		j++;
	}
	glEnd();

	j = 0;

//Cuerpo del robot
	for (int i = 0; i < 12; i++) {
		while (j < stack) {

			glBegin(GL_POLYGON);

			glNormal3f(MNormal[j][i].x, MNormal[j][i].y, MNormal[j][i].z);
			glTexCoord2f(MTexture[j][i].x, MTexture[j][i].z);
			glVertex3f(MVertex[j][i].x, MVertex[j][i].y, MVertex[j][i].z);

			glNormal3f(MNormal[j + 1][i].x, MNormal[j + 1][i].y,
					MNormal[j + 1][i].z);
			glTexCoord2f(MTexture[j + 1][i].x, MTexture[j + 1][i].z);
			glVertex3f(MVertex[j + 1][i].x, MVertex[j + 1][i].y,
					MVertex[j + 1][i].z);

			glNormal3f(MNormal[j + 1][i + 1].x, MNormal[j + 1][i + 1].y,
					MNormal[j + 1][i + 1].z);
			glTexCoord2f(MTexture[j + 1][i + 1].x, MTexture[j + 1][i + 1].z);
			glVertex3f(MVertex[j + 1][i + 1].x, MVertex[j + 1][i + 1].y,
					MVertex[j + 1][i + 1].z);

			glEnd();

			glBegin(GL_POLYGON);

			glNormal3f(MNormal[j + 1][i + 1].x, MNormal[j + 1][i + 1].y,
					MNormal[j + 1][i + 1].z);
			glTexCoord2f(MTexture[j + 1][i + 1].x, MTexture[j + 1][i + 1].z);
			glVertex3f(MVertex[j + 1][i + 1].x, MVertex[j + 1][i + 1].y,
					MVertex[j + 1][i + 1].z);

			glNormal3f(MNormal[j][i + 1].x, MNormal[j][i + 1].y,
					MNormal[j][i + 1].z);
			glTexCoord2f(MTexture[j][i + 1].x, MTexture[j][i + 1].z);
			glVertex3f(MVertex[j][i + 1].x, MVertex[j][i + 1].y,
					MVertex[j][i + 1].z);

			glNormal3f(MNormal[j][i].x, MNormal[j][i].y, MNormal[j][i].z);
			glTexCoord2f(MTexture[j][i].x, MTexture[j][i].z);
			glVertex3f(MVertex[j][i].x, MVertex[j][i].y, MVertex[j][i].z);

			glEnd();

			/*glNormal3f(MNormal[j][i + 1].x, MNormal[j][i + 1].y,
			 MNormal[j][i + 1].z);
			 glTexCoord2f(MTexture[j][i + 1].x, MTexture[j][i + 1].z);
			 glVertex3f(MVertex[j][i + 1].x, MVertex[j][i + 1].y,
			 MVertex[j][i + 1].z);*/

			j++;
		}
		j = 0;
	}
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

