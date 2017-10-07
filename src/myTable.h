#ifndef MYTABLE_H
#define MYTABLE_H

#include "CGFobject.h"
#include "CGFappearance.h"

class myTable: public CGFobject {
	public:
	myTable();
		void draw();
		CGFappearance* materialWoods;
		CGFappearance* materialMetal;
		CGFappearance* tableAppearance;
		CGFappearance* MetalAppearance;
};

#endif
