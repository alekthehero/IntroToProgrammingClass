#include "library.h"
#include "MainTester.h"


//Main function called from tester.cpp
void Lab2() {
	make_window(800, 800);
	drawStar(200, 400, 50);
	drawStar(600, 400 , 30);
}

/**
*
* Makes a 5 pointed star
*
* @param x The X position in the window to start drawing the star
* @param y The Y position in the window to start drawing the star
* @param length The segment length for each line on the star
*
*/
void drawStar(const int x, const int y, const int length) {
	//set starting pos
	move_to(x, y);
	//draw it
	
	//top right
	set_heading_degrees(180 - 36);
	draw_distance(length);
	//right upper
	set_heading_degrees(90);
	draw_distance(length);
	//right top point to middle
	set_heading_degrees(270 - 36);
	draw_distance(length);
	//right middle to bottom right point
	set_heading_degrees(180 - 36);
	draw_distance(length);

	//bottom right point to middle bottom
	set_heading_degrees(180 + 108);
	draw_distance(length);
	//middle bottom to bottom left point
	set_heading_degrees(288-36);
	draw_distance(length);

	//bottom left point to middle left
	set_heading_degrees(36);
	draw_distance(length);
	//middle left to top left point
	set_heading_degrees(270+36);
	draw_distance(length);
	//top left point to top left middle
	set_heading_degrees(90);
	draw_distance(length);
	//top left middle to top middle point
	set_heading_degrees(36);
	draw_distance(length);


}