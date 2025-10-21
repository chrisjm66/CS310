// Chris Mangan
// Dynamic Array Exercise

#include <iostream>
using namespace std;

void initialize(int* A, int size, int value) {
	for (int i = 0; i < size; i++) {
		*(A + i) = value;
	}
}

void print(int* A, int& size) {
	for (int i = 0; i < size; i++) {
		cout << *(A + i) << " ";
	}
	cout << endl;
}

int* appendElement(int* A, int& size, int newValue) {
	size++;
	int* newArray = new int[size];

	for (int i = 0; i < size - 1; i++) {
		newArray[i] = A[i];
	}

	newArray[size - 1] = newValue;
	delete[] A;
	return newArray;
}

int* insertElement(int* A, int& size, int newValue, int index) {
	size++;
	int* newArray = new int[size];
	int offset = 0;

	newArray[index] = newValue;

	for (int i = 0; i < size - 1; i++) {
		if (i == index) {
			offset++;
		}
		newArray[i+offset] = A[i];
	}

	delete[] A;
	return newArray;
}

int* deleteElement(int* A, int& size, int index) {
	size--;
	int* newArray = new int[size];
	int offset = 0;

	for (int i = 0; i < size + 1; i++) {
		if (i == index) {
			offset++;
		}

		newArray[i] = A[i + offset];
	}

	delete[] A;
	return newArray;
}

int main() {
	cout << "Enter list size: ";
	int size;
	cin >> size;

	int* A = new int[size];

	int value = 0;
	cout << "Initial value for all elements in the list: ";
	cin >> value;
	initialize(A, size, value);

	cout << "All elements initialied as " << value << endl;
	print(A, size);

	int newValue = 0;
	cout << "Append value: ";
	cin >> newValue;
	A = appendElement(A, size, newValue);

	int index;
	cout << "Insert value: ";
	cin >> newValue;
	cout << "At index: ";
	cin >> index;
	A = insertElement(A, size, newValue, index);
	print(A, size);

	cout << "Remove value at index: ";
	cin >> index;
	A = deleteElement(A, size, index);
	print(A, size);
}