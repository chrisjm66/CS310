// Chris Mangan
// Project #3
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

char getUserOption(bool reprompt = false) {
	string prompt;
	if (reprompt) {
		prompt = string("The selected option is invalid.");
	}
	else {
		prompt = string("Please select an option: [A]dd data; [R]ecent Data; [E]xit program");
	}

	return getInput<char>(prompt);
}

void addData(double& weight, double& height, string& exerciseType, int& time) {
	weight = getInput<double>("Please enter your weight in kg.");
	height = getInput<double>("Please enter your height in meters.");
	time = getInput<int>("Please enter your exercise time in minutes.");
	exerciseType = getInput<string>("Please enter your exercise type (eg. running, walking, lifting).");
}

void printRecentData(
	const string& name,
	const char& gender,
	const int& age,
	const double& weight, 
	const double& height, 
	const string& exerciseType, 
	const int& exerciseTime) {

	cout << "\t" << name << endl;
	cout << gender << ", " << age << ", " << height << "m" << endl;
	cout << "Weight: " << weight << "kg, BMI: " << weight / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << exerciseType << " (" << exerciseTime << "mins)" << endl;
}
int main() {
	string name, exerciseType;
	int age, exerciseTime;
	char gender, userOption;
	bool isValidUserOption, userEnteredData = false;
	double height, weight;

	name = getInput<string>("Please enter your name.");
	gender = getGender("Please enter your gender (M/F).");
	age = getInput<int>("Please enter your age.");
	
	userOption = getUserOption();
	
	while (true) {
		switch (userOption) {
		case 'e':
		case 'E':
			return 0;
			break;
		case 'A':
		case 'a':
			addData(weight, height, exerciseType, exerciseTime);
			userOption = getUserOption();
			userEnteredData = true;
			break;
		case 'R':
		case 'r':
			if (userEnteredData) {
				printRecentData(name, gender, age, weight, height, exerciseType, exerciseTime);
			}
			else {
				cout << "There is no fitness data to print." << endl; // we use exerciseType since it will always be null
			}
			userOption = getUserOption();
			break;
		default:
			userOption = getUserOption(true);
		}
	}

	

	// copied from project 1
	cout << "\t" << name << endl;
	cout << fixed << setprecision(2) << gender << ", " << age << ", " << height << "m" << endl;
	

	return 0;
}
