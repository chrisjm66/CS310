#include "Student.h"
#include <string>

using namespace std;

Student::Student() {
	name = "Default Student";
	studentId = 1;
	gpa = 0;
}

Student::Student(string name, int id, double gpa) {
	this->name = name;
	this->studentId = id;
	this->gpa = gpa;
}

string Student::getName() {
	return name;
}
void Student::setName(string name) {
	this->name = name;
}

int Student::getStudentId() {
	return studentId;
}

double Student::getGPA() {
	return gpa;
}

void Student::setGPA(double gpa) {
	this->gpa = gpa;
}

string Student::toString() {
	return "Student: " + name + ", ID: " + to_string(studentId) + ", GPA: " + to_string(gpa);
}