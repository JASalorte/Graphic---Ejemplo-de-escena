#include "ExampleObject.h"

void ExampleObject::draw() 
{
		// ---- BEGIN Primitive drawing section

    // NOTE: the visible face of the polygon is determined by the order of the vertices

	glBegin(GL_QUADS);
		glVertex3d(0,0,0);
		glVertex3d(4,0,0);
		glVertex3d(4,3,0);
		glVertex3d(0,3,0);
	glEnd();

	glBegin( GL_TRIANGLES );
		glVertex3d(-1,3,0);
		glVertex3d(5,3,0);
		glVertex3d(2,4,0);
	glEnd() ;

	// ---- END Primitive drawing section
}