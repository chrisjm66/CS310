#include<string>
#include<iostream>
#include <cmath>
using namespace std;

int invest(double& currentBalance, double interestRate, double goal) {
	int years = log(goal - currentBalance) - log((1 + (interestRate / 100)));
	currentBalance *= pow(1 + ((interestRate / 100)), years);

	return years;


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

int main1() {
	double currentBalance = getInput<double>("Please enter your account balance.");
	double interestRate = getInput<double>("Please enter interest rate in % (ie. 5% = 5");
	double goal = getInput<double>("Please enter investment goal.");

	int years = invest(currentBalance, interestRate, goal);

	cout << "It will take " << years << " years to get to your investment goal. Your account balance would be " << currentBalance << endl;

	return 0;
}