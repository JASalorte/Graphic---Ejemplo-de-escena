#include "mytable.h"
#include "myUnitCube.h"
#include "CGFappearance.h"

myTable::myTable() {

	// Coefficients for material table
	float ambT[3] = { 0.8, 0.8, 0.8 };
	float difT[3] = { 0.58, 0.29, 0 };
	float specT[3] = { 0.2, 0.2, 0.2 };
	float shininessT = 10.f;

	// Coefficients for material chair
	float ambC[3] = { 0.2, 0.2, 0.2 };
	float difC[3] = { 0.87, 0.87, 0.85 };
	float specC[3] = { 0.8, 0.8, 0.8 };
	float shininessC = 120.f;

	materialWoods = new CGFappearance(ambT, difT, specT, shininessT);
	materialMetal = new CGFappearance(ambC, difC, specC, shininessC);
	tableAppearance = new CGFappearance("textures/table.png", GL_REPEAT,
			GL_REPEAT);
	MetalAppearance = new CGFappearance("textures/Metal.png", GL_REPEAT,
			GL_REPEAT);

}

void myTable::draw() {

	myUnitCube *perna[4];
	for (int i = 0; i < 4; ++i) {
		perna[i] = new myUnitCube();
	}

	myUnitCube *tampo = new myUnitCube();

	//Scale the 4 legs
	glPushMatrix();
	glScaled(0.3, 3.5, 0.3);
	glTranslated(0.5, 0, 0.5);
	materialMetal->apply();
	MetalAppearance->apply();
	perna[0]->draw();
	glTranslated(7, 0, 0);
	materialMetal->apply();
	MetalAppearance->apply();
	perna[1]->draw();
	glTranslated(0, 0, 3.5);
	materialMetal->apply();
	MetalAppearance->apply();
	perna[2]->draw();
	glTranslated(-7, 0, 0);
	materialMetal->apply();
	MetalAppearance->apply();
	perna[3]->draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, 1.75, 0);
	glScaled(5, 0.3, 3);
	materialWoods->apply();
	tableAppearance->apply();
	tampo->draw();
	glPopMatrix();

}
