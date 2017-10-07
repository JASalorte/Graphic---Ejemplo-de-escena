#include "TPinterface.h"
#include "LightingScene.h"

TPinterface::TPinterface() {
	testVar = 0;
}

void TPinterface::processKeyboard(unsigned char key, int x, int y) {
	// Uncomment below if you would like to process the default keys (e.g. 's' for snapshot, 'Esc' for exiting, ...)
	// CGFinterface::processKeyboard(key, x, y);

	switch (key) {
	case 'a': {
		// This is an example of accessing the associated scene
		// To test, create the function toggleSomething in your scene to activate/deactivate something
		((LightingScene *) scene)->toggleSomething();
		break;
	}
	case 'j': {
		((LightingScene *) scene)->turnRobot(true);
		break;
	}
	case 'l': {
		((LightingScene *) scene)->turnRobot(false);
		break;
	}
	case 'i': {
		((LightingScene *) scene)->goRobot(true);
		break;
	}
	case 'k': {
		((LightingScene *) scene)->goRobot(false);
		break;
	}
	}
}

void TPinterface::initGUI() {
	// Check CGFinterface.h and GLUI documentation for the types of controls available
	GLUI_Panel *varPanel1, *varPanel2, *varPanel3, *varPanel4;

	/*varPanel = addPanel("Group", 1);
	 addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	 // You could also pass a reference to a variable from the scene class, if public
	 addSpinnerToPanel(varPanel, "Val 2(scene)", 2,
	 &(((LightingScene*) scene)->sceneVar), 2);*/

	varPanel1 = addPanel("Luzes", 1);
	addCheckboxToPanel(varPanel1, "Lamp",
			&(((LightingScene*) scene)->lampSwitch), 1);
	addCheckboxToPanel(varPanel1, "Light 1",
			&(((LightingScene*) scene)->switch1), 2);
	addCheckboxToPanel(varPanel1, "Light 2",
			&(((LightingScene*) scene)->switch2), 3);
	addCheckboxToPanel(varPanel1, "Light 3",
			&(((LightingScene*) scene)->switch3), 4);

	addColumn();

	varPanel2 = addPanel("Relogio", 1);
	addButtonToPanel(varPanel2, "Pause", 6);
	addButtonToPanel(varPanel2, "Restart", 7);

	addColumn();

	varPanel3 = addPanel("Robot", 1);
	GLUI_Listbox* listBox = addListboxToPanel(varPanel3, "Textures",
			&(((LightingScene*) scene)->robot->texture), 8);

	listBox->add_item(0, "Basic Texture");
	listBox->add_item(1, "Metal");
	listBox->add_item(2, "Marble");

	addColumn();

	varPanel4 = addPanel("Robot Mode", 1);
	GLUI_RadioGroup* radioGroup = addRadioGroupToPanel(varPanel4, &(((LightingScene*) scene)->robot->mode), 9);

	addRadioButtonToGroup(radioGroup, "Textured");
	addRadioButtonToGroup(radioGroup, "Wireframe");

	//GLUI_Listbox *GLUI::add_listbox_to_panel(varPanel3, "Basic Texture", &testVar, 8, GLUI_Listbox::get_int_val());

	//addSpinnerToPanel(varPanel, "Val 1(interface)", 2, &testVar, 1);

	// You could also pass a reference to a variable from the scene class, if public
	//addSpinnerToPanel(varPanel, "Val 2(scene)", 2,&(((LightingScene*) scene)->sceneVar), 2);

}

void TPinterface::processGUI(GLUI_Control *ctrl) {
	printf("GUI control id: %d\n  ", ctrl->user_id);
	switch (ctrl->user_id) {
	case 1: {
		//((LightingScene*) scene)->changeLight();
		if (((LightingScene*) scene)->lampSwitch == 1)
			printf("Lamp turn on\n");
		else
			printf("Lamp turn off\n");
		break;
	}

	case 2: {
		//((LightingScene*) scene)->changeLight();
		if (((LightingScene*) scene)->switch1 == 1)
			printf("Light 1 turn on\n");
		else
			printf("Light 1 turn off\n");
		break;
	}

	case 3: {
		//((LightingScene*) scene)->changeLight();
		if (((LightingScene*) scene)->switch2 == 1)
			printf("Light 2 turn on\n");
		else
			printf("Light 2 turn off\n");
		break;
	}

	case 4: {
		//((LightingScene*) scene)->changeLight();
		if (((LightingScene*) scene)->switch3 == 1)
			printf("Light 3 turn on\n");
		else
			printf("Light 3 turn off\n");
		break;
	}

	case 6: {
		if (((LightingScene*) scene)->pauseClock) {
			((LightingScene*) scene)->pauseClock = false;
			printf("Clock continues\n");
		} else {
			((LightingScene*) scene)->pauseClock = true;
			((LightingScene*) scene)->pauseClockFun();
			printf("Clock pauses\n");
		}
		break;
	}

	case 7: {
		((LightingScene*) scene)->resetClock();
		printf("Clock reset\n");
		break;
	}

	case 8: {
		printf("Texture: %d\n", testVar);
		break;
	}

	case 9: {
		printf("Mode: %d\n", testVar);
		break;
	}

	};
}

