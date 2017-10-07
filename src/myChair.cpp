#include "myChair.h"
#include "myUnitCube.h"

myChair::myChair() {
	angle = -20 + (rand() % 41);
	transX = -0.25 + ((float) rand() / (float) RAND_MAX) * 0.5;
	transZ = -0.15 + ((float) rand() / (float) RAND_MAX);
}

void myChair::draw() {

	// Coefficients for material Woods
	float ambT[3] = {0.2, 0.2, 0.2};
	float difT[3] = {0.58, 0.29, 0};
	float specT[3] = {0.2, 0.2, 0.2};
	float shininessT = 120.f;

	// Coefficients for material Metal
	float ambC[3] = {0.2, 0.2, 0.2};
	float difC[3] = {0.87, 0.87, 0.85};
	float specC[3] = {0.8, 0.8, 0.8};
	float shininessC = 120.f;


	materialWoods = new CGFappearance(ambT,difT,specT,shininessT);
	materialMetal = new CGFappearance(ambC,difC,specC,shininessC);
	tableAppearance=new CGFappearance("textures/table.png",GL_REPEAT, GL_REPEAT);
	MetalAppearance=new CGFappearance("textures/Metal.png",GL_REPEAT, GL_REPEAT);

	myUnitCube *leg = new myUnitCube();
	myUnitCube *reposacu = new myUnitCube();
	myUnitCube *espaldar = new myUnitCube();
	myUnitCube *pernarespaldo = new myUnitCube();

	glTranslated(transX,0,transZ);
	glRotated(angle, 0, 1, 0);
	//Legs
	glPushMatrix();
	glTranslated(0.05, 0, 0.05);
	glScaled(0.3, 2, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	leg->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.05, 0, 0.05);
	glScaled(0.3, 2, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	leg->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 0, 1.05);
	glScaled(0.3, 2, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	leg->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.05, 0, 1.05);
	glScaled(0.3, 2, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	leg->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(1.05, 1.15, 1.05);
	glRotated(5, 1, 0, 0);
	glScaled(0.3, 2.5, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	pernarespaldo->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.05, 1.15, 1.05);
	glRotated(5, 1, 0, 0);
	glScaled(0.3, 2.5, 0.3);
	materialMetal->apply();
	MetalAppearance->apply();
	pernarespaldo->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0.2, 1.85, 1.175);
	glRotated(5, 1, 0, 0);
	glScaled(1.8, 1, 0.1);
	materialWoods->apply();
	tableAppearance->apply();
	espaldar->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1, 0);
	glScaled(2.5, 0.3, 2.5);
	materialWoods->apply();
	tableAppearance->apply();
	reposacu->draw();
	glPopMatrix();


}
