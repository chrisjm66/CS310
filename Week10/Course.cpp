#include "Course.h"
#include <string>
#include <iostream>

using namespace std;

int Course::numCourses = 0;

void Course::expandArray() {
	if (capacity == 0) {
		capacity = 1;
	}
	string* newArray = new string[capacity * 2];

	for (int i = 0; i <  numStudents; i++) {
		newArray[i] = students[i];
	}

	capacity *= 2;
	delete[] students;
	students = newArray;
}

void Course::removeElement(int index) {
	if (index >= numStudents || index < 0 || numStudents <= 0) {
		throw new bad_array_new_length();
	}


	if (numStudents == 1) {
		delete[] students;
		students = nullptr;
		numStudents = 0;
		capacity = 0;

	}
	else {
		string* newArray = new string[capacity - 1];
		capacity = numStudents - 1;

		for (int i = 0; i < index; i++) {
			newArray[i] = students[i];
		}

		for (int i = index + 1; i < numStudents; i++) {
			newArray[i - 1] = students[i];
		}

		delete[] students;
		students = newArray;
		numStudents--;
		capacity = numStudents;
	}
}

void Course::append(string value) {
	if (numStudents == capacity) {
		expandArray();
	}

	students[numStudents] = value;
	numStudents++;
}

Course::Course(const string& name, int capacity) {
	this->name = name;
	this->capacity = capacity;
	students = new string[capacity];
	numStudents = 0;
	numCourses++;
}

Course::Course(const Course& course) {
	this->name = course.name;
	this->capacity = course.capacity;
	this->numStudents = course.numStudents;
	students = new string[capacity];

	for (int i = 0; i < numStudents; i++) {
		this->students[i] = course.students[i];
	}
	
	numCourses++;
}

Course& Course::operator= (const Course& other) {
	if (this != &other) {
		// release old array
		delete[] this->students;
		this->numStudents = other.numStudents;
		this->capacity = other.capacity;
		this->name = other.name;
		this->students = new string[other.capacity];

		for (int i = 0; i < numStudents; i++) {
			this->students[i] = other.students[i];
		}

	}

	return *this;
}

Course::~Course() {
	numCourses--;
	delete[] students;
}

string Course::getCourseName() {
	return this->name;
}

void Course::enroll(const string& studentName) {
	append(studentName);
}

void Course::drop(const string& studentName) {
	for (int i = 0; i < numStudents; i++) {
		if (students[i] == studentName) {
			removeElement(i);
			break;
		}
	}
}

void Course::printStudents() {
	cout << "Students" << endl;
	cout << "------------------" << endl;

	for (int i = 0; i < numStudents; i++) {
		cout << students[i] << endl;
	}
	cout << endl;
}

int Course::getNumStudents() {
	return this->numStudents;
}

int Course::getNumOfCourses() {
	return numCourses;
}

string Course::toString() {
	string str = name + " " + to_string(capacity);

	for (int i = 0; i < numStudents; i++) {
		str += " " + students[i];
	}

	return str;
}