

// Program 3 - A Date Validation Program

/*
	This program asks for the birthdays of a user, their mother, and their father.
	It checks for the validity of their birthdays (i.e. leapyears) and makes sure that
	the user is younger than both of their parents.
*/
	

#include <iostream> 
#include <string>
using namespace std;


int main()

{
	// Declaration of variables
	int month, day, year,				 // for checking the date validity
		user_month, user_day, user_year, // for storing the user's date of birth (DOB)
		dad_month, dad_day, dad_year,    // for storing the user's father's DOB
		mom_month, mom_day, mom_year;    // for storing the user's mother's DOB
	bool is_day_valid, is_month_valid, is_year_valid, is_leap_year_valid;

	string MonthError = ("That month does not exist.");
	string DateError = ("That date does not exist in that month.");
	string YearError = ("That year is not possible because it is less than 0.");
	string LeapYearError = ("This year is not a leap year, so the birthday cannot be 2/29.");
	string person;

	// Display a greeting
	cout << "Hello, and welcome to the birthday checking program!" << endl;





	///////////////////////// USER'S BIRTHDAY /////////////////////////

	// Get the user's birthday
	cout << endl << "What is the number of the day of your birthday?" << endl;
	cin >> day;

	cout << "What month were you born in? \n Please enter 1 for January, 2 for Febuary, etc." << endl;
	cin >> month;

	cout << "What year were you born in?" << endl;
	cin >> year;

	person = ("you");


	// DATE VALIDATION
	

	//Sets initial values for the boolean
	is_day_valid = 1, is_month_valid = 1, is_year_valid = 1, is_leap_year_valid = 1; 

	//Validate the month
	if ((month < 1) || (month > 12))
		is_month_valid = 0;

	// Validate the day
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		if ((day < 1) || (day > 31))
			is_day_valid = 0;

	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		if ((day < 1) || (day > 30))
			is_day_valid = 0;

	else if (month == 2)
		if ((day < 1) || (day > 29))
			is_day_valid = 0;

	//Validate the year
	if (year < 0)
		is_year_valid = 0;
	
	//Check for a leap year
	if (month == 2 && day == 29)
		if (year % 4 != 0)		//the year cannot be divided by 4
			is_leap_year_valid = 0;
		else
			if (year % 400 == 0)	//the year can be divided by 400
				is_leap_year_valid = 1;
			else if (year % 100 == 0) //the year can be divided by 100 but not 400
				is_leap_year_valid = 0;

	//Print the error messages
	if (is_day_valid == 0)
		cout << endl << DateError << endl;
	if (is_month_valid == 0)
		cout << endl << MonthError << endl;
	if (is_year_valid == 0)
		cout << endl << YearError << endl;
	if (is_leap_year_valid == 0)
		cout << endl << LeapYearError << endl;
	if (is_day_valid * is_month_valid * is_year_valid * is_leap_year_valid == 0)
		cout << "Thus, the date for " << person << " is not valid." << endl;

	//Store the user's birthday so we can later compare it to the monther's and father's birthdays
	user_month = month;
	user_day = day;
	user_year = year;





	////////////////////// USER'S MOTHER'S BIRTHDAY //////////////////////

	// Get the user's mother's birthday
	cout << endl << "What is the number of the day of your mother's birthday?" << endl;
	cin >> day;

	cout << "What month was your mother born in? \n Please enter 1 for January, 2 for Febuary, etc." << endl;
	cin >> month;

	cout << "What year was your mother born in?" << endl;
	cin >> year;

	person = ("your mother");


	// DATE VALIDATION (same as above)


	//Sets initial values for the boolean
	is_day_valid = 1, is_month_valid = 1, is_year_valid = 1, is_leap_year_valid = 1;

	//Validate the month
	if ((month < 1) || (month > 12))
		is_month_valid = 0;

	// Validate the day
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		if ((day < 1) || (day > 31))
			is_day_valid = 0;

		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			if ((day < 1) || (day > 30))
				is_day_valid = 0;

			else if (month == 2)
				if ((day < 1) || (day > 29))
					is_day_valid = 0;

	//Validate the year
	if (year < 0)
		is_year_valid = 0;

	//Check for a leap year
	if (month == 2 && day == 29)
		if (year % 4 != 0)		//the year cannot be divided by 4
			is_leap_year_valid = 0;
		else
			if (year % 400 == 0)	//the year can be divided by 400
				is_leap_year_valid = 1;
			else if (year % 100 == 0) //the year can be divided by 100 but not 400
				is_leap_year_valid = 0;

	//Print the error messages
	if (is_day_valid == 0)
		cout << endl << DateError << endl;
	if (is_month_valid == 0)
		cout << endl << MonthError << endl;
	if (is_year_valid == 0)
		cout << endl << YearError << endl;
	if (is_leap_year_valid == 0)
		cout << endl << LeapYearError << endl;
	if (is_day_valid * is_month_valid * is_year_valid * is_leap_year_valid == 0)
		cout << "Thus, the date for " << person << " is not valid." << endl;

	//Store the birthday so we can later compare it
	mom_month = month;
	mom_day = day;
	mom_year = year;



	

	////////////////////// USER'S FATHER'S BIRTHDAY //////////////////////

	// Get the user's father's birthday
	cout << endl << "What is the number of the day of your father's birthday?" << endl;
	cin >> day;

	cout << "What month was your father born in? \n Please enter 1 for January, 2 for Febuary, etc." << endl;
	cin >> month;

	cout << "What year was your father born in?" << endl;
	cin >> year;

	person = ("your father");


	// DATE VALIDATION (same as above)

	
	//Sets initial values for the boolean
	is_day_valid = 1, is_month_valid = 1, is_year_valid = 1, is_leap_year_valid = 1;

	//Validate the month
	if ((month < 1) || (month > 12))
		is_month_valid = 0;

	// Validate the day
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		if ((day < 1) || (day > 31))
			is_day_valid = 0;

		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			if ((day < 1) || (day > 30))
				is_day_valid = 0;

			else if (month == 2)
				if ((day < 1) || (day > 29))
					is_day_valid = 0;

	//Validate the year
	if (year < 0)
		is_year_valid = 0;

	//Check for a leap year
	if (month == 2 && day == 29)
		if (year % 4 != 0)		//the year cannot be divided by 4
			is_leap_year_valid = 0;
		else
			if (year % 400 == 0)	//the year can be divided by 400
				is_leap_year_valid = 1;
			else if (year % 100 == 0) //the year can be divided by 100 but not 400
				is_leap_year_valid = 0;

	//Print the error messages
	if (is_day_valid == 0)
		cout << endl << DateError << endl;
	if (is_month_valid == 0)
		cout << endl << MonthError << endl;
	if (is_year_valid == 0)
		cout << endl << YearError << endl;
	if (is_leap_year_valid == 0)
		cout << endl << LeapYearError << endl;
	if (is_day_valid * is_month_valid * is_year_valid * is_leap_year_valid == 0)
		cout << "Thus, the date for " << person << " is not valid." << endl;

	//Store the birthday so we can compare it
	dad_month = month;
	dad_day = day;
	dad_year = year;




	//////////////////////////////// COMPARING BIRTHDAYS ////////////////////////////////


	// Declaration of Variables
	int user_Bday, mom_Bday, dad_Bday;	 // for comparing the birthdays of the user against the mother and the father
	bool is_Bday_valid, is_mom_Bday_valid, is_dad_Bday_valid;

	string BdayError = ("Therefore, these birthdays are invalid in relation to each other.");
	string MomBdayError = ("Your mother should not be younger than you.");
	string DadBdayError = ("Your father should not be younger than you.");

	// Convert the birthdays into real numbers
	user_Bday = 10000 * user_year + 100 * user_month + user_day;
	mom_Bday = 10000 * mom_year + 100 * mom_month + mom_day;
	dad_Bday = 10000 * dad_year + 100 * dad_month + dad_day;

	//Sets the initial boolean balues
	is_Bday_valid = 1;
	is_mom_Bday_valid = 1;
	is_dad_Bday_valid = 1;

	// Compare the birthday values
	if (user_Bday <= mom_Bday)
		is_mom_Bday_valid = 0;
	if (user_Bday <= dad_Bday)
		is_dad_Bday_valid = 0;
	
	if (is_mom_Bday_valid * is_dad_Bday_valid == 0)
		is_Bday_valid = 0;

	// Display error messages
	if (is_mom_Bday_valid == 0)
		cout << endl << MomBdayError;
	if (is_dad_Bday_valid == 0)
		cout << endl << DadBdayError;
	if (is_mom_Bday_valid * is_dad_Bday_valid == 0)
		cout << endl << endl << BdayError << endl << endl;
	else
		cout << endl << endl << "The birthdays are valid in relation to each other." << endl << endl;




	// Display a good-bye and wait for an exit character
	cout << endl << "It was a pleasure to do this birthday validation for you." << endl;
	cout << "Please enter any charcter and a return to quit the program." << endl;

	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin >> inputCharacter;  // Wait to read in a character input from the keyboard

	//Finish the program and return the control to the operating system.
	return 0;
}



