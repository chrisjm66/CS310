#pragma once
#include <string>
#include "Date.h"

using namespace std;

class FitnessRecord
{
private:
	double weight;
	string exerciseType;
	int exerciseTime;
	Date date;

public:
	FitnessRecord();
	FitnessRecord(const double& weight, const string& exerciseType, const int& exerciseTime, const Date& date);

	void setWeight(const double& weight);
	void setExerciseType(const string& exerciseType);
	void setExerciseTime(const int& exerciseTime);
	void setDate(const Date& date);
	double getWeight();
	string getExerciseType();
	int getExerciseTime();
	Date getDate();
	void print(const double& height);
};

/*
Declare and implement a class named ‘FitnessRecord’, to present a fitness record for a
specific date, with two files ‘FitnessRecord.h’ and ‘FitnessRecord.cpp’, including:
 private instance variables: weight, exercise type, exercise time and Date.
 one constructor with no argument to initialize instance variables to default values.
 one constructor with four parameters to initialize instance variables with the
corresponding values provided by parameters.
 four setter methods to change the instance variables respectively.
 four getter methods to return the instance variables respectively.
 one public method called ‘print’ to print one fitness record using the same format
as previous projects and the date for the record.
*/