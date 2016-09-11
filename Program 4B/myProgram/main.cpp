

// Program 4B : This program finds all the divisors of a number entered by the user


#include <iostream>  
using namespace std; 

int main()

{
	/////////// PART 1: User enters a number, and the program finds all the divisors //////////


	// Declaration of variables
	int n;	 // the number entered in by the user
	int i;	 // counter variable for the loop
	int num_divisors = 0;	// for counting the number of non-trivial factors (divisors)
	
	// Get the input number.

	cout << "Hello, welcome to the prime number program!" << endl << endl;
	cout << "Please enter a positive integer, and I will tell \n you all the numbers it can be divided by." <<endl;
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
			{
				cout << i << " \t is a factor of " << n << "." << endl;
				num_divisors += 1;
			}
		}
	}
	
	// Report to the user the total number of divisors and whether the number is prime
	cout << "The total number of non-trivial divisors of " << n << " is " << num_divisors << endl << endl;
	if (num_divisors != 0)
		cout << n << " is not prime." << endl << endl;
	else if (n == 1)
		cout << n << " is not prime." << endl << endl;
	else
		cout << n << " is a prime." << endl << endl;




	///////////////////// PART 2: Finds every prime number less than 100 ////////////////////


	//Tell the user what the program does next
	cout << endl << endl << "Now, I will display all the primes from 1 to 100!" << endl << endl;
	cout << "Please enter any charcter to continue: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// if the user entered a character above, it would use it here so we need to ignore it
	char inputCharacter1;    // stores a character input from the keyboard
	cin >> inputCharacter1;
	cout << endl << "The prime numbers from 1 to 100 are:" << endl;
	
	// Declaration of Variables
	int j, k;	// counter variables
	num_divisors = 0; // initializes at 0
	
	// Determine primes
	for (j = 1; j < 100; j++)
	{
		num_divisors = 0;
		for (k = 1; k <= j; k++)
		{
			if (j % k == 0)
			{
				num_divisors += 1;
			}
		}
		if (num_divisors == 2)
			cout << "  " << j << endl;
	}



	/////////////////////////// PART 3: Display the first 30 primes //////////////////////////
	
	
	//Tell the user what the program does next
	cout << endl << endl << "Now, I will display the first 30 prime numbers!" << endl << endl;
	cout << "Please enter any charcter to continue: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// if the user entered a character above, it would use it here so we need to ignore it
	char inputCharacter2;    // stores a character input from the keyboard
	cin >> inputCharacter2;
	cout << endl << "The first thirty prime numbers are:" << endl;

	// Declaration of Variables
	int num_primes = 0;
	
	// Determine primes
	for (j = 1; num_primes < 30; j++)
	{
		num_divisors = 0;
		for (k = 1; k <= j; k++)
		{
			if (j % k == 0)
			{
				num_divisors += 1;
			}
		}
		if (num_divisors == 2)
		{
			cout << "  " << j << endl;
			num_primes += 1;
		}
	}
	
	
	
	
	// Display a good-bye message

	cout << endl << endl << "Thank you for using the prime number program!" << endl;

	cout << "Please enter any charcter and a return to quit the program." << endl;

	// Wait for the user input before ending the program
	cin.ignore(numeric_limits<streamsize>::max(), '\n');	// if the user entered a character above, it would use it here so we need to ignore it
	char goodbye;
	cin >> goodbye; // Wait to read in a character input from the keyboard

	// Finish the program and return the control to the operating system.
	return 0;
}

//End of the main function.



