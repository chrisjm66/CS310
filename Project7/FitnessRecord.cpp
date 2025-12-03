#include "FitnessRecord.h"
#include <iostream>

using namespace std;

FitnessRecord::FitnessRecord() :FitnessRecord(0, "None", 0, Date(1, 1, 2025)) {

}

FitnessRecord::FitnessRecord(const double& weight, const string& exerciseType, const int& exerciseTime, const Date& date) {
	this->weight = weight;
	this->exerciseType = exerciseType;
	this->exerciseTime = exerciseTime;
	this->date = date;
}

void FitnessRecord::setWeight(const double& weight) {
	this->weight = weight;
}

void FitnessRecord::setExerciseType(const string& exerciseType) {
	this->exerciseType = exerciseType;
}

void FitnessRecord::setExerciseTime(const int& exerciseTime) {
	this->exerciseTime = exerciseTime;
}

void FitnessRecord::setDate(const Date& date) {
	this->date = date;
}

double FitnessRecord::getWeight() {
	return this->weight;
}

string FitnessRecord::getExerciseType() {
	return this->exerciseType;
}

int FitnessRecord::getExerciseTime() {
	return this->exerciseTime;
}

Date FitnessRecord::getDate() {
	return this->date;
}
void FitnessRecord::print(const double& height) {
	cout << "Weight: " << this->weight << "kg, BMI: " << this->weight / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << this->exerciseType << " (" << this->exerciseTime << "mins)" << endl;
}