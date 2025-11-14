#include "Course.h"
#include <iostream>

using namespace std;

int main() {
	cout << "Courses: " << Course::getNumOfCourses() << endl;
	Course cs310("CS310", 4);
	cout << "Course Name: " << cs310.getCourseName() << endl;
	cout << "# of Students: " << cs310.getNumStudents() << endl;
	cs310.printStudents();

	cs310.enroll("John");
	cs310.enroll("Kevin");
	cs310.enroll("Ava");
	cs310.enroll("Joe");

	cout << "# of Students: " << cs310.getNumStudents() << endl;
	cs310.printStudents();

	cs310.enroll("Anna");

	cout << "# of Students: " << cs310.getNumStudents() << endl;
	cs310.printStudents();

	cs310.drop("Kevin");
	cout << "# of Students: " << cs310.getNumStudents() << endl;
	cs310.printStudents();

	cs310.drop("John");
	cs310.drop("Anna");
	cs310.drop("Joe");
	cs310.drop("Ava");

	cs310.enroll("bob");
	cs310.printStudents();
	cout << "Courses: " << Course::getNumOfCourses() << endl;
	
	Course cs310SP("CS310SP", 4);
	cout << "Courses after new init: " << Course::getNumOfCourses() << endl;
	cs310SP = cs310;
	Course* idk = new Course("idk", 5);
	cout << "Courses after another one init: " << Course::getNumOfCourses() << endl;

	delete idk;

	cout << "Courses after delete: " << Course::getNumOfCourses() << endl;
	cout << "Tostring: " << cs310SP.toString();
	return 0;
}