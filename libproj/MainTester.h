#ifndef MAINTESTER_H    
#define MAINTESTER_H

void Lab1PartA();
void Lab1PartB();
void Lab1PartC();
void Lab2();


/**
*
* Makes a 5 pointed star
*
* @param x The X position in the window to start drawing the star
* @param y The Y position in the window to start drawing the star
* @param length The segment length for each line on the star
* @param color The color you wish the star to be filled with
*
*/
void drawStar(const int x, const int y, const int length, const int color);
void loneStar(const int x, const int y);
void rowOfStars(const int x, const int y, const int starCount, const int size);
void drawAmericanFlag(const int x, const int y, const int size);

#endif