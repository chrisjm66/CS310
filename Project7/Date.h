#pragma once
#include <string>

using namespace std;

class Date
{
private:
	int month, day, year;
	bool isValid(const int& month, const int& day, const int& year);

public:
	Date();
	Date(const int& month, const int& day, const int& year);
	void setDate(const int& month, const int& day, const int& year);
	int getMonth();
	int getDay();
	int getYear();
	string toString();
};

