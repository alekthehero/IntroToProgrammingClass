#include "library.h"
#include "MainTester.h"

//format the data in the file into nine variables
double year, month, day, minTemp, avgTemp, maxTemp, maxwind, snow, rain;


void Lab9() {
	
	make_window(800, 600);
	set_caption("Average Temp");
	
	//get the file
	string inputFile = open_file_pop_up();
	
	ifstream file(inputFile);
	if (file.fail())
	{
		cout << "File not found" << endl;
		return;
	}
	
	//set the pen settings
	set_pen_color(color::black);
	set_pen_width(2);


	//count for the number of lines in the file
	int count = 0;
	double startingXAxis = 50.0;
	int yAxisBump = 200;
	
	//draw the x-axis which is months
	move_to(startingXAxis, 560.0);
	draw_to(790, 560);

	//draw the y-axis which is temperature
	move_to(startingXAxis, 560.0);
	draw_to(startingXAxis, 50.0);


	#pragma region Draw the X-Axis
	//draw the x-axis labels
	move_to(startingXAxis, 570.0);
	write_string("Jan");
	move_to(startingXAxis + 60, 570.0);
	write_string("Feb");
	move_to(startingXAxis + 120, 570.0);
	write_string("Mar");
	move_to(startingXAxis + 180, 570.0);
	write_string("Apr");
	move_to(startingXAxis + 240, 570.0);
	write_string("May");
	move_to(startingXAxis + 300, 570.0);
	write_string("Jun");
	move_to(startingXAxis + 360, 570.0);
	write_string("Jul");
	move_to(startingXAxis + 420, 570.0);
	write_string("Aug");
	move_to(startingXAxis + 480, 570.0);
	write_string("Sep");
	move_to(startingXAxis + 540, 570.0);
	write_string("Oct");
	move_to(startingXAxis + 600, 570.0);
	write_string("Nov");
	move_to(startingXAxis + 660, 570.0);
	write_string("Dec");
#pragma endregion
	
	#pragma region Draw the Y-Axis
	//draw the y-axis labels
	move_to(40.0, 560.0);
	write_string("100");
	move_to(40.0, 560.0 - yAxisBump);
	write_string("80");
	move_to(40.0, 560.0 - yAxisBump * 2);
	write_string("60");
	move_to(40.0, 560.0 - yAxisBump * 3);
	write_string("40");
	move_to(40.0, 560.0 - yAxisBump * 4);
	write_string("20");
	move_to(40.0, 560.0 - yAxisBump * 5);
	write_string("0");
#pragma endregion
	
	//read the data from the file
	if (file.is_open()) {
		//move to first dot and make a point
		set_pen_color(color::blue);
		file >> year >> month >> day >> minTemp >> avgTemp >> maxTemp >> maxwind >> snow >> rain;
		move_to(startingXAxis, (get_window_height() - minTemp * 5) - yAxisBump);
		draw_point(startingXAxis, (get_window_height() - minTemp * 5) - yAxisBump);
		//int array that holds the current positions coordinates
		double currentMinPos[2] = { get_x_position(), get_y_position()};
		//draw points for maxtemp
		set_pen_color(color::red);
		move_to(startingXAxis, (get_window_height() - maxTemp * 5) - yAxisBump);
		draw_point(startingXAxis, (get_window_height() - maxTemp * 5) - yAxisBump);
		//int array that holds the current positions coordinates
		double currentMaxPos[2] = { get_x_position(), get_y_position() };
		
		//run through the rest of the file
		while (true) {
			
			file >> year >> month >> day >> minTemp >> avgTemp >> maxTemp >> maxwind >> snow >> rain;
			if (file.fail()) {
				break;
			}
			count++;
			double xCord = (2*count)+2+startingXAxis;
			//draw points for minTemp
			set_pen_color(color::blue);
			//move to last min position
			move_to(currentMinPos[0], currentMinPos[1]);
			draw_to(xCord, (get_window_height() - minTemp * 5) - yAxisBump);
			//set new min position
			currentMinPos[0] = get_x_position();
			currentMinPos[1] = get_y_position();
			//draw to for max temp
			set_pen_color(color::red);
			//move to last max position
			move_to(currentMaxPos[0], currentMaxPos[1]);
			draw_to(xCord, (get_window_height() - maxTemp * 5) - yAxisBump);
			//set new max position
			currentMaxPos[0] = get_x_position();
			currentMaxPos[1] = get_y_position();
		}
		file.close();
	}
	else {
		cout << "End Of File" << endl;
	}
}


	