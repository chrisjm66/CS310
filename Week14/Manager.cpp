#include "Manager.h"
#include <string>
#include <iostream>

using namespace std;

Manager::Manager(const string& name, int id, double salary, int manageCapacity):Employee(name, id, salary)
{
	noOfSupervisees = 0;
	this->manageCapacity = manageCapacity;
	supervisees = new Employee[manageCapacity];
}

Manager::~Manager() {
	delete[] supervisees;
}

int Manager::getNoOfSupervisees() {
	return noOfSupervisees;
}

Employee* Manager::getSupervisees() {
	return supervisees;
}

void Manager::assignSupervisee(const Employee& emp) {
	if (noOfSupervisees >= manageCapacity) {
		cout << "Can't assign employee -- manager cannot manage this many employees";
		return;
	}

	supervisees[noOfSupervisees] = emp;
	noOfSupervisees++;
}

void Manager::unassignSupervisee(const Employee& emp) {
	bool found = false;

	for (int i = 0; i < noOfSupervisees; i++) {
		if (supervisees[i] == emp) {
			found = true;
		}

		if (found) {
			supervisees[i] = supervisees[i + 1];
		}
	}

	if (found) {
		noOfSupervisees--;
	}
}

string Manager::toString() {
	string s;
	s = "Manager: " + this->getName()
		+ "\nManage Capacity: " + to_string(manageCapacity)
		+ "\nCurrently Managing: " + to_string(noOfSupervisees)
		+ "\nCurrently supervising:\n";

	for (int i = 0; i < noOfSupervisees; i++) {
		s += supervisees[i].getName() + "\n";
	}

	return s;
}