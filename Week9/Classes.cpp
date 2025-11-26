#include <iostream>

using namespace std;

template <typename T>
class ArrayList {

private:
	T* array;
	int capacity;
	int size;

	void expandArray() {
		if (capacity == 0) {
			capacity = 1;
		}
		T* newArray = new T[capacity * 2];

		for (int i = 0; i < size; i++) {
			newArray[i] = array[i];
		}

		capacity *= 2;
		delete[] array;
		array = newArray;
	}

public:
	// overload assignment operator
	ArrayList<T>& operator = (const ArrayList<T>& other) {
		if (this != &other) {
			// release old array
			delete[] this->array;
			this->size = other.size;
			this->capacity = other.capacity;
			this->array = new T[capacity];

			for (int i = 0; i < size; i++) {
				this->array[i] = other.array[i];
			}
		}

		return *this;
	}

	// copy constructor, auto called when a copy is made
	ArrayList(const ArrayList<T>& obj) {
		this->size = obj.size;
		this->capacity = obj.capacity;
		this->array = new T[capacity];

		for (int i = 0; i < size; i++) {
			array[i] = obj.array[i];
		}

	}

	ArrayList() {
		size = 0;
		capacity = 2;
		array = new T[capacity];
	}

	ArrayList(int size, T initialValue) {
		this->size = size;
		capacity = size;
		array = new T[capacity];

		for (int i = 0; i < size; i++) {
			array[i] = initialValue;
		}
	}

	~ArrayList() {
		delete[] array;
	}

	void append(T value) {
		if (size == capacity) {
			expandArray();
		}

		array[size] = value;
		size++;
	}

	void insert(T value, int index) {
		if (index > size || index < 0) {
			cout << "Index not valid" << endl;
		}

		if (size == capacity) {
			expandArray();
		}
		size++;
		T prev;

		prev = array[index];
		array[index] = value;

		for (int i = index + 1; i < size; i++) {
			T temp = array[i];
			array[i] = prev;
			prev = temp;
		}
	}

	T removeElement(int index) {
		if (index >= size || index < 0 || size <= 0) {
			throw new bad_array_new_length();
		}

		T element = array[index];

		if (size == 1) {
			delete[] array;
			array = nullptr;
			size = 0;
			capacity = 0;

		}
		else {
			T* newArray = new T[size - 1];
			capacity = size - 1;

			for (int i = 0; i < index; i++) {
				newArray[i] = array[i];
			}

			for (int i = index + 1; i < size; i++) {
				newArray[i - 1] = array[i];
			}
			
			delete[] array;
			array = newArray;
			size--;
			capacity = size;
		}

		return element;
	}

	int getSize() {
		return size;
	}

	T get(int index) {
		return array[index];
	}

	int getCapacity() {
		return capacity;
	}

	void print() {
		for (int i = 0; i < size; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	ArrayList<int> a;

	cout << a.getSize() << endl;
	a.append(100);
	a.append(100);
	a.append(100);
	a.append(67);
	cout << a.removeElement(3) << endl;
	cout << a.getSize() << endl;

	//ArrayList<int> b = a; // calls copy constructor
	ArrayList<int> b;
	b = a;
	cout << b.getSize() << endl;
}