#include "library.h"
#include "MainTester.h"

//global scale variable for length
const double scale = 1.0;

//Main function called from tester.cpp
void Lab2() {
	make_window(800, 800);
	drawAmericanFlag(100, 100, 600);
}

#pragma region Draw Star Function
/**
*
* Makes a 5 pointed star
*
* @param x The X position in the window to start drawing the star
* @param y The Y position in the window to start drawing the star
* @param length The segment length for each line on the star
* @param color The color you wish the star to be filled with
*
*/
void drawStar(const int x, const int y, const int length, const int color) {
	//set starting pos
	move_to(x, y);
	//draw it
	set_pen_color(color);
	//color it in and note each location
	start_shape();
	
	//top middle
	set_heading_degrees(180);
	turn_left_by_degrees(36 / 2);
	draw_distance(length);
	note_position();
	//inner top right
	set_heading_degrees(90);
	draw_distance(length);
	note_position();
	//top right point
	set_heading_degrees(270);
	turn_left_by_degrees(36);
	draw_distance(length);
	note_position();
	//inner bottom right
	set_heading_degrees(180);
	turn_left_by_degrees(36 / 2);
	draw_distance(length);
	note_position();
	//bottom right
	set_heading_degrees(get_heading_degrees()-180);
	turn_left_by_degrees(36);
	draw_distance(length);
	note_position();
	//middle bottom to bottom left
	turn_left_by_degrees(180-108);
	draw_distance(length);
	note_position();
	//bottom left to middle left
	set_heading_degrees(get_heading_degrees() - 180);
	turn_left_by_degrees(36);
	draw_distance(length);
	note_position();
	//middle left to top left
	turn_left_by_degrees(180 - 108);
	draw_distance(length);
	note_position();
	//top left to top middle left
	set_heading_degrees(90);
	draw_distance(length);
	note_position();
	//top middle left to top middle
	set_heading_degrees(0);
	turn_right_by_degrees(36/2);
	draw_distance(length);
	note_position();
	fill_shape();
}
#pragma endregion

#pragma region LoneStar Function

/**
*
* Make the flag of Texas
* 
* @param x X location to place flag
* @param y Y location to place flag
* 
*/
void loneStar(const int x, const int y) {
	//move to location
	move_to(x, y);

	//draw blue rectangle
	start_shape();
	set_pen_color(color::blue);
	set_heading_degrees(90);
	move_distance(250 * scale);
	//top right
	note_position();
	turn_right_by_degrees(90);
	move_distance(500 * scale);
	//bottom right
	note_position();
	turn_right_by_degrees(90);
	move_distance(250 * scale);
	//bottom left
	note_position();
	turn_right_by_degrees(90);
	move_distance(500 * scale);
	//top right
	note_position();
	fill_shape();

	//draw star
	drawStar(x + ((250 * scale) / 2), y - 75 + (500 * scale) / 2, 60*scale, color::white);

	//draw red rectangle
	move_to(x + (250 * scale), y + (500 * scale));
	
	fill_rectangle(get_x_position(), get_y_position(), 500 * scale, -250 * scale, color::red);
	

}
#pragma endregion

#pragma region Row Of Stars Function

void rowOfStars(const int x, const int y, const int starCount, const int size) {
	//move to top right corner or desired design
	move_to(x, y);
	//draw the rectangle
	int heightScale = 10;
	double height = size/6.8 * scale;
	double width = size * scale;
	fill_rectangle(get_x_position(), get_y_position(), width, height, color::blue);
	
	//draw the stars
	//get the pixel distence between each star
	double distence = (double)width / (double)starCount;
	//set the degrees to work along the y axis
	set_heading_degrees(180);
	for (int star = 1; star <= starCount; star++ ) {
		//correctly center the rows of stars but offsetting the first star
		if (star == 1) {
			drawStar((int)get_x_position() + distence/2,
				y + height/heightScale,
				size/20 * scale,
				color::white);
		}
		else {
			drawStar((int)get_x_position() + distence,
				y + height/heightScale,
				size/20 * scale,
				color::white);
		}
	}
}
#pragma endregion

#pragma region Draw American Flag Function
/**
* Draw The American Flag
* 
* @param x Starting X location
* @param y Starting Y location
* @param size Size of flag relative to the x axis
* 
*/
void drawAmericanFlag(const int x, const int y, const int size) {
	//reset cursor
	move_to(x, y);
	//get size scaled flag is width 19 to height 10
	double xAxis = size * scale;
	int yAxisAddition = 35;
	double widthScale = size / 19;
	double heightScale = (size * 10) / 19;
	//draw the red rectangles of the flag first
	for (int i = 0; i < 7; i++) {
		fill_rectangle((int)get_x_position(),
			(int)get_y_position()+(int)((heightScale*i)/7),
			(int)size, 
			(int)heightScale/13, 
			color::red);
	}

	move_to(x, y);
	//draw the stars minus the last row
	rowOfStars(x, y + yAxisAddition * 0, 6, size * .40);
	rowOfStars(x, y + yAxisAddition * 1, 5, size * .40);
	rowOfStars(x, y + yAxisAddition * 2, 6, size * .40);
	rowOfStars(x, y + yAxisAddition * 3, 5, size * .40);
	rowOfStars(x, y + yAxisAddition * 4, 6, size * .40);
	rowOfStars(x, y + yAxisAddition * 5, 5, size * .40);
}



#pragma endregion