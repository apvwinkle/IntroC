

// Program 5B: Prime Numbers and Functions : an update to Program 4B.

#include <iostream> 
using namespace std; 

// Global Variable
bool isInService;		// for indicating whether the program should still be running


// Function Prototypes
bool isPrime(int);
void printAllPrimesLessThan(int);
int  getTheNthPrime(int);



int main()

{
	// Declaration of variables
	char option;					// for storing the user's menu choice	
	int  n;							// this stores the number the user enters


	// Beginning of while statement
	do
	{
		// Display a menu and get the user's menu choice
		cout << "Please input the character corresponding to the menu choice." << endl;
		cout << "P : checks to see if a number, n, is a prime." << endl;
		cout << "L : prints a list of all prime numbers less than a number n." << endl;
		cout << "N : prints the nth prime number." << endl;
		cout << "Q : quits the program." << endl << endl;
		cin >> option;
		cout << endl;

		// Ask the user for the number n
		if (option == 'P' || option == 'p' || option == 'L' || option == 'l' || option == 'N' || option == 'n')
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
			
			cout << "Please enter a positive integer, n." << endl;
			cout << "n = ";
			cin >> n;

			// Validate the input
			if (cin.fail())
			{
				while (!(cin >> n))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			cout << endl;
		}


		// Call on the appropriate function depending on what the user entered.
		switch (option)
		{
			case 'P':
			case 'p': 
				if (isPrime(n))
					cout << n << " is prime." << endl << endl;
				else
					cout << n << " is not prime." << endl << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');	//cleans up user error
				break;

			case 'L':
			case 'l': printAllPrimesLessThan(n);
				break;

			case 'N':
			case 'n': 
				cout << "The " << n << " prime is " << getTheNthPrime(n) << endl << endl;
				break;

			case 'Q':
			case 'q': isInService = false;		// The Service Mode is off
				break;

			default: isInService = true;		// The Service Mode is on
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
				//Display an error message
				cout << "That is not a valid menu option. \n Please try again." << endl << endl;
				break;
		}
	} while (isInService == true);

	// End of the while statement


	// Display a good-bye message
	cout << "Thank you for using this program." << endl;
	cout << "Please enter any charcter and press enter to quit the program." << endl;

	// Wait for the user input before ending the program
	char inputCharacter; 
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter; 

	//Finish the program and return the control to the operating system.
	return 0;
}

//*******************************************************************************************
//The isPrime function returns TRUE if the number entered is a prime, and FALSE if it 		*
//is not a prime number.																	*
//*******************************************************************************************

bool isPrime(int n)
{
	// Declaration of variables
	int i;	 // counter variable for the loop
	int num_divisors = 0;	// for counting the number of non-trivial factors (divisors)

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

	// The program will continue to run the menu.
	isInService = true;

	// Report to the user whether the number is prime
	if (num_divisors != 0)
		return false;
	else if (n == 1)
		return false;
	else
		return true;
}


//*******************************************************************************************
//The printAllPrimesLessThan function prints all the primes less than a number defined		*
// by the user.																				*
//*******************************************************************************************

void printAllPrimesLessThan(int n)
{
	// Counter variable
	int i;

	// If n <= 2, there are no primes less than n.
	if (n <= 2)
		cout << endl << "There are no primes less than " << n << " ." << endl;
	else
	{
		cout << endl << "The prime numbers less than " << n << " are:" << endl;

		// Determine primes
		for (i = 2; i < n; i++)
		{
			if (isPrime(i))
				cout << "  " << i << endl;
		}
	}

	// The program will continue to run the menu.
	cout << endl;
	isInService = true;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//cleans up user error
}

int getTheNthPrime(int n)
{
	// Declare variables
	int i;				//counter variable
	int primeCount = 0;	//counts the # of primes seen so far

	// Determine and count primes
	for (i = 2; primeCount < n + 1; i++)
	{
		if (isPrime(i))
			primeCount += 1;
		if (primeCount == n)
			break;
	}
		
	// The program will continue to run the menu.
	isInService = true;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//cleans up user error

	return i;
}