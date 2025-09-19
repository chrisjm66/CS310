// prints first 50 prime numbers
#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int num) {
	for (int divisor = 2; divisor < num; divisor++) {
		if (num % divisor == 0) {
			return false;
		}
	}

	return true;
}

void printPrimes(int start, int numOfPrimes, int lineCount) {
	int row = 0;
	int primesFound = 0;
	int currentNum = start > 2 ? start : 2;

	while (primesFound < numOfPrimes) {


		if (isPrime(currentNum)) {
			primesFound++;
			if (row % lineCount == 0) {
				cout << endl;
				row = 0;
			}

			cout << setw(5) << currentNum << ", ";
			row++;
		}
		currentNum++;
	}
}

// this segment here has nothing to do with prime numbers
double getInput() {
	double input;
	cout << "Input a floating point type and I will validate it";
	cin >> input;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid entry, please try again.";
		cin >> input;
	}

	return input;
}

int main() {
	double input = getInput();
	cout << "Your input: " << input << endl;
	printPrimes(0, 10000, 50);
	printPrimes(0, 15000, 2);
	printPrimes(0, 10000, 100);

	return 0;
}