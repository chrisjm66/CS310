#include "Shape.h"
#include <string>
#include "Point.h"

using namespace std;

Shape::Shape():Shape("black", Point(0, 0)) {

}

Shape::Shape(const string& col, const Point& loc) {
	color = col;
	location = loc;
}

string Shape::getColor() {
	return color;
}

Point Shape::getLocation() {
	return location;
}

void Shape::setColor(const string& newColor) {
	color = newColor;
}

void Shape::move(double deltaX, double deltaY) {
	location.setX(location.getX() + deltaX);
	location.setY(location.getY() + deltaY);
}

double Shape::getArea() {
	return 0.0;
}

string Shape::toString() {
	return to_string(location.getX()) + ", " + to_string(location.getY()) + " with color " + color;
}