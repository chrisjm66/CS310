#include <iostream>
#include <iomanip> // lets us do all the stuff to the strings and variables on lines 29-31
#include <string>

using namespace std;

int program() {
    cout << "Happy Friday!\n";
    cout << "Hello c++!";
    cout << endl;

    cout << 3.14;

    cout << endl << "Welcome!\n" << "CS310\n";

    char letter; // variables declared in pretty much the same way as other programming languages
    letter = 'A'; // we can declare then define, like this

    bool isTrue = true; // or just declare it like this

    cout << "Default output for bool values: " << isTrue << endl; // this is how we would print variables
    isTrue = false;
    cout << "Default output for bool values: " << isTrue << endl;

    // all sorts of numbers!
    short int age = 0;
    int members = 10;
    double pi = 3.14159265; // float = 32 bit; double = 64 bit (double the precision)

    cout << "Default float: " << pi << endl;
    cout << fixed<< setprecision(4) << pi << endl; // how you would set precision (i guess this is the same as &.4f?)
    cout << "Print false: " << boolalpha 
    << isTrue << endl; // lets us decide how booleans are displayed (by default they print as 1 or 0)

    // this is very important for pointers:
    cout << "# of bytes in an int: "
    << sizeof(int) << "\t" << sizeof(members) << endl;

    int op1(2); // this is the same as int op1 = 2, its called "constructor initialization" (same as how objects are made)
    cout << "Initial as 2: " << op1 << endl;

    // both do the same thing, but the first one is more efficient
    string message("Hello"); // this creates only one object in the memory (the string object)
    string message2 = "Meow"; // this creates two objects, one for the string literal and the second for the actual string object.

    // standard input from keyboard
    cin >> message2;
    cout << "Your input: " << message2 << endl;

    int op2 = 0; // this initialization can be omitted since we are going to use the console input
    cout << "Enter two ints" << endl;
    cin >> op1 >> op2; // this sends first input to op1 and second input to op2
    cout << "Sum: " << op1 + op2 << endl;

    cout << "Integer division: " << op1 / op2 << endl; // recall that integers round up
    cout << "Real value division: " << (double)op1 / op2 << endl; // welcome typecasting, also notice how we set the precision and it stays persistent
    cout << "% operator: " << op1 % op2 << endl;

    return 0;
}
