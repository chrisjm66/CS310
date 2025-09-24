// prints first 50 prime numbers
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// provide default value without sending an argument
bool isPrime(int num=2) {
	for (int divisor = 2; divisor < num; divisor++) {
		if (num % divisor == 0) {
			return false;
		}
	}

	return true;
}

// if using defaults, all values need a default
void printPrimes(int start=2, int numOfPrimes=100, int lineCount=10) {
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
template <typename T>
void getInput(T& variable, const string& prompt) { // const doesn't let it change (final) and we can use the reference since we aren't changing it anyway. saves RAM!
	cout << prompt;
	cin >> variable;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid entry, please try again.";
		cin >> variable;
	}
}

// templates specialization
template <>
void getInput<string>(string& variable, const string& prompt) {
	string input;
	cout << prompt;
	getline(cin, input);
}

template <typename T>
void swapByRef(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int main() {
	string name;
	double input;

	getInput<string>(name, "Enter a string cuh ");
	getInput<double>(input, "Enter a double: ");

	int age = 0;
	// this is considered a reference variable - any value changed to ref will directly affect age
	int& ref = age;
	int a, b;

	getInput<int>(a, "Enter an int: ");
	getInput<int>(b, "enter another int: ");


	swapByRef(a, b);

	cout << "A: " << a << ", B: " << b << endl;

	double one, two;
	getInput<double>(one, "Now do it with 2 floats: ");
	getInput(two ,"again: "); // you can see type is not required since the type is implied with our variable here
	swap(one, two);

	cout << "A: " << one << ", B: " << two;

	/*
	printPrimes(0, 10000, 50);
	printPrimes(0, 15000, 2);
	printPrimes(0, 10000, 100);
	*/

	return 0;
}