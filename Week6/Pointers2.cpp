#include <iostream>

using namespace std;

void printArray(int* grades, const int size) {
	for (int i = 0; i < size; i++) {
		cout << grades[i] << '\t';
		// cout << *(grades+i) << '\t';
	}

	cout << endl;
}

int* reverse(const int* original, const int size) {
	int* p = new int[size];

	for (int i = 0; i < size; i++) {
		p[i] = original[size - i - 1];
	}

	return p;
}

int main() {
	int grades[3] = { 100, 90, 80 };
	int* pGrades = grades;

	cout << "First element: " << pGrades[0] << endl; // this works for pointers
	pGrades += 2;
	cout << "Last element: " << *pGrades << endl;

	cout << "Ints between 2 addresses: " << pGrades - grades << endl;

	printArray(grades, 3);

	// new operator: dynamically allocated memory
	int size = 5;
	int* p = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter another grade: ";
		cin >> p[i];
	}

	printArray(p, size);


	int* newArray = reverse(p, size);

	// remember the brackets - no brackets = single block of memory. we can also specify how many blocks to delete
	delete[] p;
	p = nullptr;

	printArray(newArray, size);

	delete[] newArray;
	newArray = nullptr;

	// dynamic string
	string* dynamicString = new string();
	delete dynamicString;
}