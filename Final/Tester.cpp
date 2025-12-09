#include <iostream>
#include <iomanip>
#include <string>
#include "Student.h"
#include "Graduate.h"
#include "Intern.h"
#include "Course.h"

using namespace std;

double bestGpa(Student** students, int size) {
	double highestGpa = 0;

	for (int i = 0; i < size; i++) {
		double currentGpa = students[i]->getGPA();

		if (currentGpa > highestGpa) {
			highestGpa = currentGpa;
		}
	}

	return highestGpa;
}

int main() {
	const int NUM_STUDENTS = 4;
	Student** students = new Student*[4];

	Student james("James", 1, 3.5);
	cout << james.toString() << endl;

	Intern henry("Henry", 2, 4, "Google");
	Intern angel("Angel", 3, 3.8, "Facebook");

	cout << henry.toString() << endl;
	cout << angel.toString() << endl;

	Graduate oliver("Oliver", 4, 4, 96.5);
	cout << oliver.toString() << endl;

	students[0] = &james;
	students[1] = &henry;
	students[2] = &angel;
	students[3] = &oliver;

	double best = bestGpa(students, NUM_STUDENTS);

	cout << "\nI will now print the students with the best GPA (" + to_string(best) + "):" << endl;
	for (int i = 0; i < NUM_STUDENTS; i++) {
		if (students[i]->getGPA() == best) {
				cout << students[i]->toString() << endl;
		}
	}

	Course cpp("C++ Programming", 10);
	cout << "\nCourse: " << cpp.getCourseName() << ", Students: " << cpp.getNumberOfStudents() << endl;

	cpp.addStudent(james);
	cpp.addStudent(oliver);
	cpp.dropStudent(oliver);

	Student* courseStudents = cpp.getStudents();
	for (int i = 0; i < cpp.getNumberOfStudents(); i++) {
		cout << courseStudents[i].toString() << endl;
	}

	delete[] students;
}