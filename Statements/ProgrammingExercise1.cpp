// Chris M and Jen Greene
// there are two solutons, Jen made another one with mod


#include <iostream>

using namespace std;

int main() {
	int number, int1, int2, int3;
	cout << "Enter number 100-999: " << endl;
	cin >> number;

	int1 = number / 100;
	int2 = number / 10 - int1 * 10;
	int3 = number - int1 * 100 - int2 * 10;
	int sum = int1 + int2 + int3;

	cout << int1 << '\n' << int2 << '\n' << int3 << endl;
	cout << "Sum: " << sum << endl;

	cout << "The sum " << (sum % 3 == 0 ? "is" : "isnt") << " divisible by 3" << endl;

	return 0;
}