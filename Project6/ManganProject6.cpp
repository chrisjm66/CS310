// Chris Mangan
// Project #6
#include<iostream>
#include<string>
#include <iomanip>
#include <cmath>
using namespace std;

struct User {
	string name;
	double height;
	char gender;
	int age;
};

struct FitnessRecord {
	double weight;
	int exerciseTime;
	string exerciseType;
};

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
T* resizeArray(T* array, int& size) {
	T* newArray = new T[size * 2];
	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}

	delete[] array;
	return newArray;
}

template <typename T>
T* insertItem(T array[], T item, const int& index, int& size) {

	for (int i = 0; i < index - 1; i++) {
		array[i] = array[i];
	}
	array[index] = item;

	return array;
}

void addData(FitnessRecord*& fitnessRecords, int& size, int& index) {
	double weight = getInput<double>("Please enter your weight in kg.");
	int time = getInput<int>("Please enter your exercise time in minutes.");
	string exerciseType = getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");

	index++;
	cout << index << endl;
	if (size == index) { // double array sizes if index == size
		fitnessRecords = resizeArray(fitnessRecords, size);
		cout << "resized" << endl;
		size *= 2;
	}

	FitnessRecord newRecord;
	newRecord.exerciseTime = time;
	newRecord.weight = weight;
	newRecord.exerciseType = exerciseType;

	fitnessRecords = insertItem(fitnessRecords, newRecord, index, size);
}

void printBasicInfo(const User& user) {
	cout << "\tName: " << user.name << endl;
	cout << "Gender: " << user.gender << ", Age: " << user.age << ", Height: " << user.height << "m" << endl;
}

void printFitnessRecord(const User& user, const FitnessRecord& record) {
	cout << "Weight: " << record.weight << "kg, BMI: " << record.weight / (user.height * user.height) << " kg/m2" << endl;
	cout << "Exercise: " << record.exerciseType << " (" << record.exerciseTime << "mins)" << endl;
}

void printHistoryData(
	const User& user,
	const FitnessRecord* fitnessRecord,
	const int& index) {

	if (index == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	printBasicInfo(user);
	cout << "------------------" << endl;

	for (int i = 0; i <= index; i++) {
		FitnessRecord record = fitnessRecord[i];

		printFitnessRecord(user, record);
		cout << "---------------------------------------------------------------" << endl;
	}
}

void printRecentData(
	const User user,
	const FitnessRecord* fitnessRecords,
	const int& index) {

	if (index == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	FitnessRecord record = fitnessRecords[index];

	printBasicInfo(user);

	printFitnessRecord(user, record);
}

User getBasicInfo() {
	string name = getInput<string>("Please enter your name.");
	char gender = getGender("Please enter your gender (M/F).");
	int age = getInput<int>("Please enter your age.");
	double height = getInput<double>("Please enter your height in meters.");

	User user = {name, height, gender, age};
	return user;
}

int main() {
	int size = 1;
	int index = -1;
	FitnessRecord* fitnessRecords = new FitnessRecord[size];

	char userOption;
	User user = getBasicInfo();

	userOption = getOption();

	while (true) {
		switch (userOption) {
		case 'e':
		case 'E':
			return 0;
			break;
		case 'A':
		case 'a':
			addData(fitnessRecords, size, index);
			userOption = getOption();
			break;
		case 'R':
		case 'r':
			printRecentData(user, fitnessRecords, index);
			userOption = getOption();
			break;
		case 'V':
		case 'v':
			printHistoryData(user, fitnessRecords, index);
			userOption = getOption();
			break;
		default:
			userOption = getOption(true);
		}
	}

	return 0;
}