#include <iostream>

using namespace std;

template <typename T>
void copyArray(const T array[], T newArray[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		newArray[i] = array[i];
	}
}

template <typename T>
void printArray(const T array[], const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << endl;
	}
}

void passArgByValue(int array[], int value) {
	array[0] = 1000;
	value = 1000;
}

void passArgByRef(int array[], int& value) {
	array[0] = 1000;
	value = 1000;
}

template <typename T>
void printValues(T array[], int value) {
	cout << "Array[0]: " << array[0] << endl;
	cout << "value: " << value << endl;
}

void printArray(int array[][2], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 2; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void reverseArray(T array[], int size) {
	int left = 0;
	int right = size - 1;

	while (left < right) {
		T temp = array[left];
		array[left] = array[right];
		array[right] = temp;

		left++;
		right--;
	}
}

template<typename T>
void reverseArray(const T original[], T copy[], int size) {
	for (int i = 0, j = size - 1; i < size; i++, j--) {
		copy[i] = original[j];
		copy[j] = original[i];
	}
}

double getAverage(const int grades[][2], const int SIZE, const int row) {
	double avg = 0;
	for (int i = 0; i < SIZE; i++) {
		avg += grades[i][row];
	}

	return avg / SIZE;
}

int main() {
	//int array
	const int SIZE = 5;
	int grades[SIZE] = {1, 2, 5, 100}; // no data defualts to a value of 0

	printArray(grades, SIZE);

	cout << "Last element: " << grades[SIZE - 1] << endl;
	cout << "Starting address: " << grades << endl;
	cout << "Ending address: " << grades + sizeof(grades);

	// int copy[SIZE] = grades, not allowed for obvious reasons
	int copy[SIZE];

	copyArray(grades, copy, SIZE);
	printArray(copy, SIZE);
	
	int value = 999;
	printValues(copy, value);

	passArgByValue(copy, value);
	printValues(copy, value);

	passArgByRef(copy, value);
	printValues(copy, value);

	reverseArray(copy, SIZE);
	printArray(copy, SIZE);

	int copy2[SIZE];
	reverseArray(copy, copy2, SIZE);
	printArray(copy2, SIZE);


	// pt 2
	const int ASSIGNMENTS = 2;
	int gradebook[SIZE][ASSIGNMENTS] = { {99, 99}, {3, 4}, {5, 6}, {7, 8}, {9, 10} };

	cout << '\n' << "Array:" << endl;
	printArray(gradebook, SIZE);

	double averages[2];
	for (int i = 0; i < 2; i++) {
		averages[i] = getAverage(gradebook, SIZE, i);
	}
	cout << "Col1 avg: " << averages[0] << endl;
	cout << "Col2 avg: " << averages[1] << endl;
	
	
}