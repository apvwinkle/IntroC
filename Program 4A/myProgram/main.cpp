

// Program 4A: An ATM-Like Service Program


#include <iostream>
using namespace std;


int main()

{
	// Declaration of variables
	char option;				// for storing the user's menu choice
	bool isInService = true;		// for indicating whether the program should still be running	
	
	int year;					// for leap year calculation	
	bool isLeapYear;
	
	double miles, km;			// for miles to km calculation
	double KM_PER_MILE = 1.609;


	// Beginning of while statement

	while (isInService == true)
	{
		// Display a menu and get the user's menu choice
		cout << "Please input the character corresponding to the menu choice." << endl;
		cout << "L : determines if a year is a leap year." << endl;
		cout << "D : converts a distance from miles to kilometers." << endl;
		cout << "Q : quits the program." << endl << endl;

		cin >> option;


		if ((option == 'L') || (option == 'l'))
		{
			isLeapYear == true;

			// Get a year from the user
			cout << "Please enter a year, and I will tell you if it is a leap year." << endl;
			cin >> year;

			// Make sure the input is valid 
			// (code found at https://www.daniweb.com/programming/software-development/threads/29074/wrong-user-input)
			if (cin.fail())
			{
				while (!(cin >> year))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			// Calculate to see if it is a leap year
			if (year % 4 != 0)		//the year cannot be divided by 4
				isLeapYear = false;

			else
				if (year % 400 == 0)	//the year can be divided by 400
					isLeapYear = true;

				else if (year % 100 == 0) //the year can be divided by 100 but not 400
					isLeapYear = false;


			// Tell the user whether or not it is a leap year
			if (isLeapYear == true)
			{
				cout << year << " is a leap year." << endl << endl;
				isInService = true;
			}
			else
			{
				cout << year << " is not a leap year." << endl << endl;
				isInService = true;
			}
			
		}

		else if ((option == 'D') || (option == 'd'))
		{	
			// Get a distance in miles from the user
			cout << "What is the distance in miles?" << endl;
			cin >> miles;

			// Make sure the input is valid 
			// (code found at https://www.daniweb.com/programming/software-development/threads/29074/wrong-user-input)
			if (cin.fail())
			{
				while (!(cin >> miles))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			
			// Convert the distance to kilometers
			km = KM_PER_MILE * miles;

			// Display the distance in kilometers
			cout << "The distance in kilometers is " << km << endl << endl;
			isInService = true;
			
			
		}


		else if ((option == 'Q') || (option == 'q'))
		{
			// The Service Mode is off
			isInService = false;
		}


		else
		{
			// The Service Mode is on
			isInService = true;

			//Display an error message
			cout << "That is not a valid menu option. \n Please enter L for leap year calculation, \n D for distance calculation, or Q to quit." << endl << endl;
		}
	}
	// End of the while statement


	// Display a good-bye message
	cout << "Thank you for using this program." << endl;
	cout << "Please enter any charcter and press enter to quit the program." << endl;

	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter; // Wait to read in a character input from the keyboard

	//Finish the program and return the control to the operating system.
	return 0;
}



