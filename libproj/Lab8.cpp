#include "library.h"
#include "MainTester.h"

int const SCALE = 1;
int const ROW = 4;
int const COLUMN = 5;

int baseSize = 100 * SCALE;

string onDisplay = "";

string input = "";
string output = "";
string operation = "";

//X and Y Co-ordinates at center of button
struct Button {
	int xCord;
	int yCord;
	string character;
	//size is measured in x distence from the faces |<-->|
	int size;
	int fontSize = 80;

	Button(int x, int y, string c, int s) {
		xCord = x;
		yCord = y;
		character = c;
		size = s;
	}

	Button(int x, int y, string c, int s, int fSize) {
		xCord = x;
		yCord = y;
		character = c;
		size = s;
		fontSize = fSize;
	}
};

void Lab8() {
	make_window(800*SCALE, 800*SCALE);

	drawGrid();
}

void clearDisplay() {
	set_pen_width(120 * SCALE);
	set_pen_color(color::white);
	move_to(0, 50);
	draw_to(get_window_width(), 50);

}

void pushToDisplay(string item) {
	
	clearDisplay();
	onDisplay.append(item);
	print("\n\n");
	print(onDisplay);
	print("\n\n");
	move_to(100, 90);
	set_pen_color(color::black);
	set_font_size(100);

	//check if the length of the if longer then 14 characters and dont write_string if it is
	if (onDisplay.length() < 14) {
		write_string(onDisplay);
	}
	else {
		onDisplay = "";
		write_string("Error");
	}
	
}


void updateDisplay(Button toUpdateButton) {
	
	if (toUpdateButton.character == "C") {
		clearDisplay();
		onDisplay = "";
		return;
	}

	if (toUpdateButton.character == "+") {
		//do math
		clearDisplay();
		input = onDisplay;
		operation = "+";
		onDisplay = "";
	}
	if (toUpdateButton.character == "-") {
		//do math
		clearDisplay();
		input = onDisplay;
		operation = "-";
		onDisplay = "";
		return;
	}
	if (toUpdateButton.character == "X") {
		//do math
		clearDisplay();
		input = onDisplay;
		operation = "X";
		onDisplay = "";
		return;
	}
	if (toUpdateButton.character == "/") {
		//do math
		clearDisplay();
		input = onDisplay;
		operation = "/";
		onDisplay = "";
		return;
	}
	if (toUpdateButton.character == "+/-") {
		//convert onscreen to a neg if its pos and a pos if its neg
		onDisplay = to_string(stoi(onDisplay) * -1);
		pushToDisplay("");
		return;
	}
	if (toUpdateButton.character == "X^2") {
		clearDisplay();
		input = onDisplay;
		operation = "X^2";
		onDisplay = "";
		return;
	}

	

	if (toUpdateButton.character == "=") {
		//do math
		clearDisplay();

		if (operation == "+") {
			output = to_string(stoi(input) + stoi(onDisplay));
		}
		if (operation == "-") {
			output = to_string(stoi(input) - stoi(onDisplay));
		}
		if (operation == "X") {
			output = to_string(stoi(input) * stoi(onDisplay));
		}
		if (operation == "/") {
			output = to_string(stoi(input) / stoi(onDisplay));
		}
		if (operation == "X^2") {
			output = to_string(stoi(input) * stoi(input));
		}
		onDisplay = "";
		pushToDisplay(output);
		return;
	}
	
	pushToDisplay(toUpdateButton.character);

}

//Draw a button centered at the x,y coordinates with the specified charactor
void drawButton(Button button) {
	//move pen to the center of where the button should be

	//move to top left corner of button
	move_to(button.xCord - (button.size / 2), button.yCord - (button.size / 2));

	//draw the outline of the button
	set_heading_degrees(90);
	draw_distance((double)button.size);
	turn_right_by_degrees(90);
	draw_distance((double)button.size);
	turn_right_by_degrees(90);
	draw_distance((double)button.size);
	turn_right_by_degrees(90);
	draw_distance((double)button.size);

	//print the character on the screen
	move_to(button.xCord-(button.size/6), button.yCord+(button.size/4));
	set_font_size(button.fontSize * SCALE);
	write_string(button.character, true);
}

void drawGrid() {
	//get the center count of each button compared to size of screen
	int xScaled = (get_window_width() / COLUMN) - (baseSize / 2);
	int yScaled = get_window_height() - (get_window_height() / ROW);
	int yIncrement = -(baseSize + 10);

	//draw buttons bottom row
	Button clearButton = Button(xScaled, yScaled, "C", baseSize);
	drawButton(clearButton);
	Button zeroButton = Button(xScaled * 2, yScaled, "0", baseSize);
	drawButton(zeroButton);
	Button equalButton = Button(xScaled * 3, yScaled, "=", baseSize);
	drawButton(equalButton);
	Button dividButton = Button(xScaled * 4, yScaled, "/", baseSize);
	drawButton(dividButton);
	Button upButton = Button(xScaled * 5, yScaled, "/\\", baseSize);
	drawButton(upButton);

	//row above that
	Button oneButton = Button(xScaled, yScaled + yIncrement, "1", baseSize);
	drawButton(oneButton);
	Button twoButton = Button(xScaled * 2, yScaled + yIncrement, "2", baseSize);
	drawButton(twoButton);
	Button threeButton = Button(xScaled * 3, yScaled + yIncrement, "3", baseSize);
	drawButton(threeButton);
	Button timeButton = Button(xScaled * 4, yScaled + yIncrement, "X", baseSize);
	drawButton(timeButton);
	Button rndButton = Button(xScaled * 5, yScaled + yIncrement, "rnd", baseSize, 40);
	drawButton(rndButton);

	//row above that
	Button fourButton = Button(xScaled, yScaled + yIncrement * 2, "4", baseSize);
	drawButton(fourButton);
	Button fiveButton = Button(xScaled * 2, yScaled + yIncrement * 2, "5", baseSize);
	drawButton(fiveButton);
	Button sixButton = Button(xScaled * 3, yScaled + yIncrement * 2, "6", baseSize);
	drawButton(sixButton);
	Button subButton = Button(xScaled * 4, yScaled + yIncrement * 2, "-", baseSize);
	drawButton(subButton);
	Button posNegButton = Button(xScaled * 5, yScaled + yIncrement * 2, "+/-", baseSize, 40);
	drawButton(posNegButton);

	//row above that
	Button sevenButton = Button(xScaled, yScaled + yIncrement * 3, "7", baseSize);
	drawButton(sevenButton);
	Button eightButton = Button(xScaled * 2, yScaled + yIncrement * 3, "8", baseSize);
	drawButton(eightButton);
	Button nineButton = Button(xScaled * 3, yScaled + yIncrement * 3, "9", baseSize);
	drawButton(nineButton);
	Button plusButton = Button(xScaled * 4, yScaled + yIncrement * 3, "+", baseSize);
	drawButton(plusButton);
	Button squarButton = Button(xScaled * 5, yScaled + yIncrement * 3, "X^2", baseSize, 40);
	drawButton(squarButton);
	
	Button sinButton = Button(xScaled, yScaled + yIncrement * 4, "sin", baseSize, 40);
	drawButton(sinButton);

	//main calc loop
	while (true) {
		wait_for_mouse_click();
		int xClick = get_click_x();
		int yClick = get_click_y();

		//clear button
		if (clearButton.xCord - (baseSize / 2) < xClick and xClick < clearButton.xCord + (baseSize / 2)) {
			if (clearButton.yCord - (baseSize / 2) < yClick and yClick < clearButton.yCord + (baseSize / 2)) {
				print("clicked clear button\n");
				updateDisplay(clearButton);
			}
		}

		//zero button
		if (zeroButton.xCord - (baseSize / 2) < xClick and xClick < zeroButton.xCord + (baseSize / 2)) {
			if (zeroButton.yCord - (baseSize / 2) < yClick and yClick < zeroButton.yCord + (baseSize / 2)) {
				print("clicked zero button\n");
				updateDisplay(zeroButton);
			}
		}

		//equal button
		if (equalButton.xCord - (baseSize / 2) < xClick and xClick < equalButton.xCord + (baseSize / 2)) {
			if (equalButton.yCord - (baseSize / 2) < yClick and yClick < equalButton.yCord + (baseSize / 2)) {
				print("clicked equal button\n");
				updateDisplay(equalButton);
			}
		}

		//divid button
		if (dividButton.xCord - (baseSize / 2) < xClick and xClick < dividButton.xCord + (baseSize / 2)) {
			if (dividButton.yCord - (baseSize / 2) < yClick and yClick < dividButton.yCord + (baseSize / 2)) {
				print("clicked divid button\n");
				updateDisplay(dividButton);
			}
		}

		//up arrow?
		if (upButton.xCord - (baseSize / 2) < xClick and xClick < upButton.xCord + (baseSize / 2)) {
			if (upButton.yCord - (baseSize / 2) < yClick and yClick < upButton.yCord + (baseSize / 2)) {
				print("clicked up button\n");
				updateDisplay(upButton);
			}
		}

		//one button
		if (oneButton.xCord - (baseSize / 2) < xClick and xClick < oneButton.xCord + (baseSize / 2)) {
			if (oneButton.yCord - (baseSize / 2) < yClick and yClick < oneButton.yCord + (baseSize / 2)) {
				print("clicked one button\n");
				updateDisplay(oneButton);
			}
		}

		//two button
		if (twoButton.xCord - (baseSize / 2) < xClick and xClick < twoButton.xCord + (baseSize / 2)) {
			if (twoButton.yCord - (baseSize / 2) < yClick and yClick < twoButton.yCord + (baseSize / 2)) {
				print("clicked two button\n");
				updateDisplay(twoButton);
			}
		}

		//three button
		if (threeButton.xCord - (baseSize / 2) < xClick and xClick < threeButton.xCord + (baseSize / 2)) {
			if (threeButton.yCord - (baseSize / 2) < yClick and yClick < threeButton.yCord + (baseSize / 2)) {
				print("clicked three button\n");
				updateDisplay(threeButton);
			}
		}

		//times button
		if (timeButton.xCord - (baseSize / 2) < xClick and xClick < timeButton.xCord + (baseSize / 2)) {
			if (timeButton.yCord - (baseSize / 2) < yClick and yClick < timeButton.yCord + (baseSize / 2)) {
				print("clicked times button\n");
				updateDisplay(timeButton);
			}
		}

		//rnd button
		if (rndButton.xCord - (baseSize / 2) < xClick and xClick < rndButton.xCord + (baseSize / 2)) {
			if (rndButton.yCord - (baseSize / 2) < yClick and yClick < rndButton.yCord + (baseSize / 2)) {
				print("clicked rnd button\n");
				updateDisplay(rndButton);
			}
		}

		//four button
		if (fourButton.xCord - (baseSize / 2) < xClick and xClick < fourButton.xCord + (baseSize / 2)) {
			if (fourButton.yCord - (baseSize / 2) < yClick and yClick < fourButton.yCord + (baseSize / 2)) {
				print("clicked four button\n");
				updateDisplay(fourButton);
			}
		}

		//five button
		if (fiveButton.xCord - (baseSize / 2) < xClick and xClick < fiveButton.xCord + (baseSize / 2)) {
			if (fiveButton.yCord - (baseSize / 2) < yClick and yClick < fiveButton.yCord + (baseSize / 2)) {
				print("clicked five button\n");
				updateDisplay(fiveButton);
			}
		}

		//six button
		if (sixButton.xCord - (baseSize / 2) < xClick and xClick < sixButton.xCord + (baseSize / 2)) {
			if (sixButton.yCord - (baseSize / 2) < yClick and yClick < sixButton.yCord + (baseSize / 2)) {
				print("clicked six button\n");
				updateDisplay(sixButton);
			}
		}

		//minus button
		if (subButton.xCord - (baseSize / 2) < xClick and xClick < subButton.xCord + (baseSize / 2)) {
			if (subButton.yCord - (baseSize / 2) < yClick and yClick < subButton.yCord + (baseSize / 2)) {
				print("clicked minus button\n");
				updateDisplay(subButton);
			}
		}

		//posNeg Button
		if (posNegButton.xCord - (baseSize / 2) < xClick and xClick < posNegButton.xCord + (baseSize / 2)) {
			if (posNegButton.yCord - (baseSize / 2) < yClick and yClick < posNegButton.yCord + (baseSize / 2)) {
				print("clicked pos neg button\n");
				updateDisplay(posNegButton);
			}
		}

		//seven button
		if (sevenButton.xCord - (baseSize / 2) < xClick and xClick < sevenButton.xCord + (baseSize / 2)) {
			if (sevenButton.yCord - (baseSize / 2) < yClick and yClick < sevenButton.yCord + (baseSize / 2)) {
				print("clicked seven button\n");
				updateDisplay(sevenButton);
			}
		}

		//eight button
		if (eightButton.xCord - (baseSize / 2) < xClick and xClick < eightButton.xCord + (baseSize / 2)) {
			if (eightButton.yCord - (baseSize / 2) < yClick and yClick < eightButton.yCord + (baseSize / 2)) {
				print("clicked eight button\n");
				updateDisplay(eightButton);
			}
		}

		//nine button
		if (nineButton.xCord - (baseSize / 2) < xClick and xClick < nineButton.xCord + (baseSize / 2)) {
			if (nineButton.yCord - (baseSize / 2) < yClick and yClick < nineButton.yCord + (baseSize / 2)) {
				print("clicked nine button\n");
				updateDisplay(nineButton);
			}
		}

		//plus button
		if (plusButton.xCord - (baseSize / 2) < xClick and xClick < plusButton.xCord + (baseSize / 2)) {
			if (plusButton.yCord - (baseSize / 2) < yClick and yClick < plusButton.yCord + (baseSize / 2)) {
				print("clicked plus button\n");
				updateDisplay(plusButton);
			}
		}
		
		//squar button
		if (squarButton.xCord - (baseSize / 2) < xClick and xClick < squarButton.xCord + (baseSize / 2)) {
			if (squarButton.yCord - (baseSize / 2) < yClick and yClick < squarButton.yCord + (baseSize / 2)) {
				print("clicked square button\n");
				updateDisplay(squarButton);
			}
		}

		//zero button
		if (zeroButton.xCord - (baseSize / 2) < xClick and xClick < zeroButton.xCord + (baseSize / 2)) {
			if (zeroButton.yCord - (baseSize / 2) < yClick and yClick < zeroButton.yCord + (baseSize / 2)) {
				print("clicked zero button\n");
				updateDisplay(zeroButton);
			}
		}
		
		//sin button
		if (sinButton.xCord - (baseSize / 2) < xClick and xClick < sinButton.xCord + (baseSize / 2)) {
			if (sinButton.yCord - (baseSize / 2) < yClick and yClick < sinButton.yCord + (baseSize / 2)) {
				print("clicked sin button\n");
				updateDisplay(sinButton);
			}
		}

	}
	
}