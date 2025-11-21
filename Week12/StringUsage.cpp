#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

using namespace std;

bool isValidInt(const string& input) {
	if (input.empty()) return false;

	auto start = input.find_first_not_of(" \t\n");
	auto end = input.find_last_not_of(" \t\n");
	string trimmed = input.substr(start, end);

	for (int i = 0; i < trimmed.length(); i++) {
		if (!isdigit(trimmed.at(i))) {
			return false;
		}
	}

	return true;
}

int main() {
	string content;
	cout << content[0] << endl;
	// cout << content.at(0) << endl; // throws an exception

	content = "c++";
	content.assign("c++"); // these are the same

	content += " ";
	content.append(" program"); // these also are the same
	content.insert(3, "--");
	content.erase(3, 2);
	cout << content << endl;

	content.replace(0, 3, "Java");
	cout << content << endl;

	string weight = "weight: " + to_string(50.50) + " kg"; // using c style strings; array of characters
	cout << weight << endl;
	stringstream format;
	format << fixed << setprecision(2);
	format << "weight: " << 50.5;
	weight = format.str();
	cout << weight << endl;

	int age;
	string input;
	cout << "enter age";
	getline(cin, input);
	auto index = input.find(' ');
	if (index == string::npos) {
		cout << "no spaces in string" << endl;
	}
	else {
		cout << "spaces found in string, first one at" << index << endl;
	}

	auto firstDigitIndex = input.find_first_of("0123456789");
	if (firstDigitIndex == string::npos) {
		cout << "No digits found" << endl;
	}
	else {
		cout << "First digit: " << firstDigitIndex << endl;
	}

	auto lastDigitIndex = input.find_last_of("0123456789");
	if (lastDigitIndex == string::npos) {
		cout << "No digits found" << endl;
	}
	else {
		cout << "Last digit: " << lastDigitIndex << endl;
	}

	if (isValidInt(input)) {
		age = stoi(input);
		cout << age << endl;
	}
	else {
		cout << "bad input";
	}
	
	return 0;
}