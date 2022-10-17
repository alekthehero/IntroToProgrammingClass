#include "library.h"
#include "MainTester.h"

void Lab5() {
	//get date
	int year = get_calendar_date() / 10000;
	int month = get_calendar_date() / 100 % 100;
	int day = get_calendar_date() % 100;

	//get time
	int hour = get_clock_time() / 10000;
	int minute = get_clock_time() / 100 % 100;

	//print the date
	cout << "Date: " << year << "-" << month << "-" << day;
	//print the time formatted to 12 hours
	if (hour > 12) {
		hour = ((hour - 2) % 10);
		cout << "\nTime: " << hour << ":" << minute << " p.m.";
	}
	else {
		cout << "\nTime: " << hour << ":" << minute << " a.m.";
	}
	make_window(400, 600);
	drawClock();
}

void drawClock() {
	set_pen_width(3);
	double pi = acos(-1);
	double tau = 2 * pi;

	for (double angle = 0; angle <= tau; angle += 0.001) {
		double currX = 200 + 150 * cos(angle);
		double currY = 300 + 150 * sin(angle);

		double innerX = 200 + 138 * cos(angle);
		double innerY = 300 + 138 * sin(angle);

		draw_point(currX, currY);

		for (int i = 0; i <= 12; i++) {
			if (!(angle < .523*i) && !(.524*i < angle)) {
				cout << "Draw Tick at 20\n";
				move_to(currX, currY);
				draw_to(innerX, innerY);
			}
		}
	}
	//calculate degrees to time
	double hourToDegree = 360 / 12;
	double minuteToDegree = 360 / 60;
	double secondToDegree = 360 / (60*60);
	//draw hands and update them
	//second hand
	int secondHandDegree = 0;
	move_to(200, 300);
	set_pen_width(2);
	set_heading_degrees(secondHandDegree);
	draw_distance(120);
	//minute hand
	int minuteHandDegree = 0;
	move_to(200, 300);
	set_heading_degrees(minuteHandDegree);
	draw_distance(120);

}