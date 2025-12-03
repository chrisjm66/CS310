#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

bool Date::isValid(const int& month, const int& day, const int& year) {
	if (month < 1 || month > 12) {
		return false;
	}
	else if (day < 1 || day > 31) {
		return false;
	}

	return true;
}

Date::Date():Date(11, 25, 2025) {

}

Date::Date(const int& month, const int& day, const int& year) {
	setDate(month, day, year);
}

void Date::setDate(const int& month, const int& day, const int& year) {
	if (isValid(month, day, year)) {
		this->month = month;
		this->day = day;
		this->year = year;
	}
	else
	{
		cout << "Date not valid" << endl;
	}
}

int Date::getMonth() {
	return this->month;
}

int Date::getDay() {
	return this->day;
}

int Date::getYear() {
	return this->year;
}

string Date::toString() {
	return to_string(this->month) + "/" + to_string(this->day) + "/" + to_string(this->year);
}