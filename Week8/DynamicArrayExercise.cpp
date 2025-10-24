// Chris Mangan
// Dynamic Array Exercise

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void initialize(T* A, int size, T value) {
	for (int i = 0; i < size; i++) {
		*(A + i) = value;
	}
}

template <typename T>
void print(T* A, int& size) {
	for (int i = 0; i < size; i++) {
		cout << *(A + i) << " ";
	}
	cout << endl;
}
template <typename T>
T* appendElement(T* A, int& size, T newValue) {
	size++;
	T* newArray = new T[size];

	for (int i = 0; i < size - 1; i++) {
		newArray[i] = A[i];
	}

	newArray[size - 1] = newValue;
	delete[] A;
	return newArray;
}

template <typename T>
T* insertElement(T* A, int& size, T newValue, int index) {
	if (index > size || index < 0) {
		return A;
	}

	size++;
	T* newArray = new T[size];
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

template <typename T>
T* deleteElement(T* A, int& size, int index) {
	if (index > size || index < 0) {
		return A;
	}

	if (size == 1) {
		delete[] A;
		return nullptr;
	}

	size--;
	T* newArray = new T[size];
	int offset = 0;

	for (int i = 0; i < size + 1; i++) {
		if (i == index) {
			offset++;
		}

		if (i < size) {
			newArray[i] = A[i + offset];
		}
	}

	delete[] A;
	return newArray;
}

template <typename T>
void runFlow() {
	cout << "Enter list size: ";
	int size;
	cin >> size;

	T* A = new T[size];

	T value = 0;
	cout << "Initial value for all elements in the list: ";
	cin >> value;
	initialize(A, size, value);

	cout << "All elements initialied as " << value << endl;
	print(A, size);

	T newValue = 0;
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

	delete[] A;
}

void printVector(const vector<int>& v) {
	/*
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		// do something
		cout << *it << " ";
	}
	cout << endl;
	*/

	for (auto it = v.begin(); it != v.end(); it++) {
		// same thing but shorter
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	//cout << "Int time: " << endl;
	//runFlow<int>();

	//cout << "Char time: " << endl;
	//runFlow<char>();

	vector<int> array(5, 0); // initialized array of size 5 with default element 0
	vector<int> anotherArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // auto populates size
	cout << "First element: " << array.front() << " " << array[0] << endl;
	cout << "Last element: " << array.back() << endl;

	for (int i = 0; i < array.size(); i++) {
		// standard for loop
	}

	for (int item : array) {
		// enhanced for loop
		cout << item << " ";
	}

	array.push_back(11);

	printVector(array);

	// insert element at index 1
	array.insert(array.begin() + 1, 1);

	//delete last element
	array.pop_back();

	// delete 3rd element
	array.erase(array.begin() + 3);
	cout << "# of elements: " << array.size() << endl;

	// clear an entire array
	array.clear();
	cout << "Is array empty?: " << boolalpha << array.empty() << endl;;

	array = { 15, 10, 12, 4, 6, 0, 5, 2, 3, 1 };

	sort(array.begin(), array.end()); // sort the array

	printVector(array);

	auto index = find(array.begin(), array.end(), 12);
	cout << "Location of 12: " << index - array.begin(); // find function returns address of found object
	return 0;
}