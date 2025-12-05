#include "Employee.h"
#include <sstream>
#include <iomanip>
using namespace std;

Employee::Employee()
{
	name = "";
	id = 0;
	salary = 0;
}
Employee::Employee(const string& eName, int eID, double eSalary)
{
	name = eName;
	id = eID;
	salary = eSalary >= 0 ? eSalary : 0;
}
string Employee::getName()
{
	return name;
}
void Employee::setName(const string& eName)
{
	name = eName;
}
int Employee::getID()
{
	return id;
}
double Employee::getSalary()
{
	return salary;
}
void Employee::setSalary(double eSalary)
{
	salary = eSalary >= 0 ? eSalary : salary;
}

string Employee::toString() {
	string s;
	s = "Name: " + name + ", ID: " + to_string(id) + ", Salary: $" + to_string(salary);
	return s;
}

bool Employee::operator==(const Employee& other) {
	if (name != other.name) {
		return false;
	}

	if (id != other.id) {
		return false;
	}

	if (salary != other.salary) {
		return false;
	}

	return true;
}

