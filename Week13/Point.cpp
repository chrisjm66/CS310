#include "Point.h"
#include <iostream>
using namespace std;
Point::Point()
{
	x = y = 0;
}
Point::Point(double initialX, double initialY)
{
	x = initialX;

	y = initialY;
}
double Point::getX()
{
	return this->x;
}
double Point::getY()
{
	return this->y;
}
void Point::setX(double newX)
{
	x = newX;
}
void Point::setY(double newY)
{
	y = newY;
}
void Point::print()
{
	cout << "( " << x << "," << y << ")";
}