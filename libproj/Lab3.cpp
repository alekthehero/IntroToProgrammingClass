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

void drawCannon(int x, int y, int angle) {
	drawCircle(x, y, 20, 15);
}

#pragma endregion