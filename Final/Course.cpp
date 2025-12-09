#include "Course.h"
#include <iostream>

Course::Course(string name, int capacity) {
	courseName = name;
	this->capacity = capacity;
	students = new Student[capacity];
}

Course::~Course() {
	delete[] students;
}
string Course::getCourseName() {
	return courseName;
}

void Course::addStudent(Student student) {
	if (capacity == numberOfStudents) {
		cout << "Course full." << endl;
	}
	else {
		students[numberOfStudents] = student;
		numberOfStudents++;
	}
}

void Course::dropStudent(Student& student) {
	bool found = false;

	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].getStudentId() == student.getStudentId()) {
			found = true;
		}

		if (found) {
			students[i] = students[i + 1];
		}
	}

	if (found) {
		numberOfStudents--;
	}
}

Student* Course::getStudents() {
	return students;
}

int Course::getNumberOfStudents() {
	return numberOfStudents;
}