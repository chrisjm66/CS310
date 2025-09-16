#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>

using namespace std;


int hold() {
	// Math Class
	const double PI = acos(-1);
	double noFraction = 2;
	double largeValue = pow(PI, 20);
	cout << "Default Display:" << endl;
	cout << PI << '\t' << noFraction << '\t' << largeValue << endl;

	cout << showpoint; // shows non decimal values with 6 digits by default
	cout << "Using showpoint: " << endl;
	cout << PI << '\t' << noFraction << '\t' << largeValue << '\n' << endl;

	cout << noshowpoint; // does the opposite

	cout << "Fixed Precision Display:" << endl;
	cout << fixed << setprecision(10); // fixed shows scientific values in nonscientific form
	cout << PI << '\t' << noFraction << '\t' << largeValue << '\n' << endl;

	cout << left; // sets alignment of setw to left

	cout << setw(15) << "2023 Fall" << setw(10) << "Python" << endl; // sets line width of next string
	cout << setw(15) << "2024 Spring" << setw(10) << "Java" << endl;
	cout << setw(15) << "2024 Fall" << setw(10) << "Python" << endl;
	cout << setw(15) << "2025 Spring" << setw(10) << "C++" << endl;


	string goal;
	cout << "What is your fitness goal?" << endl;
	getline(cin, goal);
	cout << "You would like to " << goal << endl;

	int age;
	cout << "How old are you?" << endl;
	cin >> age;

	while (cin.fail()) {
		cout << "Bad Input. Please enter a number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> age;
	}

	cout << "Your age: " << age << endl;
	cout << "What is your name? " << endl;

	string name;
	cin.ignore(); // this ignores only one char or \n (default case)
	getline(cin, name);

	cout << "Welcome, " << name << endl;

	return 0;
}

