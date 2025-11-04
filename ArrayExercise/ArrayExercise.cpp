// Chris Mangan
#include <iostream>
#include <iomanip>
using namespace std;

const int COLUMNS = 3;

void initializeMatrix(int matrix[][COLUMNS], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			int input;

			cout << "Enter a number: ";
			cin >> input;

			while (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid entry, please try again.";
				cin >> input;
			}

			matrix[i][j] = input;
			cout << endl;
		}
	}

	cout << endl;
}

void calculateColumnSums(const int matrix[][COLUMNS], int rows, int columnSums[]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			if (i == 0) {
				columnSums[j] = 0;
			}

			columnSums[j] += matrix[i][j];
		}
	}
}

int maxValue(const int myArray[], int size) {
	int maxValue = 0;

	for (int i = 0; i < size; i++) {
		if (i == 0) {
			maxValue = myArray[i];
		}
		else if (myArray[i] >= maxValue) {
			maxValue = myArray[i];
		}
	}

	return maxValue;
}

int findIndexesOfValue(const int myArray[], int size, int value, int indexes[]) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (myArray[i] == value) {
			indexes[count] = i;
			count++;
		}
	}

	return count;
}

void printArray(const int myArray[], int size) {
	for (int i = 0; i < size; i++) {
		cout << setw(5) << myArray[i];
	}
}

void printMatrix(const int matrix[][COLUMNS], int rows) {
	for (int i = 0; i < rows; i++) {
		printArray(matrix[i], COLUMNS);

		cout << endl;
	}

	cout << endl;
}



int main() {
	const int ROWS = 2;
	int matrix[ROWS][COLUMNS];
	int sums[COLUMNS];
	int sumIndexes[COLUMNS];

	initializeMatrix(matrix, ROWS);

	cout << "The matrix is: " << endl;
	printMatrix(matrix, ROWS);

	calculateColumnSums(matrix, ROWS, sums);

	cout << "The column sums are: " << endl;
	printArray(sums, COLUMNS);

	const int colMax = maxValue(sums, COLUMNS);

	cout << "\n\nLargest column sum: " << colMax << endl;

	int colsWithSum = findIndexesOfValue(sums, COLUMNS, colMax, sumIndexes);

	cout << endl << colsWithSum << " columns containing the largest sum: "<< endl;

	printArray(sumIndexes, colsWithSum);
}