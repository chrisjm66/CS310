#include "Circle.h"
#include <iostream>
#include <cmath>
using namespace std;

Circle::Circle()
{
	radius = 0;
}

Circle::Circle(double initialR, Point& c, string color):Shape(color, c)
{
	radius = initialR > 0 ? initialR : 0;
}

double Circle::getRadius()
{
	return radius;
}

void Circle::setRadius(double newR)
{
	radius = newR > 0 ? newR : radius;
}

void Circle::print()
{
	cout << "Circle at ";
	cout << Shape::toString() <<
	", radius: " << radius << endl;
}

string Circle::toString() {
	return "Circle: " + Shape::toString() + ", radius: " + to_string(radius);
}

bool Circle::operator==(Circle& other)
{
	if (this->radius == other.radius)
		return true;
	else
		return false;
}

Circle::~Circle()
{
	
}

double Circle::getArea() {
	return radius * radius * 3.14159;
}