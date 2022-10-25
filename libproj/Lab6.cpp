#include "library.h";
#include "MainTester.h";

void Lab6() {
	cout << daysLong(2022, 2) << "\n";
	cout << daysLong(2024, 2) << "\n";
	cout << daysLong(2078, 7) << "\nDays in the year up to this point\n";
	cout << dayOfTheYear(2022, 10, 25) << "\nDays in the century up to this point\n";
	cout << dayOfTheCentury(2022, 10, 25) << "\nDays from zero\n";
	cout << dayFromYearZero(2000, 1, 1);
}

struct months {
	int january = 31;
	int february = 28;
	int march = 31;
	int april = 30;
	int may = 31;
	int june = 30;
	int july = 31;
	int august = 31;
	int september = 30;
	int october = 31;
	int november = 30;
	int december = 31;
};

months listOfMonths;
int daysLong(int year, int month) {

	if (year % 400 == 0 && year % 4 == 0 && year % 100 != 0) {
		//feb is a 29 day month
		listOfMonths.february = 29;
	}

	#pragma region Month Check
	if (month == 1) {
		return(listOfMonths.january);
	}
	if (month == 2) {
		return(listOfMonths.february);
	}
	if (month == 3) {
		return(listOfMonths.march);
	}
	if (month == 4) {
		return(listOfMonths.april);
	}
	if (month == 5) {
		return(listOfMonths.may);
	}
	if (month == 6) {
		return(listOfMonths.june);
	}
	if (month == 7) {
		return(listOfMonths.july);
	}
	if (month == 8) {
		return(listOfMonths.august);
	}
	if (month == 9) {
		return(listOfMonths.september);
	}
	if (month == 10) {
		return(listOfMonths.october);
	}
	if (month == 11) {
		return(listOfMonths.november);
	}
	if (month == 12) {
		return(listOfMonths.december);
	}
	else {
		return(NULL);
	}
#pragma endregion

	

}

int dayOfTheYear(int year, int month, int day) {
	int dayCount = day;
	for (int i = month; i >= 1; i--) {
		dayCount += daysLong(year, i);
	}
	return dayCount;
}

int dayOfTheCentury(int year, int month, int day) {
	int dayCount = dayOfTheYear(year,month,day);
	for (int i = year; i >= 2000; i--) {
		if (year % 4 == 0) {
			//day count for the year is 366
			dayCount += 366;
		}
		else {
			dayCount += 365;
		}
	}
	return dayCount;
}

int dayFromYearZero(int year, int month, int day) {
	int dayCount = dayOfTheYear(year, month, day);
	for (int i = year; i >= 0; i--) {
		if (year % 400 == 0 && year % 4 == 0 && year % 100 != 0) {
			//day count for the year is 366
			dayCount += 366;
		}
		else {
			dayCount += 365;
		}
	}
	return dayCount;
}