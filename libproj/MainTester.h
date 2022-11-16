#ifndef MAINTESTER_H    
#define MAINTESTER_H

void Lab1PartA();
void Lab1PartB();
void Lab1PartC();
void Lab2();
void Lab3();
void Lab4();
void Lab5();
void Lab6();
void Lab8();
void Lab9();

//Lab 1
void drawCircle(int x, int y, int steps, int segmentLen);

//Lab 2
void drawStar(const int x, const int y, const int length, const int color);
void loneStar(const int x, const int y);
void rowOfStars(const int x, const int y, const int starCount, const int size);
void drawAmericanFlag(const int x, const int y, const int size);

//Lab 3
void count(int a, int b);
int countUpBy5(int a, int b);
void dotsStarsDots(int d1, int s1, int d2);
void asciArt(int a, int b);
void drawCannon(int x, int y, double angle);

//Lab 4
struct FiringPoint;
FiringPoint drawCannonAndReturnFiringPoint(int x, int y, double angle);
void drawFiringLine(int xLoc, int yLoc, double velocity);
void drawHQ(int x);

//Lab 5
void drawClock();

//Lab 6 
int daysLong(int year, int month);
int dayOfTheYear(int year, int month, int day);
int dayOfTheCentury(int year, int month, int day);
int dayFromYearZero(int year, int month, int day);
int dayOfTheWeek(int year, int month, int day);
void printOutCal(int year, int month);

//Lab 8
struct Button;
void drawButton(Button button);
void drawGrid();

#endif