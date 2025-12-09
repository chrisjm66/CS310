#pragma once
#include <string>
#include "Student.h"

using namespace std;

class Course
{
private:
	string courseName;
	Student* students;
	int numberOfStudents;
	int capacity;

public:
	Course(string name, int capacity);
	~Course();
	string getCourseName();
	void addStudent(Student student);
	void dropStudent(Student& student);
	Student* getStudents();
	int getNumberOfStudents();
};

