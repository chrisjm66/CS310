#include "Graduate.h"

Graduate::Graduate(string name, int id, double gpa, double hours):Student(name, id, gpa) {
	this->hours = hours;
}

double Graduate::getHours() {
	return hours;
}

void Graduate::setHours(double hours) {
	this->hours = hours;
}

string Graduate::toString() {
	return "Graduate: " + this->getName() + ", ID: " + to_string(this->getStudentId()) + ", GPA: " + to_string(this->getGPA()) + ", Hours: " + to_string(hours);
}