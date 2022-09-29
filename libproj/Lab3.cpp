#include "library.h"
#include "MainTester.h"

//Main function called from tester.cpp
void Lab3() {
	make_window(800, 800);
	drawCannon(400, 400, 60);
}

#pragma region A1
void count(int a, int b) {
	cout << "Count from A to B\nStarting count: " << a;
	for (int x = a; x <= b; x++) {
		cout << "\nCurrent Count: " << x;
	}
}
#pragma endregion

#pragma region A2
int countUpBy5(int a, int b) {
	if (a <= b) {
		cout << "\nCount from A, in pounds: " << a << " to B in Increments of 5\nCurrent conversion: " << a* 0.45359237;
		a += 5;
		return countUpBy5(a, b);
	}
	else {
		return 0;
	}
}
//Conversion one lb pound is 0.45359237 kg.

#pragma endregion

#pragma region B5

void dotsStarsDots(int d1, int s1, int d2) {

	for (int dots = 0; dots < d1; dots++){
		print(".");
	}
	for (int stars = 0; stars < s1; stars++){
		print("*");
	}
	for (int dots = 0; dots < d2; dots++){
		print(".");
	}
	print("\n");

}

void asciArt(int a, int b) {
	//cound down to 1 from a
	for (int i = a; i > 1; i--){
		dotsStarsDots(i, b, i);
		b = b + 2;
	}
}

#pragma endregion

#pragma region C2

void drawCannon(int x, int y, double a) {
	/*G is the point on the ground where the wheel rests.Its coordinates are(xg, yg).
	C is the exact position of the axle, its coordinates are(xc, yc).
	P is the easiest point to start drawing the body of the cannon from, coordinates(xp, yp).
	E is the point where the ball pops out when it is fired, coordinates(xe, ye).*/
	double pi = acos(-1.0);
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
	double widthBackOfCannon = 70;
	double widthFrontOfCannon = 60;
	double lengthBackToAxle = 40;
	double lengthAxleToFront = 260;

	//drawing the shape of the cannon we need the base angle
	double drawnCannonAngle = asin(
		(widthBackOfCannon - widthFrontOfCannon)
		/ 2 /
		(lengthBackToAxle + lengthAxleToFront)
	);

	//calculate where to start drawing the cannon
	xCannon = -(xAxle - lengthBackToAxle) * sin(a - drawnCannonAngle);
	yCannon = -(yAxle + lengthBackToAxle) * cos(a - drawnCannonAngle);

	//get the overall length of the cannon
	double length = (lengthBackToAxle + lengthAxleToFront) * cos(drawnCannonAngle);

	//find where the cannon ball shoots
	
	//get distence between draw cannon point and where the ball shoots
	double distenceToFiringPoint = sqrt((length * length) + (widthBackOfCannon * widthBackOfCannon) / 4);
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
	set_pen_color(color::black);
	set_pen_width(2);

	//draw the circle first given its center point
	for (double angle = 0; angle <= 2 * pi; angle += 0.01) {
		draw_point(xAxle + radius * cos(angle), yAxle + radius * sin(angle));
	}
	
	//draw cannon now
	move_to(xCannon, yCannon);
	set_heading_degrees(90 - (a - ((drawnCannonAngle * (180 / pi)) * a)));
	draw_distance(length - lengthBackToAxle);
	move_distance(radius*2);
	draw_distance(lengthAxleToFront);
	

	

}

#pragma endregion