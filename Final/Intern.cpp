#include "Intern.h"
#include <string>

using namespace std;

Intern::Intern(string name, int id, double gpa, string company) :Student(name, id, gpa) {
	this->company = company;
}

string Intern::getCompany() {
	return company;
}

void Intern::setCompany(string company) {
	this->company = company;
}

string Intern::toString() {
	return "Intern: " + this->getName() + ", ID: " + to_string(this->getStudentId()) + ", GPA: " + to_string(this->getGPA()) + ", Company: " + company;
}