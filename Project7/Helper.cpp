/*#include "Helper.h"
#include <iostream>
#include <limits>

using namespace std;

template <typename T>
static T Helper::getInput(const string& prompt) {
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

template <typename T>
static T* Helper::resizeArray(T* array, int& size) {
	T* newArray = new T[size * 2];
	for (int i = 0; i < size; i++) {
		newArray[i] = array[i];
	}

	delete[] array;
	return newArray;
}*/