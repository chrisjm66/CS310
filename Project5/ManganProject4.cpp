// Chris Mangan
// Project #3
#include<iostream>
#include<string>
#include <iomanip>
#include <cmath>
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
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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

	return gender;
}

void printMenu() {
	cout << "Please select an option: [A]dd data; [R]ecent Data; [V]iew history; [E]xit program" << endl;
}

char getOption(bool reprompt = false) {
	string prompt;
	if (reprompt) {
		prompt = string("The selected option is invalid.");
	}
	else {
		printMenu();
	}

	return getInput<char>(prompt);
}

template <typename T>
void shiftItemsOne(T array[], const int SIZE) {
	for (int i = SIZE - 1; i > 0; i--) {
		array[i] = array[i - 1];
	}
}

void addData(double weights[], string exerciseTypes[], int times[], const int& SIZE) {
	shiftItemsOne(weights, SIZE);
	shiftItemsOne(exerciseTypes, SIZE);
	shiftItemsOne(times, SIZE);

	weights[0] = getInput<double>("Please enter your weight in kg.");
	times[0] = getInput<int>("Please enter your exercise time in minutes.");
	exerciseTypes[0] = getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");
}

void printBasicInfo(const string& name, const char& gender, const int& age, const double& height) {
	cout << "\tName: " << name << endl;
	cout << "Gender: " << gender << ", Age: " << age << ", Height: " << height << "m" << endl;
}

void printHistoryData(
	const string& name,
	const char& gender,
	const int& age,
	const double weights[],
	const double& height,
	const string exerciseTypes[],
	const int exerciseTimes[],
	const int& SIZE,
	const int& userEntries) {

	if (userEntries == 0) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	printBasicInfo(name, gender, age, height);
	cout << "------------------" << endl;

	for (int i = 0; i < min(SIZE, userEntries); i++) { // the min function is to prevent bad data being displayed if the user enters less than 7 pieces of data
		cout << "Weight: " << weights[i] << "kg, BMI: " << weights[i] / (height * height) << " kg/m2" << endl;
		cout << "Exercise: " << exerciseTypes[i] << " (" << exerciseTimes[i] << "mins)" << endl;
		cout << "---------------------------------------------------------------" << endl;
	}
}

void printRecentData(
	const string& name,
	const char& gender,
	const int& age,
	const double weights[],
	const double& height,
	const string exerciseTypes[],
	const int exerciseTimes[],
	const int& userEntries) {

	if (userEntries == 0) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	printBasicInfo(name, gender, age, height);

	cout << "Weight: " << weights[0] << "kg, BMI: " << weights[0] / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << exerciseTypes[0] << " (" << exerciseTimes[0] << "mins)" << endl;
}

void getBasicInfo(string& name, char& gender, int& age, double& height) {
	name = getInput<string>("Please enter your name.");
	gender = getGender("Please enter your gender (M/F).");
	age = getInput<int>("Please enter your age.");
	height = getInput<double>("Please enter your height in meters.");
}

int main() {
	const int SIZE = 7;
	int userEntries = 0;
	int exerciseTimes[SIZE];
	double weights[SIZE];
	string exerciseTypes[SIZE];

	string name;
	int age;
	char gender, userOption;
	bool isValidUserOption;
	double height;

	getBasicInfo(name, gender, age, height);

	userOption = getOption();

	while (true) {
		switch (userOption) {
		case 'e':
		case 'E':
			return 0;
			break;
		case 'A':
		case 'a':
			addData(weights, exerciseTypes, exerciseTimes, SIZE);
			userOption = getOption();
			userEntries++;
			break;
		case 'R':
		case 'r':
			printRecentData(name, gender, age, weights, height, exerciseTypes, exerciseTimes, userEntries);
			userOption = getOption();
			break;
		case 'V':
		case 'v':
			printHistoryData(name, gender, age, weights, height, exerciseTypes, exerciseTimes, SIZE, userEntries);
			userOption = getOption();
			break;
		default:
			userOption = getOption(true);
		}
	}

	return 0;
}
