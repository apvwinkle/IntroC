

// Programming Assignment #0

// converts temperature from Celsius to Fahrenheit


#include <iostream> 

using namespace std;


// Beginning of main function

int main()

{
	// Declaration of variables

	double C;     // for storing the input data: temperature in Celsius

	double F;     // for storing the result: temperature in Fahrenheit


	// Get the input data

	cout << "What is the temperature in Celsius?" << endl;

	cin >> C;

	cout << endl << "The temperature in Celsius is " << C << endl;

	// Convert the temperature to Fahrenheit and store the result.

	F = 1.8*C + 32.0;

	// Display the temperature in Fahrenheit.

	cout << "The temperature in Fahrenheit is " << F << endl << endl;


	// Display a good-bye message

	cout << "It is a pleasure to do this Celsius-to-Fahrenheit conversion for you." << endl;

	cout << "Please enter any charcter and a return to quit the program." << endl;


	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;

}

//End of the main function.



