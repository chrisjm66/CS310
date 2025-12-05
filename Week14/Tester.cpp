#include <iostream>
#include <string>
#include <iomanip>
#include "Employee.h"
#include "Manager.h"

double highestSalary(Employee** emps, int noOfEmployees) {
	double highest = -1;

	for (int i = 0; i < noOfEmployees; i++) {
		if (emps[i]->getSalary() >= highest) {
			highest = emps[i]->getSalary();
		}
	}

	// print highest value here
	return highest;
}

void printEmployeesWithSalary(double salary, Employee** emps, int noOfEmployees) {
	for (int i = 0; i < noOfEmployees; i++) {
		if (salary == emps[i]->getSalary()) {
			cout << emps[i]->toString() << endl;
		}
	}
}

int main() {
	int empsTotal = 5;
	Employee john("John", 100, 100000);
	Employee jane("Jane", 200, 200000);
	Employee bob("Bob", 500, 1000000);
	Employee jack("Jack", 300, 300000);

	cout << john.toString() << endl;
	cout << jane.toString() << endl;
	cout << jack.toString() << endl;

	Manager rich("Rich", 400, 1000000, 5);

	Employee** emps = new Employee*[empsTotal];
	emps[0] = &john;
	emps[1] = &jane;
	emps[2] = &jack;
	emps[3] = &rich;
	emps[4] = &bob;

	cout << rich.toString() << endl;

	rich.assignSupervisee(john);
	rich.assignSupervisee(jane);
	rich.assignSupervisee(jack);
	rich.assignSupervisee(bob);
	
	cout << rich.toString() << endl;

	rich.unassignSupervisee(jane);
	cout << "Jane removed\n" << endl;

	cout << rich.toString() << endl;

	rich.assignSupervisee(jane);
	cout << "Jane readded\n" << endl;

	int highest = highestSalary(emps, empsTotal);
	cout << "Highest Salary: " << highest << endl;

	cout << "Highest salaried employee(s):" << endl;
	printEmployeesWithSalary(highest, emps, empsTotal);

	delete[] emps;
}