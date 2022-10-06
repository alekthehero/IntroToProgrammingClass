#include "library.h"
#include "MainTester.h"


//structure so that draw cannon can return the firing point when called
struct FiringPoint
{
	int x;
	int y;
	FiringPoint(int xLoc, int yLoc) {
		x = xLoc;
		y = yLoc;
	}
};

int angle = 60;
//Main function called from tester.cpp
void Lab4() {
	//h(meters) = v(meters/second)t(seconds) ‐ 1/2(9.807)t^2
	make_window(800, 800);
	FiringPoint firePoint(0, 0);
	firePoint = drawCannonAndReturnFiringPoint(150, 700, angle);
	drawFiringLine(firePoint.x, firePoint.y, 100);
}



#pragma region Draw firing line
const double g = 9.807;
void drawFiringLine(int xLoc, int yLoc, double velocity) {
	double y;

	for (double seconds = 1; seconds <= (2*velocity)/g; seconds += .05){
		y = (velocity * seconds*cos((angle*(acos(-1)/180))) - (.5 * g * pow(seconds, 2)));
		set_pen_width(5);
		set_pen_color(color::pink);
		draw_point(xLoc+(seconds*20), yLoc-y+100);
	}

}

#pragma endregion


#pragma region drawCannon Edit

FiringPoint drawCannonAndReturnFiringPoint(int x, int y, double angle) {
	double pi = acos(-1.0);
	/*G is the point on the ground where the wheel rests.Its coordinates are(xg, yg).
	C is the exact position of the axle, its coordinates are(xc, yc).
	P is the easiest point to start drawing the body of the cannon from, coordinates(xp, yp).
	E is the point where the ball pops out when it is fired, coordinates(xe, ye).*/
	double a = angle * (pi / 180);
	double radius = 30;
	double xGround = x;
	double yGround = y;
	double xAxle = xGround;
	double yAxle = yGround - radius;
	double xCannon;
	double yCannon;
	double xFirePoint;
	double yFirePoint;
	//dimensions of the cannon
	double widthBackOfCannon = 80;
	double widthFrontOfCannon = 60;
	double lengthBackToAxle = 70;
	double lengthAxleToFront = 240;

	//drawing the shape of the cannon we need the base angle
	double drawnCannonAngle = asin(
		(widthBackOfCannon - widthFrontOfCannon)
		/ 2 /
		(lengthBackToAxle + lengthAxleToFront)
	);

	//calculate where to start drawing the cannon
	xCannon = xAxle - lengthBackToAxle * sin(a - drawnCannonAngle);
	yCannon = yAxle + lengthBackToAxle * cos(a - drawnCannonAngle);

	//get the overall length of the cannon
	double length = (lengthBackToAxle + lengthAxleToFront) * cos(drawnCannonAngle);

	//find where the cannon ball shoots

	//get distence between draw cannon point and where the ball shoots
	double distenceToFiringPoint = sqrt(length * length + widthBackOfCannon * widthBackOfCannon / 4);
	//get angle between the two
	double firingAngle = asin(widthBackOfCannon / 2 / distenceToFiringPoint);

	//now we can calculate the firing location
	xFirePoint = xCannon + distenceToFiringPoint * sin(a - firingAngle);
	yFirePoint = yCannon - distenceToFiringPoint * cos(a - firingAngle);

	//Now actually draw the cannon
	set_pen_width(10);
	set_pen_color(color::red);
	draw_point(xCannon, yCannon);
	set_pen_color(color::orange);
	draw_point(xAxle, yAxle);
	set_pen_color(color::cyan);
	draw_point(xFirePoint, yFirePoint);
	set_pen_color(color::black);
	set_pen_width(2);

	//draw the circle first given its center point and radius
	for (double angle = 0; angle <= 2 * pi; angle += 0.01) {
		draw_point(xAxle + radius * cos(angle), yAxle + radius * sin(angle));
	}

	//draw cannon now
	move_to(xCannon, yCannon);
	set_heading_radians(a);
	//set_heading_degrees(90 - (a - ((drawnCannonAngle * (180 / pi)) * a)));
	draw_distance(lengthBackToAxle - radius);
	move_distance(radius * 2);
	draw_distance(lengthAxleToFront - radius);
	turn_left_by_degrees(90);
	draw_distance(widthFrontOfCannon);
	turn_left_by_degrees(86);
	draw_distance(length);
	turn_left_by_degrees(94);
	draw_distance(widthBackOfCannon);

	//set a structure to return the xy position of a firing point
	FiringPoint returnFiring(xFirePoint, yFirePoint);
	return returnFiring;

}


#pragma endregion