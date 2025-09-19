#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

int mainl() {
	int positiveInt = 0;
	cout << "Enter  a value and I will tell you if its prime: " << endl;
	cin >> positiveInt;
	while (cin.fail() || positiveInt < 0) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Invalid input, please enter a positive integer." << endl;
		cin >> positiveInt;
	}

	int counter = 0;
	for (int divisor = 2; divisor < positiveInt; divisor++) {
		if (positiveInt % divisor == 0) {
			counter++;
			cout << positiveInt << " is not prime." << endl;
			break;
		}
	}

	if (counter == 0) {
		cout << "Your number is prime." << endl;
	}


	cout << "Your numerical grade: " << endl;
	int grade;
	cin >> grade;
	while (cin.fail() || grade < 0 || grade > 100) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "Invalid input, please enter an integer." << endl;
		cin >> grade;
	}

	char letter;

	if (grade >= 90) {
		letter = 'A';
	}
	else if (grade >= 80) {
		letter = 'B';
	}
	else if (grade >= 70) {
		letter = 'C';
	} 
	else {
		letter = 'F';
	}

	cout << "Your number grade: " << grade << endl;
	cout << "Your letter grade: " << letter << endl;

	double gpa = 0;
	switch (letter) {
	case 'A':
		gpa = 4.0;
		break;
	case 'B':
		gpa = 3.0;
		break;
	case 'C':
		gpa = 2.0;
		break;
	default:
		gpa = 0;
		break;
	}

	cout << "Your GPA: " << fixed << setprecision(1) << gpa << '\n' << endl;
	// -------------- \\

	double pi = acos(-1);

	cout << left << fixed << setprecision(4);
	cout << setw(10) << "Degrees"
		<< setw(10) << "Radians"
		<< setw(10) << "Sine"
		<< setw(10) << "Cosine"
		<< setw(10) << "Tangent"
		<< endl;

	cout << "--------------------------------------------------" << endl;

	for (int i = 0; i <= 360; i += 30) { // same syntax as java
		double rad = i * pi / 180;

		cout <<
			setw(10) << i
			<< setw(10) << rad
			<< setw(10) << sin(rad)
			<< setw(10) << cos(rad)
			<< setw(10) << tan(rad) << endl;
	}

	return 0;
}