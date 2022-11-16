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
	
	//count for the number of lines in the file
	int count = 0;

	//set the pen settings
	set_pen_color(color::black);
	set_pen_width(2);

	//read the data from the file
	if (file.is_open()) {
		//move to first dot and make a point
		file >> year >> month >> day >> minTemp >> avgTemp >> maxTemp >> maxwind >> snow >> rain;
		move_to(2.0, (get_window_height() - avgTemp * 5) - 100);
		draw_point(2.0, (get_window_height() - avgTemp * 5) - 100);
		
		//run through the rest of the file
		while (true) {
			
			file >> year >> month >> day >> minTemp >> avgTemp >> maxTemp >> maxwind >> snow >> rain;
			if (file.fail()) {
				break;
			}
			count++;
			double xCord = (2*count)+2;
			draw_to(xCord, (get_window_height() - avgTemp * 5) - 100);
		}
		file.close();
	}
	else {
		cout << "End Of File" << endl;
	}
}


	