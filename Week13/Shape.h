#pragma once
#include "Point.h"
#include <string>

using namespace std;

class Shape
{
private:
	string color;
	Point location;
public:
	Shape();
	Shape(const string& col, const Point& loc);
	string getColor();
	Point getLocation();
	void setColor(const string& newColor);
	void move(double deltaX, double deltaY);
	virtual string toString(); // polymorphic function
	virtual double getArea();
};

