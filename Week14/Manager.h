#pragma once
#include "Employee.h"
#include <string>

using namespace std;

class Manager: public Employee
{
private:
	int noOfSupervisees, manageCapacity;
	Employee* supervisees;

public:
	Manager(const string& name, int id, double salary, int manageCapacity);
	~Manager();
	int getNoOfSupervisees();
	Employee* getSupervisees();
	void assignSupervisee(const Employee& emp);
	void unassignSupervisee(const Employee& emp);
	string toString();
};

