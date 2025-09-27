#include <iostream>

using namespace std;

void copyArray(const int array[], int newArray[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		newArray[i] = array[i];
	}
}

int main() {
	//int array
	const int SIZE = 5;
	int grades[SIZE] = {1, 2, 5, 100}; // no data defualts to a value of 0
	
	for (int i = 0; i < SIZE; i++) {
		cout << grades[i] << endl;
	}

	cout << "Last element: " << grades[SIZE - 1] << endl;
	cout << "Starting address: " << grades << endl;
	cout << "Ending address: " << grades + sizeof(grades);

	// int copy[SIZE] = grades, not allowed for obvious reasons
	int copy[SIZE];

	copyArray(grades, copy, SIZE);

	for (int i : copy) {
		cout << i << endl;;
	}
	

}