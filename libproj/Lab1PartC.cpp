#include "library.h"
#include "MainTester.h"

//constants
const double pi = 3.14159265358979323846;


void DrawCircle(int steps, int segmentLen) {
	move_to(400-(segmentLen)/2/*Do this to put cirlce in middle of x = 400*/, 200);
	//Loop for sharpness of circle
	for (int step = 0; step <= steps; step++) {
		//get the progress around circle
		float circleProgress = (float)step / steps;
		
		//get tau
		float currRadian = circleProgress * 2 * pi;

		//scale x and y over -1 to 1
		float xScale = cos(currRadian);
		float yScale = sin(currRadian);

		//multiply by desired lenghth of segment to get size of cirlce and actual x y coordinates

		double x = xScale * segmentLen;
		double y = yScale * segmentLen;
		
		draw_relative(-x,-y); //Negative to that it moves more like a x-y graph
	}	
}

//Main function, gets called from the tester file where void main is
 void Lab1PartC() {
	//Make the window to draw on
	
	make_window(800, 800);

	//Modify pen to be thicker
	set_pen_width(3);
	set_pen_color(color::red);
	//Make Person

	//draw head
	DrawCircle(20, 16);

	//Draw Back
	move_relative(8,0);
	set_pen_color(color::black);
	draw_relative(0, 50);
	//mark where the arms break off
	double xArmLocation = get_x_position();
	double yArmlocation = get_y_position();
	//Draw left arm
	set_heading_degrees(210);
	draw_distance(100);
	//move back to arm break
	move_to(xArmLocation, yArmlocation);
	//draw right arm waving
	set_heading_degrees(150);
	draw_distance(50);
	set_heading_degrees(45);
	draw_distance(50);
	//move back to arm break
	move_to(xArmLocation, yArmlocation);
	draw_relative(0, 100);
	//mark where the legs break off
	double xLegLocation = get_x_position();
	double yLegLocation = get_y_position();
	//draw left leg
	set_heading_degrees(210);
	draw_distance(100);
	//move back to leg break
	move_to(xLegLocation, yLegLocation);
	//draw right leg
	set_heading_degrees(150);
	draw_distance(100);
}