

// Program 5A: Calling Void Functions in an n ATM-Like Service Program


#include <iostream>
using namespace std;

// Global Variable
bool isInService;					// for indicating whether the program should still be running

// Function prototypes
void displayMenu();
void checkLeapYear();
void checkPrime();


int main()

{
	// Declaration of variables
	char option;					// for storing the user's menu choice	
	

	// Beginning of while statement
	do
	{
		// Display a menu and get the user's menu choice
		displayMenu();
		cin >> option;

		// Call on the appropriate function depending on what the user entered.
		switch(option)
		{
		case 'L':
		case 'l': checkLeapYear();
			break;

		case 'P':
		case 'p': checkPrime();
			break;

		case 'Q':
		case 'q': isInService = false;		// The Service Mode is off
			break;

		default: isInService = true;		// The Service Mode is on
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
			//Display an error message
			cout << "That is not a valid menu option. \n Please enter L for leap year calculation, \n D for distance calculation, or Q to quit." << endl << endl;
			break;
		}
	} while (isInService == true);

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

//*******************************************************************************************
//The displayMenu function prints the menu out to the screen                                *
//*******************************************************************************************
void displayMenu()
{
	cout << "Please input the character corresponding to the menu choice." << endl;
	cout << "L : determines if a year is a leap year." << endl;
	cout << "P : checks to see if a number is a prime." << endl;
	cout << "Q : quits the program." << endl << endl;
}


//*******************************************************************************************
//The checkLeapYear function asks the user for an input year, checks to see if it is a		*
//leap year, and then tells the user whether the year is a leap year or not.				*
//*******************************************************************************************
void checkLeapYear()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	int year;
	bool isLeapYear = true;
	
	// Get a year from the user
	cout << "Please enter a year, and I will tell you if it is a leap year." << endl;
	cin >> year;

	// Validate the input
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
		cout << year << " is a leap year." << endl << endl;
	else
		cout << year << " is not a leap year." << endl << endl;

	isInService = true;

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
}


//*******************************************************************************************
//The checkPrime function asks the user for a prime number, checks to see if it is a		*
//prime, and then tells the user if it is a prime number or not.							*
//*******************************************************************************************
void checkPrime()
{
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//cleans up user error

	// Declaration of variables
	int n;	 // the number entered in by the user
	int i;	 // counter variable for the loop
	int num_divisors = 0;	// for counting the number of non-trivial factors (divisors)

	// Get the input number.

	cout << "Please enter a positive integer, and I will tell \n you if it is a prime number." << endl;
	cin >> n;
	cout << endl;

	// Validate the input
	while (n < 1)
	{
		cout << "Please enter a positive integer." << endl;
		do // (code found at https://www.daniweb.com/programming/software-development/threads/29074/wrong-user-input)
		{
			cerr << "Invalid input, try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} while (!(cin >> n));
	}

	// Find the divisors of the number
	if ((n == 1) || (n == 2))
		num_divisors = 0;
	else
	{
		for (i = 2; i < n; i++)
		{
			if (n % i == 0)
				num_divisors += 1;
		}
	}

	// Report to the user whether the number is prime
	if (num_divisors != 0)
		cout << n << " is not prime." << endl << endl;
	else if (n == 1)
		cout << n << " is not prime." << endl << endl;
	else
		cout << n << " is a prime." << endl << endl;

	isInService = true;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//cleans up user error
}