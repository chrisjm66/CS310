#include "HealthTracker.h"
#include "Helper.h"
#include <iostream>
#include <string>
using namespace std;

void HealthTracker::printMenu() {
	cout << "Please select an option: [A]dd data; [R]ecent Data; [V]iew history; [E]xit program" << endl;
}

char HealthTracker::getOption(bool reprompt = false) {
	string prompt("");
	if (reprompt) {
		prompt = string("The selected option is invalid.");
	}
	else {
		printMenu();
	}

	return Helper::getInput<char>(prompt);
}

bool HealthTracker::isGenderValid(const char& gender) {
	return gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F';
}

char HealthTracker::getGender(const string& prompt) {
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

void HealthTracker::printBasicInfo() {
	cout << "\tName: " << name << endl;
	cout << "Gender: " << gender << ", DOB: " << dateOfBirth.toString() << ", Height: " << height << "m" << endl;
}

HealthTracker::HealthTracker() {
	capacity = 1;
	days = -1;
	history = new FitnessRecord[capacity];

	name = Helper::getInput<string>("Please enter your name.");
	gender = getGender("Please enter your gender (M/F).");
	height = Helper::getInput<double>("Please enter your height in meters.");

	int month = Helper::getInput<int>("Please enter birth month (1-12): ");
	int day = Helper::getInput<int>("Please enter birth day (1-31): ");
	int year = Helper::getInput<int>("Please enter birth year (4 year format; ie 2000): ");
	dateOfBirth = Date(month, day, year);
}

HealthTracker::~HealthTracker() {
	delete[] history;
}

void HealthTracker::inputData() {
	double weight = Helper::getInput<double>("Please enter your weight in kg.");
	int time = Helper::getInput<int>("Please enter your exercise time in minutes.");
	string exerciseType = Helper::getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");
	int month = Helper::getInput<int>("Please enter record month (1-12): ");
	int day = Helper::getInput<int>("Please enter record day (1-31): ");
	int year = Helper::getInput<int>("Please enter record year (4 year format; ie 2000): ");
	Date date(month, day, year);

	days++;

	if (capacity == days) { // double array sizes if index == size
		history = Helper::resizeArray(history, capacity);
		capacity *= 2;
	}

	FitnessRecord* newRecord = new FitnessRecord(weight, exerciseType, time, date);

	history[days] = *newRecord;
}

void HealthTracker::printHistoryData() {
	if (days == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}
	int totalExerciseTime = 0;

	printBasicInfo();
	cout << "------------------" << endl;

	for (int i = days; i >= 0; i--) {
		FitnessRecord record = history[i];
		totalExerciseTime += record.getExerciseTime();
		record.print(height);
		cout << "---------------------------------------------------------------" << endl;
	}

	cout << "Change in BMI: " << (history[days].getWeight() - history[0].getWeight()) / (height * height) << "kg/m^2" << endl;
	cout << "Total exercise time: " << totalExerciseTime << " mins" << endl;
}

void HealthTracker::printRecentData() {
	if (days == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	FitnessRecord record = history[days];

	printBasicInfo();

	record.print(height);
}

void HealthTracker::execute() {
	while (true) {
		char userOption = getOption();

		while (true) {
			switch (userOption) {
			case 'e':
			case 'E':
				return;
				break;
			case 'A':
			case 'a':
				inputData();
				userOption = getOption();
				break;
			case 'R':
			case 'r':
				printRecentData();
				userOption = getOption();
				break;
			case 'V':
			case 'v':
				printHistoryData();
				userOption = getOption();
				break;
			default:
				userOption = getOption(true);
			}
		}
	}
}