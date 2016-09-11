

// Program 5C : A better birthday validation program

#include <iostream> 
#include <string>
using namespace std;

// Global Variables
int day, month, year;

// Function Prototypes
void getBirthday(string);
bool isLeapYear(int);
bool isValidDate(int, int, int);



int main()

{

	// Display a greeting
	cout << "Hello, and welcome to the birthday checking program!" << endl;



	// ****************************** USER ******************************

	// Get the birthday
	getBirthday("were you");

	// Validate the birthday
	while (!isValidDate(month, day, year))
	{
		cout << endl << endl << "This birthday is invalid. Please enter a valid birthday." << endl;
		getBirthday("were you");
		if (isValidDate(month, day, year))
			break;
	}

	// Report whether the birthday is a leap year or not.
	cout << endl << "The year you were born in, " << year;
	if (isLeapYear(year))
		cout << ", was a leap year." << endl << endl;
	else
		cout << ", was not a leap year." << endl << endl;



	// ****************************** MOTHER ******************************

	// Get the birthday
	getBirthday("was your mother");

	// Validate the birthday
	while (!isValidDate(month, day, year))
	{
		cout << endl << endl << "This birthday is invalid. Please enter a valid birthday." << endl;
		getBirthday("was your mother");
		if (isValidDate(month, day, year))
			break;
	}

	// Report whether the birthday is a leap year or not.
	cout << endl << "The year your mother was born in, " << year;
	if (isLeapYear(year))
		cout << ", was a leap year." << endl << endl;
	else
		cout << ", was not a leap year." << endl << endl;



	// ****************************** FATHER ******************************

	// Get the birthday
	getBirthday("was your father");

	// Validate the birthday
	while (!isValidDate(month, day, year))
	{
		cout << endl << endl << "This birthday is invalid. Please enter a valid birthday." << endl;
		getBirthday("was your father");
		if (isValidDate(month, day, year))
			break;
	}

	// Report whether the birthday is a leap year or not.
	cout << endl << "The year your father was born in, " << year;
	if (isLeapYear(year))
		cout << ", was a leap year." << endl << endl;
	else
		cout << ", was not a leap year." << endl << endl;

	// ****************************************************************

	// Tell the user that all the dates were valid.
	cout << endl << endl << "Congratulations! All three birthdays are valid!" << endl;

	// Display a good-bye message
	cout << endl << endl << "Thank you for using this program." << endl;
	cout << "Please type any charcter and press enter to quit the program." << endl;

	// Wait for the user input before ending the program
	char inputCharacter;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter;

	//Finish the program and return the control to the operating system.
	return 0;
}

//*******************************************************************************************
// The getBirthday function asks the user to enter the birthday for the selected person.	*
// It makes sure that the user enters integers for the month, day, and year.				*
//*******************************************************************************************
void getBirthday(string wasperson)
{
	cout << endl << "What year " << wasperson << " born in?" << endl;
	cin >> year;
	if (cin.fail())		//The program will not move on until they enter an integer
	{
		while (!(cin >> year))
		{
			cerr << "Invalid input, try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << "What month " << wasperson << " born in? \n Please enter 1 for January, 2 for Febuary, etc." << endl;
	cin >> month;
	if (cin.fail())		//The program will not move on until they enter an integer
	{
		while (!(cin >> month))
		{
			cerr << "Invalid input, try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	cout << "What day " << wasperson << " born on?" << endl;
	cin >> day;
	if (cin.fail())		//The program will not move on until they enter an integer
	{
		while (!(cin >> day))
		{
			cerr << "Invalid input, try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}


}

//*******************************************************************************************
// The isLeapYear function returns TRUE if year entered is a leap year, otherwise it will	*
// return FALSE.																			*
//*******************************************************************************************

bool isLeapYear(int year)
{
	if (year % 4 == 0)
		if (year % 100 == 0)
			if (year % 400 == 0)
				return 1;		// year divides by 400
			else
				return 0;		// year divides by 100 but not 400
		else
			return 1;			// year divides by 4, but not 100
	else
		return 0;				// year is not divisible by 4
}

//*******************************************************************************************
// The isValidDate function returns TRUE if the numbers entered for the day, month, and 		*
// year compose and valid date. Otherwise, it will return FALSE.																	*
//*******************************************************************************************

bool isValidDate(int month, int day, int year)
{
	// Declare variables
	bool isDayValid, isYearValid, isMonthValid = true;
	
	// Validate the year
	if (year < 0)
		isYearValid = false;
	else
		isYearValid = true;

	// Validate the month and day
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		if (day < 1 || day > 31)
			isDayValid = false;
		else
			isDayValid = true;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		if (day < 1 || day > 30)
			isDayValid = false;
		else
			isDayValid = true;
	else if (month == 2)
		if (day < 1 || day > 29)
			isDayValid = false;
		else if (day == 29)
			if (isLeapYear)		
				isDayValid = true;	
			else
				isDayValid = false;
		else
			isDayValid = true;
	else
	{
		isMonthValid = false;	// this will be set to 0 if month is not in [1, 12].
		isDayValid = false;
	}
	
	// Set the return value
	if (isDayValid && isMonthValid && isYearValid)
		return 1;
	else
		return 0;
}


