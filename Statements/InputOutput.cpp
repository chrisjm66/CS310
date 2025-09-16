#include <iostream>
#include <string>
using namespace std;

int main1() {
	int x, y; // same as java, you can declare multiple variables
	cout << (x = 2) << endl; // this is another way to initialize a variable in c++
	y = x;

	y = 2 * y;
	y *= 2 + x; // shorthand for line above; 2 + x evalated first

	cout << "Y expected as 16: " << y << endl;

	y++; // increment
	y--; //decrement
	
	cout << y << endl;

	int counter = 0;
	cout << "Expect 1: " << ++counter << endl; // predecrement; runs before cout
	cout << "Expect 1: " << counter-- << endl; // postdecrement; runs after cout
	cout << "After postdecrement: " << counter << endl;

	int size = 2 * (++counter);
	cout << "pre: " << size << ", counter: " << counter << endl;
	
	size = (int)"1.234567"; // does not check for type safety
	size = static_cast<int>(1.234567);
	cout << "Typecast - expect as 1: " << size << endl;

	int absResult = size >= 0 ? size : -size; // ternarys; same as js and java


	string message;
	cout << "Enter a greeting: " << endl;
	getline(cin, message);
	cout << message << endl;

	int age;
	cout << "Enter your age: " << endl;
	cin >> age; // if a string is entered here it defautls to 0; if it is a double it will simply type cast to an int
	cout << "Extraction faild? " << boolalpha << cin.fail() << endl;
	
	while (cin.fail()) {
		cin.clear(); // changes status from failed to be ready for next
		cin.ignore(1000, '\n'); // ignores current input; ignores up to 1000 chars or when the newline is emitted
		// can also be overloaded with true??? find out next class
		cout << "Please reenter integer: " << endl;
		cin >> age;
	}

	cout << age << endl;
	cout << "Will age get a new value? " << age << endl;

	return 0;
}