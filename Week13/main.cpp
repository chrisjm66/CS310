#include <iostream>
#include <iomanip>
#include<string>

#include "Rectangle.h"
#include "Circle.h"
using namespace std;

void move(Shape& shape, double deltaX, double deltaY) {
	shape.move(deltaX, deltaY);
}

void resize(Shape* obj) {
	Circle* c = dynamic_cast<Circle*>(obj);

	if (c != nullptr) {
		c->setRadius(c->getRadius() * 2);
	}

	Rectangle* r = dynamic_cast<Rectangle*>(obj);
	if (r != nullptr) {
		r->setLength(r->getLength() * 2);
		r->setWidth(r->getWidth() * 2);
	}
	
}

Shape* smaller(Shape* s1, Shape* s2) {
	if (s1->getArea() < s2->getArea()) {
		return s1;
	}
	else {
		return s2;
	}
}

double smallestArea(Shape* shapes[], int size) {
	double smallest = shapes[0]->getArea();

	for (int i = 0; i < size; i++)
	{
		if (shapes[i]->getArea() < smallest) {
			smallest = shapes[i]->getArea();
		}
	}

	return smallest;
}

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

	Point location(2, 3);

	Circle shape1(1, location, "blue");
	cout << fixed << setprecision(2) << shape1.toString() << endl;
	move(shape1, 5, 7);
	cout << fixed << setprecision(2) << shape1.toString() << endl;
	Shape s = shape1;
	cout << fixed << setprecision(2) << s.toString() << endl; // this wont print since itll ask for the Shape::tostring() not Circle::toString()

	// to fix this change s2 to a reference or pointer
	Shape& s2 = shape1;
	cout << fixed << setprecision(2) << s2.toString() << endl;

	resize(&shape1);
	cout << "doubled? " << shape1.toString() << endl;

	Point center(0, 0);
	Circle* otherShape = new Circle(3.0, center, "red");
	cout << smaller(&shape1, otherShape)->toString() << " is smaller" <<  endl;

	Shape* shapes[5];
	for (int i = 0; i < 5; i++) {
		Point point(i * 5, i * 3);
		shapes[i] = new Circle(i + 5, point, "color");
	}

	cout << smallestArea(shapes, 5);
	delete[] shapes;

	delete otherShape;
}