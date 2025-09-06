// Chris Mangan
// Fitness tracker app

#include <string>
#include <iostream>

using namespace std;

int main() {
	string name("Chris Mangan"); // constructor init
	char gender = 'M';
	int age = 20;
	double height = 1.72;
	double weight = 83.91;
	string todaysExercise("3 mile walk outside");
	int exerciseTime = 40;

	cout << "\t" << name << endl;
	cout << gender << ", " << age << ", " << height << "m" << endl;
	cout << "Weight: " << weight << "kg, BMI: " << weight / (height * height) << " kg/m2" << endl;
	cout << "Exercise: " << todaysExercise << " (" << exerciseTime << "mins)" << endl;
	return 0;
}