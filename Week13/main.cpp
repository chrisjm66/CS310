#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
	Rectangle* rectangles = new Rectangle[2];

	Rectangle* defaultRectangle = new Rectangle();
	cout << defaultRectangle->toString() << endl;

	defaultRectangle->setLength(.1);
	defaultRectangle->setWidth(.1);
	defaultRectangle->move(10, 12);
	cout << defaultRectangle->toString() << endl;

	Rectangle* rectangle1 = new Rectangle(3.0, 4.0);
	cout << rectangle1->toString() << endl;

	rectangles[0] = *defaultRectangle;
	rectangles[1] = *rectangle1;

	
	delete[] rectangles;
	delete defaultRectangle;
	delete rectangle1;

	Shape* shape1 = new Rectangle(4.0, 5.0, "red", Point(1.0, 2.0));
	cout << shape1->toString() << endl;
	delete shape1;
}