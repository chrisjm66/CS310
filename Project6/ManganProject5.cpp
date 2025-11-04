// Chris Mangan
// Project #4
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

void addData(double*& weights, string*& exerciseTypes, int*& times, int& size, int& index) {
	double newWeight = getInput<double>("Please enter your weight in kg.");
	int newTime = getInput<int>("Please enter your exercise time in minutes.");
	string newExerciseType = getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");

	index++;

	if (size == index) { // double array sizes if index == size
		weights = resizeArray(weights, size);
		exerciseTypes = resizeArray(exerciseTypes, size);
		times = resizeArray(times, size);
		size *= 2;
	}

	weights = insertItem(weights, newWeight, index, size);
	exerciseTypes = insertItem(exerciseTypes, newExerciseType, index, size);
	times = insertItem(times, newTime, index, size);
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
	const int& index) {

	if (index == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	printBasicInfo(name, gender, age, height);
	cout << "------------------" << endl;

	for (int i = 0; i < index + 1; i++) { // the min function is to prevent bad data being displayed if the user enters less than 7 pieces of data
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
	const int& index) {

	if (index == -1) {
		cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
		return;
	}

	printBasicInfo(name, gender, age, height);

	cout << "Weight: " << weights[index] << "kg, BMI: " << weights[index] / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << exerciseTypes[index] << " (" << exerciseTimes[index] << "mins)" << endl;
}

void getBasicInfo(string& name, char& gender, int& age, double& height) {
	name = getInput<string>("Please enter your name.");
	gender = getGender("Please enter your gender (M/F).");
	age = getInput<int>("Please enter your age.");
	height = getInput<double>("Please enter your height in meters.");
}

int main() {
	int size = 1;
	int index = -1;
	int* exerciseTimes = new int[size];
	double* weights = new double[size];
	string* exerciseTypes = new string[size];

	string name;
	int age;
	char gender, userOption;
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
			addData(weights, exerciseTypes, exerciseTimes, size, index);
			userOption = getOption();
			break;
		case 'R':
		case 'r':
			printRecentData(name, gender, age, weights, height, exerciseTypes, exerciseTimes, index);
			userOption = getOption();
			break;
		case 'V':
		case 'v':
			printHistoryData(name, gender, age, weights, height, exerciseTypes, exerciseTimes, index);
			userOption = getOption();
			break;
		default:
			userOption = getOption(true);
		}
	}

	return 0;
}
