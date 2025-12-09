#pragma once
#include "Student.h"
#include <string>

class Graduate: public Student
{
private:
	double hours;

public:
	Graduate(string name, int id, double gpa, double hours);
	double getHours();
	void setHours(double hours);
	string toString();
};

