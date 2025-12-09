#pragma once
#include "Student.h"
#include <string>

using namespace std;

class Intern : public Student
{
private:
	string company;
public:
	Intern(string name, int id, double gpa, string company);
	string getCompany();
	void setCompany(string company);
	string toString();
};

