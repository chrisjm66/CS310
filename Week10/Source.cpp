#include "Course.h"
#include <iostream>

using namespace std;

int main() {
	Course course("CS310", 4);
	cout << "Course Name: " << course.getCourseName() << endl;
	cout << "# of Students: " << course.getNumStudents() << endl;
	course.printStudents();

	course.enroll("John");
	course.enroll("Kevin");
	course.enroll("Ava");
	course.enroll("Joe");

	cout << "# of Students: " << course.getNumStudents() << endl;
	course.printStudents();

	course.enroll("Anna");

	cout << "# of Students: " << course.getNumStudents() << endl;
	course.printStudents();

	course.drop("Kevin");
	cout << "# of Students: " << course.getNumStudents() << endl;
	course.printStudents();
}