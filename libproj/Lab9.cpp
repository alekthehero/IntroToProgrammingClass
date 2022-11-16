#include "library.h"
#include "MainTester.h"

//format the data in the file into nine variables
double year, month, day, minTemp, avgTemp, maxTemp, maxwind, snow, rain;


void Lab9() {
	
	make_window(800, 600);
	set_caption("Average Temp");

	ifstream file("data.txt");
	if (file.fail())
	{
		cout << "File not found" << endl;
		return;
	}
	
	while (true) {
		//read the data from the file
		if (file.is_open()) {
			while (file >> year >> month >> day >> minTemp >> avgTemp >> maxTemp >> maxwind >> snow >> rain) {
				if (file.fail()) {
					break;
				}
				double xCord = month * 31 + day;
				draw_point(xCord*2, (get_window_height() - avgTemp)-100);
			}
			file.close();
		}
		else {
			cout << "End Of File" << endl;
			break;
		}
	}
}

	