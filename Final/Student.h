#pragma once
#include <string>

using namespace std;

class Student
{
private:
	string name;
	int studentId;
	double gpa;

public:
	Student();
	Student(string name, int id, double gpa);
	string getName();
	void setName(string name);
	int getStudentId();
	double getGPA();
	void setGPA(double gpa);
	virtual string toString();
};

