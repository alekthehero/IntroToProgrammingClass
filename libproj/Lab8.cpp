#include "library.h"
#include "MainTester.h"

int const SCALE = 1;

void Lab8() {
	make_window(800*SCALE, 800*SCALE);

	drawButton(100,200);
}

//X and Y Co-ordinates at center of button
struct Button {
	int xCord;
	int yCord;
	int character;
	//size is measured in x distence from the faces |<-->|
	int size;
};

//Draw a button centered at the x,y coordinates with the specified charactor
void drawButton(int x, int y) {
		
}