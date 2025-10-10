#include <iostream>
using namespace std;

void swapByPointer(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int maineee() {
	int a = 5;

	int grades[3] = { 100, 90, 80 };

	// Address Operand: &; shows the address of a variable
	cout << "a is at " << &a << endl;
	cout << "First element of grades is at " << grades << " " << &grades[0] << endl; // either one works

	// Declare int pointer to declare int address
	int* pointer = &a; // sets pointer to the address of a

	// * indirection operator to dereference
	cout << a << " " << *pointer << endl;

	*pointer = 10; // we can use the indirection operator to directly update the address that is stored
	

	cout << a << " " << *pointer << endl;

	// We can save the arrays address too
	pointer = grades;
	cout << "Here are the three grades: " << endl;
	cout << *pointer << '\t' << *grades << endl; // we can also apply the indirection operator on arrays
	pointer++;
	cout << *pointer << "\t" << pointer[1] << endl;
	cout << *(grades + 1) << endl; //this also works too

	pointer = nullptr;
	if (pointer == nullptr) {
		cout << "Pointer is null - do not dereference!" << endl;
	}

	double* someDouble = nullptr;
	double balance = 20.23;
	someDouble = &balance;
	//someDouble = &a; we obviously cant do this since doubles are 64 bit, ints are 32 bit.

	int* pA, *pB; // this would only declare the first variable as a pointer if the * was missing from the second variable
	a = 2;
	int b = 3;

	pA = &a;
	pB = &b;
	pA = pB;

	cout << "a, b stayed the same: " << a << '\t' << b << endl;
	cout << "pA: " << *pA << "\t pB: " << *pB << endl;

	pA = &a;
	pB = &b;

	*pA = *pB; // has the same output as a = b;

	a = 2;
	b = 3;

	cout << "pA and pB reset to a, b. *pA = *pB: " << a << '\t' << b << endl;

	swapByPointer(&a, &b);
	cout << "a, b swapped: " << a << " " << b << endl;

	return 0;
}