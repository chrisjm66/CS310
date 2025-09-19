// Chris Mangan
// Project #2
#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

bool isGenderValid(char gender) {
	return gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F';
}

int main() {
	string name, exerciseType;
	int age, exerciseTime;
	double height, weight;
	char gender;

	cout << "Please enter your name." << endl;
	getline(cin, name);

	cout << "Please enter your gender (M/F)." << endl;
	cin >> gender;
	while (cin.fail() || !isGenderValid(gender)) {
		cout << "Bad Input. Please enter M or F." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> gender;
	}

	cout << "Please enter your age." << endl;
	cin >> age;
	while (cin.fail()) {
		cout << "Bad Input. Please enter a valid integer." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> age;
	}

	cout << "Please enter your height in meters." << endl;
	cin >> height;
	while (cin.fail()) {
		cout << "Bad Input. Please enter a valid decimal number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> height;
	}

	cout << "Please enter your weight in kg." << endl;
	cin >> weight;
	while (cin.fail()) {
		cout << "Bad Input. Please enter a valid decimal number." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> weight;
	}

	cin.ignore(); // so we ignore the \n from previous command
	cout << "Please enter your exercise type (eg. running, walking, lifting)." << endl;
	getline(cin, exerciseType);

	cout << "Please enter your exercise time in minutes." << endl;
	cin >> exerciseTime;
	while (cin.fail()) {
		cout << "Bad Input. Please enter a valid integer." << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> exerciseTime;
	}

	// copied from project 1
	cout << "\t" << name << endl;
	cout << fixed << setprecision(2) << gender << ", " << age << ", " << height << "m" << endl;
	cout << setprecision(1) << "Weight: " << weight << "kg, BMI: " << setprecision(2) << weight / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << exerciseType << " (" << exerciseTime << "mins)" << endl;

	return 0;
}
