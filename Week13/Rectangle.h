#pragma once
#include <string>
#include "Shape.h"
#include "Point.h"

using namespace std;

class Rectangle: public Shape // is a relationship (inheritance)
{
private:
	double length;
	double width;

public:
	Rectangle();
	Rectangle(const double& len, const double& wid);
	Rectangle(const double& len, const double& wid, const string& col, const Point& corner);

	double getLength();
	double getWidth();
	void setLength(const double& newLen);
	void setWidth(const double& newWid);
	double getArea();

	string toString();
};

