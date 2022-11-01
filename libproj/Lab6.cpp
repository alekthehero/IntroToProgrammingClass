#include "library.h";
#include "MainTester.h";

void Lab6() {
	/*cout << daysLong(2022, 2) << "\n";
	cout << daysLong(2024, 2) << "\n";
	cout << daysLong(2078, 7) << "\nDays in the year up to this point\n";
	cout << dayOfTheYear(2022, 10, 25) << "\nDays in the century up to this point\n";
	cout << dayOfTheCentury(2022, 10, 25) << "\nDays from zero\n";*/

	cout << dayFromYearZero(1999, 1, 1) << "\n";
	cout << dayFromYearZero(1967, 5, 12) << "\n";
	cout << dayFromYearZero(1456, 9, 7) << "\n\n\n";
	//print(dayOfTheWeek(2000, 1, 1));

	printOutCal(1848, 4);
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

	if (year % 400 == 0)
	{
		//cout << year << " is a leap year.";
		//is a leap year
		listOfMonths.february = 29;
	}
	else if (year % 100 == 0)
	{
		//cout << year << " is not a leap year.";
		//is not a leap year
		listOfMonths.february = 28;
	}
	else if (year % 4 == 0)
	{
		//cout << year << " is a leap year.";
		//is a leap year
		listOfMonths.february = 29;
	}
	else
	{
		//cout << year << " is not a leap year.";
		//is not a leap year
		listOfMonths.february = 28;
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

//using zellers algo
string weekday[7] = {"Monday","Tuesday", "Wednesday","Thursday","Friday", "Saturday","Sunday", };
int dayOfTheWeek(int year, int month, int day) {
	int uMonth;
	int lastTwo = year % 100;
	int firstTwo = year / 100;
	if (month > 2) //not worrying about leap years
		uMonth = month; 
	else { //dealing with leap years by adding 12 and decreasing year
		uMonth = month+12; 
		year--;
	} 
	int res = (day + floor((13 * (uMonth + 1)) / 5) + lastTwo + floor(lastTwo / 4) + floor(firstTwo / 4) + (5 * firstTwo));
	int resMod = res % 7;
	//remap 0,1 from sat sun to monday tues
	switch (resMod) {
	case 0:
		res = 5;
		break;
	case 1:
		res = 6;
		break;
	case 2:
		res = 0;
		break;
	case 3:
		res = 1;
		break;
	case 4:
		
		res = 2;
		break;
	case 5:
		res = 3;
		break;
	case 6:
		res = 4;
		break;
	}
	return res;
}

void printOutCal(int year, int month) {
	//keep count of the spacing in the first week to add to the day cout
	int countOfSpacing = 0;
	//print out the header
	cout << "Year: " << year << "   Month: " << month << "\n";
	cout << "Mon  " << "Tue  " << "Wed  " << "Thu  " << "Fri  " << "Sat  " << "Sun  \n";
	
	//get the count of days
	int daysInMonth = daysLong(year, month);
	//get the starting day 
	int startingDay = dayOfTheWeek(year, month, 1);

	//put spacing before
	for (int i = 0; i < startingDay; i++) {
		if (startingDay > 0) {

			countOfSpacing++;
			cout << "     ";

		}
	}


	//get it working from monday
	for (int i = 1; i <= daysInMonth; i++) {
		if ((i+countOfSpacing) % 7 == 0) {
			cout << i << "\n";
		}
		else {
			if (i > 9) {
				cout << i << "   ";
			}
			else {
				cout << i << "    ";
			}
		}
	}

	cout << "\n\nStarting Day: " << weekday[startingDay];
}