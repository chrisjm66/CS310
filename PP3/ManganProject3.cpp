// Chris Mangan
// Project #2
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;

bool isGenderValid(char gender) {
	return gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F';
}

template <typename T>
T getInput(const string& prompt) { // const doesn't let it change (final) and we can use the reference since we aren't changing it anyway. saves RAM!
	T input;
	cout << prompt << endl;
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid entry, please try again.";
		cin >> input;
	}

	return input;
}

template <>
string getInput<string>(const string& prompt) {
	string input;
	cout << prompt << endl;
	getline(cin, input);

	return input;
}

char getGender(const string& prompt) {
	char gender;

	cout << prompt << endl;
	cin >> gender;
	while (cin.fail() || !isGenderValid(gender)) {
		cout << prompt << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this ignores the max length of the stream size
		cin >> gender;
	}
}

char getUserOption(bool reprompt = false) {
	string prompt;
	if (reprompt) {
		prompt = string("Please select an option: [A]dd data; [R]ecent Data; [E]xit program");
	}
	else {
		prompt = string("Please enter a valid option.");
	}

	char selection = getInput<char>(prompt);


	return selection;
}

string addData() {
	double weight = getInput<double>("Please enter your weight in kg.");
	double height = getInput<double>("Please enter your height in meters.");
	string exerciseType = getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");
	int time = getInput<int>("Please enter your exercise time in minutes.");

	string data = "Weight: " + weight + "kg, BMI: " + setprecision(2) + weight / (height * height) + " kg/m2" + endl + "Exercise: " + exerciseType + " (" << time << "mins)" << endl;
}

int main() {
	string name, exerciseType;
	int age, exerciseTime;
	char gender, userOption;
	bool isValidUserOption;

	name = getInput<string>("Please enter your name.");
	gender = getGender("Please enter your gender (M/F).");
	age = getInput<int>("Please enter your age.");
	height = getInput<int>("Please enter your height in meters.");
	userOption = getUserOption();
	
	while (true) {
		switch (userOption) {
		case 'e':
		case 'E':
			return 0;
			break;
		case 'A':
		case 'a':
			addData();
			break;
		case 'R':
		case 'r':
			showRecentData();
			break;
		default:
			getUserOption(true);
		}
	}

	

	// copied from project 1
	cout << "\t" << name << endl;
	cout << fixed << setprecision(2) << gender << ", " << age << ", " << height << "m" << endl;
	

	return 0;
}
