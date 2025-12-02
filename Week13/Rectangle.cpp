#include "Rectangle.h"

Rectangle::Rectangle():Shape() { // this turns it into a shape object too
	width = length = 1;
}

Rectangle::Rectangle(const double& len, const double& wid) :Shape() {
	width = wid >= 0 ? wid : 1;
	length = len >= 0 ? len : 1;
}

Rectangle::Rectangle(const double& len, const double& wid, const string& col, const Point& corner):Shape(col, corner) {
	width = wid >= 0 ? wid : 1;
	length = len >= 0 ? len : 1;
}

double Rectangle::getLength() {
	return length;
}

double Rectangle::getWidth() {
	return width;
}

void Rectangle::setLength(const double& newLen) {
	length = newLen;
}

void Rectangle::setWidth(const double& newWid) {
	width = newWid;
}

double Rectangle::getArea() {
	return length * width;
}

string Rectangle::toString() {
	return Shape::toString() +
		", rectangle length " + to_string(length) + ", width " + to_string(width);
}