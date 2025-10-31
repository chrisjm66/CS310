#include <iostream>
#include <string>

using namespace std;

struct Employee {
	int id;
	string name;
	double salary;
};

void printEmployee(const Employee& employee) {
	cout << "Employee Name: " << employee.name << " ID: " << employee.id << " Salary: " << employee.salary << endl;
}

void addEmployee(Employee& emp) {
	cout << "Name: ";
	getline(cin, emp.name);
	cout << "Id: ";
	cin >> emp.id;

	cout << "Salary: ";
	cin >> emp.salary;
	cin.ignore(1000, '\n');
}

int searchEmployee(const Employee employees[], int employeeId, int size) {
	for (int i = 0; i < size; i++) {
		if (employees[i].id == employeeId) {
			return i;
		}
	}

	return -1;
}

int main() {
	int size = 0;
	cout << "Enter # of employees: " << endl;
	cin >> size;
	cin.ignore(1000, '\n');

	Employee* array = new Employee[size];

	for (int i = 0; i < size; i++) {
		Employee e;
		addEmployee(e);
		array[i] = e;
	}

	// print empployees
	cout << endl << "Employees:" << endl;
	for (int i = 0; i < size; i++) {
		printEmployee(array[i]);
	}
	cout << endl;

	while (true) {
		// search
		cout << endl << "Enter employee to search: ";
		int searchId = 0;
		cin >> searchId;

		int employeeIndex = searchEmployee(array, searchId, size);
		if (employeeIndex != -1) {
			cout << "Employee found, Name: " << array[employeeIndex].name;
		}
		else {
			cout << "Employee not found";
		}
	}

	return 0;
}