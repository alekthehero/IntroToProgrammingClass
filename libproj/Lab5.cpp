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
				move_to(currX, currY);
				draw_to(innerX, innerY);
			}
		}
	}
	//draw time and date




	int sleepTime = 20;
	while (true) {
		//get time
		int calDate = get_calendar_date();
		int year = calDate / 10000;
		int month = calDate / 100 % 100;
		int day = calDate % 100;

		//get time
		int timeVal = get_clock_time();
		int hour24 = timeVal / 10000;
		int hour12 = ((hour24 - 2) % 10);
		int minute = timeVal / 100 % 100;
		int second = timeVal % 100;


		move_to(0, 100);
		set_pen_width(40);
		set_pen_color(color::white);
		draw_to(400, 100);
		//write time and date
		if (hour24 > 12) {
			int hour = ((hour24 - 2) % 10);
			move_to(100, 100);
			set_pen_color(color::black);
			if (minute < 10) {
				string updatedMinute = std::to_string(minute);
				updatedMinute.insert(0, "0");
				string print = std::to_string(hour) + ":" + updatedMinute + " p.m.";
				write_string(print, direction::east);
			}
			else {
				string print = std::to_string(hour) + ":" + std::to_string(minute) + " p.m.";
				write_string(print, direction::east);
				cout << "test";
			}
		}
		else {
			set_pen_color(color::black);
			move_to(100, 100);
			if (minute < 10) {
				string updatedMinute = std::to_string(minute);
				updatedMinute.insert(0, "0");
				string print = std::to_string(hour24) + ":" + updatedMinute + " a.m.";
				write_string(hour24 + ":" + updatedMinute, direction::east);
			}
			else {
				string print = std::to_string(hour24) + ":" + std::to_string(minute) + " a.m.";
				write_string(print, direction::east);
			}
		}

		//update the date
		move_to(0, 500);
		set_pen_width(40);
		set_pen_color(color::white);
		draw_to(400, 500);

		move_to(100, 500);
		set_pen_color(color::black);
		string output= "Date: " + std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
		write_string(output);
		


		//calculate degrees to time
		double hourToDegree = 360 / 12;
		double minuteToDegree = 360 / 60;
		double secondToDegree = 360 / 60;
		//draw hands and update them
		//second hand
		int secondHandDegree = secondToDegree * second;
		move_to(200, 300);
		set_pen_width(2);
		set_heading_degrees(secondHandDegree);
		set_pen_color(color::black);
		draw_distance(120);
		Sleep(sleepTime);
		set_pen_color(color::white);
		draw_to(200, 300);
		//minute hand
		int minuteHandDegree = minute * minuteToDegree;
		move_to(200, 300);
		set_pen_width(4);
		set_heading_degrees(minuteHandDegree);
		set_pen_color(color::black);
		draw_distance(100);
		Sleep(sleepTime);
		set_pen_color(color::white);
		draw_to(200, 300);
		//hour
		int hourHandDegree = 0.5 * (hour12 * 60 + minute);
		move_to(200, 300);
		set_pen_width(5);
		set_heading_degrees(hourHandDegree);
		set_pen_color(color::black);
		draw_distance(80);
		Sleep(sleepTime);
		set_pen_color(color::white);
		draw_to(200, 300);
	}
}