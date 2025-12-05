#pragma once
#include <string>
#include "Date.h"
#include "FitnessRecord.h"

using namespace std;

class HealthTracker
{
private:
	string name;
	char gender;
	Date dateOfBirth;
	double height;
	FitnessRecord* history;
	int capacity;
	int days;

	void printMenu();
	char getOption(bool reprompt);
	char getGender(const string& prompt);
	bool isGenderValid(const char& gender);
	void printBasicInfo();
public:
	HealthTracker();
	~HealthTracker();
	void inputData();
	void printHistoryData();
	void printRecentData();
	void execute();
};