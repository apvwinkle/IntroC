

// Handout #1: Source code of a C++ Program, which

// converts distance in inches to centimeters.



#include <iostream>  //inclusion of support for doing input & output

using namespace std; //declare access to standard stuff like cin, cout



// Beginning of main function

int main()

{

	// Declaration of three variables

	double CM_PER_INCH = 2.54;    // for storing a constant: 2.54cm equals one inch

	double inches;             // for storing the input data: distance in inches

	double cms;          // for storing the result: distance in centimeters



	// Get the input of distance in inches.

	cout << "What is the distance in inches?" << endl;

	cin >> inches;

	cout << "The distance in inches is " << inches << endl;



	// Convert the distance to centimeters and store the result.

	cms = CM_PER_INCH * inches;



	// Display the distance in centimeters.

	cout << "The distance in centimeters is " << cms << endl << endl;




	// Display a good-bye message

	cout << "It is a pleasure to do this inch-to-centimeter conversion for you." << endl;

	cout << "Please enter any character and a return to quit the program." << endl;



	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;




}

//End of the main function.



