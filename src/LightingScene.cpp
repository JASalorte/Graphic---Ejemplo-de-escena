#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myChair.h"
#include "myCylinder.h"
#include "myLamp.h"

#include "CGFappearance.h"

#include <math.h>

float pi = acos(-1.0);
float deg2rad = pi / 180.0;

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
//float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light0_pos[4] = { 9, 6.5, 8.5, 1.0 };
//float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};
float light1_pos[4] = { 0, 4.5, 7.5, 1.0 };

float light2_pos[4] = { 10.5, 6.0, 5.0, 1.0 };
float light3_pos[4] = { 4, 6.0, 5.0, 1.0 };

// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4] = { 0, 0, 0, 0 };

// number of divisions
#define BOARD_A_DIVISIONS 30
#define BOARD_B_DIVISIONS 100
#define BOARD_C_DIVISIONS 120
#define floor_DIVISIONS  40

// Coefficients for material A
float ambA[3] = { 0.2, 0.2, 0.2 };
float difA[3] = { 0.6, 0.6, 0.6 };
float specA[3] = { 0, 0.8, 0.8 };
float shininessA = 10.f;

// Coefficients for material B
float ambB[3] = { 0.2, 0.2, 0.2 };
float difB[3] = { 0.6, 0.6, 0.6 };
float specB[3] = { 0.8, 0.8, 0.8 };
float shininessB = 120.f;

// Coefficients for material Floor
float ambF[3] = { 0.2, 0.2, 0.2 };
float difF[3] = { 0.95, 0.90, 1 };
float specF[3] = { 0.25, 0.1, 0.1 };
float shininessF = 120.f;

// Coefficients for material Wall
float ambW[3] = { 0.2, 0.2, 0.2 };
float difW[3] = { 0.80, 0.87, 0.85 };
float specW[3] = { 0.5, 0.75, 0.75 };
float shininessW = 120.f;

// Coefficients for material cilinder
float ambCI[3] = { 0.2, 0.2, 0.2 };
float difCI[3] = { 0.72, 0.57, 0.35 };
float specCI[3] = { 0.5, 0.25, 0.25 };
float shininessCI = 120.f;

// Coefficients for material lamp
float ambL[3] = { 0.2, 0.2, 0.2 };
float difL[3] = { 0.63, 0.83, 0.81 };
float specL[3] = { 1, 1, 1 };
float shininessL = 30.f;

float ambientNull[4] = { 0, 0, 0, 1 };
float yellow[4] = { 1, 1, 0, 1 };

void LightingScene::init() {
	// Enables lighting computations
	glEnable(GL_LIGHTING);

	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);

	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);

	//enable/disable smooth
	//glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH);

	// Declares and enables two lights, with null ambient component

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);
	light0->setSpecular(yellow);

	light0->enable();
	light0->disable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);

	//light1->disable();
	light1->enable();

	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	light2->setKq(0);
	light2->setKl(1);

	//light2->disable();
	light2->enable();

	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(0);
	light3->setKq(0);
	light3->setKl(1);

	//light3->disable();
	light3->enable();
	// Uncomment below to enable normalization of lighting normal vectors
	glEnable(GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	aircraft = new MyPaperPlane(6.5, 2, 8.5);
	robot = new MyRobot(5);
	windowsWall = new MyWindows(0.4, 0.4, 0.6, 0.7);
	cilinder = new myCylinder(8, 2.0, true);
	cilinder2 = new myCylinder(8, 2.0, false);
	clock = new myClock(12, 1, true);
	lamp = new myLamp(16, 8, 1, true);
	chair[0] = new myChair();
	chair[1] = new myChair();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS, 0, 0, 1, 1);
	boardB = new Plane(BOARD_B_DIVISIONS, 0, 0, 1, 1.29);
	boardC = new Plane(BOARD_C_DIVISIONS, -1, -1, 2, 2);
	floor = new Plane(floor_DIVISIONS, 0, 0, 10, 12);

	//Declares materials
	materialA = new CGFappearance(ambA, difA, specA, shininessB);
	materialB = new CGFappearance(ambB, difB, specB, shininessB);
	materialFloor = new CGFappearance(ambF, difF, specF, shininessF);
	materialWall = new CGFappearance(ambW, difW, specW, shininessW);
	materialCilinder = new CGFappearance(ambCI, difCI, specCI, shininessCI);
	materialLamp = new CGFappearance(ambL, difL, specL, shininessL);
	slidesAppearance = new CGFappearance("textures/slides.png", GL_REPEAT,
			GL_REPEAT);
	boardAppearance = new CGFappearance("textures/board.png", GL_CLAMP,
			GL_CLAMP);
	windowAppearance = new CGFappearance("textures/window.png", GL_CLAMP,
			GL_CLAMP);
	floorAppearance = new CGFappearance("textures/floor.png", GL_REPEAT,
			GL_REPEAT);
	MarmolAppearance = new CGFappearance("textures/marmol.png", GL_REPEAT,
			GL_REPEAT);
	wallAppearance = new CGFappearance("textures/wall.png", GL_REPEAT,
			GL_REPEAT);
	impostorAppearance = new CGFappearance("textures/impostor.png", GL_CLAMP,
			GL_CLAMP);

	//update 
	setUpdatePeriod(100);

	sceneVar = lampSwitch = switch1 = switch2 = switch3 = 0;
	pauseClock = false;

}

void LightingScene::toggleSomething() {

}

void LightingScene::pauseClockFun() {
	clock->setInitialTime(0);
	clock->saveState();
}

void LightingScene::resetClock() {
	clock->reset();
}

void LightingScene::turnRobot(bool dir) {
	if (dir)
		robot->turnLeft();
	else
		robot->turnRight();
}

void LightingScene::goRobot(bool dir) {
	if (dir)
		robot->goFront();
	else
		robot->goBack();
}

void LightingScene::update(long millis) {
	if (!pauseClock) {
		clock->update(millis);
	}
	//aircraft->update(millis);
}

void LightingScene::drawImpostor() {
	glPushMatrix();

	impostorAppearance->apply();
	glNormal3f(1, 0, 0);

	glBegin(GL_QUADS);

	glTexCoord2f(1, 0);
	glVertex3f(-10, -4, -8);
	glTexCoord2f(1, 1);
	glVertex3f(-10, 12, -8);
	glTexCoord2f(0, 1);
	glVertex3f(-10, 12, 23);
	glTexCoord2f(0, 0);
	glVertex3f(-10, -4, 23);

	glEnd();

	glPopMatrix();

}

void LightingScene::display() {

	// ---- BEGIN Background, camera and axis setup

	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	if (lampSwitch == 0) {
		light0->enable();
	} else {
		light0->disable();
	}

	if (switch1 == 0) {
		light1->enable();
	} else {
		light1->disable();
	}

	if (switch2 == 0) {
		light2->enable();
	} else {
		light2->disable();
	}

	if (switch3 == 0) {
		light3->enable();
	} else {
		light3->disable();
	}

	//light0->draw();
	//light1->draw();
	//light2->draw();
	//light3->draw();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//glTranslated(7.25, 5, 5);

	/*glPushMatrix();
	 aircraft->draw();
	 glPopMatrix();*/

	//Robot
	glPushMatrix();
	glTranslated(7.5, 0, 7.5);
	glRotatef(180, 0, -1, 0);
	robot->draw();
	glPopMatrix();

	drawImpostor();

	//Windows
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslated(-15, 0, 0);
	glScaled(15, 8, 1);
	windowsWall->draw();
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//lamp
	glPushMatrix();
	 glTranslated(9, 7, 8);
	 glRotatef(180, 0, 0, 1);
	 materialLamp->apply();
	 lamp->draw();
	 glPopMatrix();

	 //cilinders
	 glPushMatrix();
	 glTranslated(3, 0, 8);
	 glScaled(1, 4, 1);
	 materialCilinder->apply();
	 MarmolAppearance->apply();
	 cilinder->draw();
	 glPopMatrix();

	/*glPushMatrix();
	 glTranslated(10, 0, 4);
	 glScaled(1, 4, 1);
	 materialCilinder->apply();
	 MarmolAppearance->apply();
	 cilinder2->draw();
	 glPopMatrix();*/

	//clock
	glPushMatrix();
	glTranslated(7.25, 8, 0.25);
	materialWall->apply();
	clock->draw();
	glPopMatrix();

	//First Table
	glPushMatrix();
	 glTranslated(3, 0, 12);
	 table->draw();
	 //glTranslated(0.8, 0, 0.5);
	 //chair[0]->draw();
	 glPopMatrix();

	//Second Table
	/* glPushMatrix();
	 glTranslated(12, 0, 8);
	 table->draw();
	 glTranslated(0.8, 0, 0.5);
	 chair[1]->draw();
	 glPopMatrix();*/

	//Floor
	glPushMatrix();
	 glTranslated(7.5, 0, 7.5);
	 glScaled(15, 0.2, 15);
	 materialFloor->apply();
	 floorAppearance->apply();
	 floor->draw();
	 glPopMatrix();

	//LeftWall
	/*glPushMatrix();
	 glTranslated(0, 4, 7.5);
	 glRotated(-90.0, 0, 0, 1);
	 glScaled(8, 0.2, 15);
	 materialWall->apply();
	 glRotatef(90, 0, 1, 0);
	 windowAppearance->apply();
	 boardC->draw();
	 glPopMatrix();*/

	 //PlaneWall
	 glPushMatrix();
	 glTranslated(7.5, 4, 0);
	 glRotated(90.0, 1, 0, 0);
	 glScaled(15, 0.2, 8);
	 materialWall->apply();
	 wallAppearance->apply();
	 wall->draw();
	 glPopMatrix();

	 // Board A
	 glPushMatrix();
	 glTranslated(4, 4, 0.2);
	 glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	 glRotated(90.0, 1, 0, 0);
	 materialA->apply();
	 slidesAppearance->apply();
	 boardA->draw();
	 glPopMatrix();

	 //PlaneB
	 glPushMatrix();
	 glTranslated(10.5, 4, 0.2);
	 glScaled(BOARD_WIDTH, BOARD_HEIGHT, 1);
	 glRotated(90.0, 1, 0, 0);
	 materialB->apply();
	 boardAppearance->apply();
	 boardB->draw();
	 glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// ---- END Primitive drawing section
	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() {
	delete (light0);
	delete (light1);
	delete (table);
	delete (cilinder);
	delete (cilinder2);
	delete (lamp);
	delete (clock);
	delete (chair[0]);
	delete (chair[1]);
	delete (wall);
	delete (floor);
	delete (boardA);
	delete (boardB);
	delete (boardC);
	delete (materialA);
	delete (materialB);
	delete (boardAppearance);
	delete (slidesAppearance);
	delete (windowAppearance);

}
