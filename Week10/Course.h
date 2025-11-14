#pragma once
#include <string>

using namespace std;

class Course {
private:
	static int numCourses;
	string name;
	string* students;
	int numStudents;
	int capacity;
	void expandArray();
	void removeElement(int index);
	void append(string value);

public:
	Course(const string& name, int capacity);

	Course(const Course& course);

	Course& operator = (const Course& other);

	~Course();

	string getCourseName();

	void enroll(const string& studentName);

	void drop(const string& studentName);

	void printStudents();

	int getNumStudents();

	static int getNumOfCourses();

	string toString();
};
