#ifndef MAINTESTER_H    
#define MAINTESTER_H

void Lab1PartA();
void Lab1PartB();
void Lab1PartC();
void Lab2();
void Lab3();

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
void drawCannon(int x, int y, int angle);
#endif