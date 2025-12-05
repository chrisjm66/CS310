#pragma once

#include <string>
using namespace std;

class Employee
{
private:
	string name;
	int id;
	double salary;
public:
	Employee();
	Employee(const string& eName, int eID, double eSalary);
	string getName();
	void setName(const string& eName);
	int getID();
	double getSalary();
	void setSalary(double eSalary);
	virtual string toString();
	bool operator==(const Employee& other);

};
