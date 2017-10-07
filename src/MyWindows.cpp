/*
 * MyWindows.cpp
 *
 *  Created on: 04/05/2014
 *      Author: Linkku
 */

#include "MyWindows.h"
#include "MyRobot.h"
#include <iostream>

MyWindows::MyWindows(float x1, float y1, float x2, float y2) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;

	WindowsTexture = new CGFappearance("textures/wall.png", GL_REPEAT,
			GL_REPEAT);
	border = new CGFappearance("textures/window.png", GL_CLAMP, GL_CLAMP);

	ejeX[0] = 0;
	ejeX[1] = x1;
	ejeX[2] = x2;
	ejeX[3] = 1;

	ejeY[0] = 0;
	ejeY[1] = y1;
	ejeY[2] = y2;
	ejeY[3] = 1;

	ejeTX[0] = -(((x1 * 118) / (x2 - x1)) / 128);
	ejeTX[1] = 0.0390625;
	ejeTX[2] = 0.9609375;
	ejeTX[3] = 1 + ((((1 - x2) * 118) / (x2 - x1)) / 128);

	ejeTY[0] = -(((y1 * 76) / (y2 - y1)) / 128);
	ejeTY[1] = 0.0625;
	ejeTY[2] = 0.6640625;
	ejeTY[3] = 1 + ((((1 - y2) * 76) / (y2 - y1)) / 128);

}

void MyWindows::draw() {

	/*float ejeX[4] = { 0, x1, x2, 1 };
	float ejeY[4] = { 0, y1, y2, 1 };*/

	//float medio = (1 - x2 + x1) / 20;

	/*float ejeMX[4] = { x1, x1 + medio, x2 - medio, x2 };
	 float ejeMY[4] = { y1, y1 + medio, y2 - medio * 4, y2 };
	 float ejeTX[4] = { 0, medio, 1 - medio, 1 };
	 float ejeTY[4] = { 0, medio, 1 - medio * 10, 1 };*/

	/*float ejeTX[4] = { -(((x1 * 118) / (x2 - x1)) / 128), 0.0390625, 0.9609375,
			1 + ((((1 - x2) * 118) / (x2 - x1)) / 128) };
	float ejeTY[4] = { -(((y1 * 76) / (y2 - y1)) / 128), 0.0625, 0.6640625, 1
			+ ((((1 - y2) * 76) / (y2 - y1)) / 128) };*/

	border->apply();

	glNormal3f(0, 0, 1);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!((i == 1) && (j == 1))) {
				glBegin(GL_QUADS);

				//glTexCoord2f((j + 1) / 3.0, i / 3.0);
				glTexCoord2f(ejeTX[j + 1], ejeTY[i]);
				glVertex3f(ejeX[j + 1], ejeY[i], 0);

				//glTexCoord2f((j + 1) / 3.0, (i + 1) / 3.0);
				glTexCoord2f(ejeTX[j + 1], ejeTY[i + 1]);
				glVertex3f(ejeX[j + 1], ejeY[i + 1], 0);

				//glTexCoord2f((j) / 3.0, (i + 1) / 3.0);
				glTexCoord2f(ejeTX[j], ejeTY[i + 1]);
				glVertex3f(ejeX[j], ejeY[i + 1], 0);

				//glTexCoord2f((j) / 3.0, (i) / 3.0);
				glTexCoord2f(ejeTX[j], ejeTY[i]);
				glVertex3f(ejeX[j], ejeY[i], 0);
				glEnd();

			}
		}
	}

	/*

	 for (int i = 0; i < 3; i++) {
	 for (int j = 0; j < 3; j++) {
	 if (!((i == 1) && (j == 1))) {

	 glBegin(GL_QUADS);
	 glTexCoord2f(ejeTX[j + 1], ejeTY[i]);
	 glVertex3f(ejeMX[j + 1], ejeMY[i], 0);

	 glTexCoord2f(ejeTX[j + 1], ejeTY[i + 1]);
	 glVertex3f(ejeMX[j + 1], ejeMY[i + 1], 0);

	 glTexCoord2f(ejeTX[j], ejeTY[i + 1]);
	 glVertex3f(ejeMX[j], ejeMY[i + 1], 0);

	 glTexCoord2f(ejeTX[j], ejeTY[i]);
	 glVertex3f(ejeMX[j], ejeMY[i], 0);

	 glEnd();

	 }
	 }
	 }*/

}

