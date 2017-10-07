#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "myChair.h"
#include "Plane.h"
#include "myCylinder.h"
#include "myLamp.h"
#include "myClock.h"
#include "MyRobot.h"
#include "MyPaperPlane.h"
#include "MyWindows.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void update(long millis);
	void toggleSomething();
	void turnRobot(bool dir);
	void goRobot(bool dir);
	void changeLight();
	void pauseClockFun();
	void resetClock();
	void drawImpostor();

	int sceneVar;
	int lampSwitch, switch1,switch2,switch3;
	bool pauseClock;

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;

	myTable* table;
	myChair* chair[2];
	myCylinder* cilinder;
	myCylinder* cilinder2;
	myClock* clock;
	myLamp* lamp;
	MyRobot* robot;
	MyWindows* windowsWall;
	MyPaperPlane* aircraft;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	Plane* boardC;
	Plane* floor;
	CGFappearance* materialA;
	CGFappearance* materialB;
	CGFappearance* materialFloor;
	CGFappearance* materialWall;
	CGFappearance* materialCilinder;
	CGFappearance* materialLamp;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* MarmolAppearance;
	CGFappearance* wallAppearance;
	CGFappearance* impostorAppearance;
	  

	~LightingScene();
};

#endif
