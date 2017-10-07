#include "myFloor.h"
#include "myUnitCube.h"

void myFloor::draw() 
{
	myUnitCube chao;
	//suelo
	glPushMatrix();
	glScalef(8,0.1,6);
	chao.draw();
	glPopMatrix();

}