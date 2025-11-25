#pragma once //avoid a class defined mutltiple times
#ifndef POINT_H //same as pragma once
#define POINT_H
class Point
{
private:
	double x, y;
public:
	Point();//function prototype
	Point(double initialX, double intitialY);
	double getX();
	double getY();
	void setX(double newX);
	void setY(double newY);
	void print();
};


#endif // !POINT_H

