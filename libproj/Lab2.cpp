#include "library.h"
#include "MainTester.h"

//global scale variable for length
const double scale = 1.0;

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
void drawStar(const int x, const int y, int length) {
	length = length * scale;
	//set starting pos
	move_to(x, y);
	//draw it
	
	// USE turn_right_by_degrees();
	//36* for points 108* for shoulders

	//top middle
	set_heading_degrees(180);
	turn_left_by_degrees(36 / 2);
	draw_distance(length);
	//inner top right
	set_heading_degrees(90);
	draw_distance(length);
	//top right point
	set_heading_degrees(270);
	turn_left_by_degrees(36);
	draw_distance(length);
	//inner bottom right
	set_heading_degrees(180);
	turn_left_by_degrees(36 / 2);
	draw_distance(length);
	//bottom right
	set_heading_degrees(get_heading_degrees()-180);
	turn_left_by_degrees(36);
	draw_distance(length);
	//middle bottom to bottom left
	turn_left_by_degrees(180-108);
	draw_distance(length);
	//bottom left to middle left
	set_heading_degrees(get_heading_degrees() - 180);
	turn_left_by_degrees(36);
	draw_distance(length);
	//middle left to top left
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	//top left to top middle left
	set_heading_degrees(90);
	draw_distance(length);
	//top middle left to top middle
	set_heading_degrees(0);
	turn_right_by_degrees(36/2);
	draw_distance(length);



	


}