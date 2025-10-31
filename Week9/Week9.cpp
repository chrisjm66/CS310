#include <iostream>
#include <string>
#include<vector>

using namespace std;

struct Date {
	int day, month, year;
};

struct Student {
	int id;
	string name;
	string major;
	double gpa;
	Date dob;
};

void printStudent(const Student& student) {
	cout << endl;
	cout << "Student: " << student.name << " DOB: " << student.dob.month << "/" << student.dob.day << "/" << student.dob.year << endl;
	cout << " Major: " << student.major << endl;
	cout << "GPA: " << student.gpa << " ID: " << student.id << endl;
}

void updateGPA(Student& student, double newGPA) {
	student.gpa = newGPA;
}

Student getStudent() {
	Student stu;

	cout << "Name: ";
	getline(cin, stu.name);

	cin.ignore(1000, '\n');
	cout << "Major: ";
	getline(cin, stu.major);

	cout << "GPA: ";
	cin >> stu.gpa;

	cout << "ID: ";
	cin >> stu.id;

	cout << "Date of birth (dd month year)";
	cin >> stu.dob.day >> stu.dob.month >> stu.dob.year;

	cin.ignore(1000, '\n');

	return stu;
}
/*
int main() {
	Student me;
	me.id = 1383755;
	me.name = "Chris";

	Student someone = { 123, "Bob", "CS", 3.9 };
	cout << me.id << endl;
	cout << me.name << endl;
	cout << "Address: " << &me << endl;
	cout << "Name located at: " << &me.name << endl;
	cout << "id located at: " << &me.id << endl;

	printStudent(me);
	printStudent(someone);

	updateGPA(me, 4);
	printStudent(me);

	int size = 0;
	cout << "Students in class: ";
	cin >> size;

	Student* pStudents = new Student[size];
	vector<Student> students(size);

	for (int i = 0; i < size; i++) {
		Student student = getStudent();
		pStudents[i] = student;

		students.push_back(student);
		printStudent(student);
	}

	Student* p = &me;
	//p->id; getting id
	// or (*p).id;

	delete[] pStudents;
	delete[] &students;

	return 0;
}*/