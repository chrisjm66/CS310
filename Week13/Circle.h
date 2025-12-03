#pragma once
#include "Point.h"
#include "Shape.h"

class Circle: public Shape
{
private:
	double radius;
public:
	Circle();
	Circle(double initialR, Point& c, string color);
	double getRadius();
	void setRadius(double newR);
	void print();
	string toString();
	bool operator==(Circle& other);
	double getArea();
	~Circle();//destructor
};

