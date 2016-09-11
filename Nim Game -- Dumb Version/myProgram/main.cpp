

// Midterm Project: Nim Game -- Dumb Version


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// Global Variable
bool isInService;		// for indicating whether the program should still be running
int m;					// stores max # of coins someone can take per turn
int n;					// stores total # of coins in the pile
int k;					// stores current # of coins in the pile
bool userfirst;			// stores if it is the user's turn (if false, then it is the computer's turn)
bool lastwins;			// stores if whoever takes the last coin wins (if false, then whoever takes the last coin loses)

// Function Prototypes
void displaymenu();
void displaysettings();
int  getnumber(string);
void nimgame();
int  randcoin();
void displayhelp();


int main()

{
	// Display a welcome message
	cout << "Hello! Welcome to the Nim game!" << endl;
	cout << "________________________________________________________________________" << endl << endl;

	// Declaration of variables and initial values
	m = 3;
	n = 12;
	userfirst = true;
	lastwins = true;
	char option;					// for storing the user's menu choice

	// Display the menu and carry out the selected function.
	do
	{
		// Display current settings
		displaysettings();

		// Display a menu and get the user's menu choice
		displaymenu();
		cin >> option;
		cout << "________________________________________________________________________" << endl << endl;

		// Call on the appropriate function depending on what the user entered.
		switch (option)
		{
		case 'N':
		case 'n': n = getnumber("n");
			cout << "The number of coins to begin with changed." << endl << endl;
			isInService = true;
			break;

		case 'M':
		case 'm': m = getnumber("m");
			cout << "The maximum number of coins per turn changed." << endl << endl;
			isInService = true;
			break;

		case 'U':
		case 'u': userfirst = true;
			cout << "The user will take the first turn." << endl << endl;
			isInService = true;
			break;

		case 'C':
		case 'c': userfirst = false;
			cout << "The computer will take the first turn." << endl << endl;
			isInService = true;
			break;

		case 'W':
		case 'w': lastwins = true;
			cout << "The player who takes the last coin will win." << endl << endl;
			isInService = true;
			break;

		case 'L':
		case 'l': lastwins = false;
			cout << "The player who takes the last coin will lose." << endl << endl;
			isInService = true;
			break;

		case 'P':
		case 'p': nimgame();
			isInService = true;
			break;

		case 'H':
		case 'h': cout << "Help Section: " << endl;
			displayhelp();
			isInService = true;
			break;

		case 'Q':
		case 'q': isInService = false;		// The Service Mode is off
			break;

		default: isInService = true;		// The Service Mode is on
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
			//Display an error message
			cout << "That is not a valid menu option. \n Please try again." << endl;
			cout << "________________________________________________________________________" << endl << endl;
			break;
		}
	} while (isInService == true);


	// Display a good-bye message
	cout << "I sure had fun playing the Nim game with you!" << endl << endl;
	cout << "Please enter any charcter and a return to quit the program. ";

	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;
}




//*******************************************************************************************
// The displayhelp function displays directions for the game, and also instructions on		*
// how to change the game settings.																			*
//*******************************************************************************************

void displayhelp()
{
	cout << "    The Nim game is a simple game where two players take turns removing";
	cout << " \n coins from a pile of coins. Before the game starts, you can negotiate";
	cout << " \n the total number of coins that you begin with, as well as the maximum";
	cout << " \n number of coins that a player can take in a turn. \n ";
	cout << "   You can also choose whether the player that takes the last coin is ";
	cout << " \n the winner or the loser. Likewise, you can also state whether the ";
	cout << " \n computer goes first or whether you go first." << endl;
	cout << "________________________________________________________________________" << endl;

	cout << "\n   To play with the current settings, press P on the menu screen ";
	cout << "\n followed by an enter. Otherwise, you can change any of the settings";
	cout << "\n before you start playing by typing the letter corresponding to the";
	cout << "\n menu choice and then pressing enter." << endl;
	cout << "________________________________________________________________________" << endl << endl;

	// Wait for the user input before continuing the program
	cout << "Please type any character followed by an enter, and I will display the \n menu again: ";
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter; // Wait to read in a character input from the keyboard
	cout << "________________________________________________________________________" << endl << endl;
}

//*******************************************************************************************
// The displaymenu function displays the menu for changing game settings.																			*
//*******************************************************************************************

void displaymenu()
{

	cout << "Please input the character corresponding to the menu choice." << endl << endl;

	cout << "N : change the Number of coins to begin with." << endl;
	cout << "M : change the Maximum number of coins a player can take on a turn." << endl;
	cout << "U : select the User, you, as the player who takes the first turn." << endl;
	cout << "C : select the Computer as the player who takes the first turn." << endl;
	cout << "W : the person who takes the last coin will be the Winner." << endl;
	cout << "L : the person who takes the last coin will be the Loser." << endl << endl;

	cout << "P : Play the game with the current settings." << endl;
	cout << "H : display the Help secion." << endl;
	cout << "Q : Quit the program." << endl;
	cout << "________________________________________________________________________" << endl << endl;
}

//*******************************************************************************************
// The displaysettings function displays the current game settings.							*
//*******************************************************************************************

void displaysettings()
{
	cout << "Current Settings:";
	cout << " \n number of coins to begin with, n = " << n;
	cout << " \n maximum number of coins a player can take on a turn, m = " << m;

	cout << " \n the player that starts the game:  ";
	if (userfirst)
		cout << "user";
	else
		cout << "computer";

	cout << " \n the player that takes the last coin is the: "; //winner or loser
	if (lastwins)
		cout << "winner";
	else
		cout << "loser";
	cout << endl;
	cout << "________________________________________________________________________" << endl << endl;
}

//*******************************************************************************************
// The getnumber function gets the new m or n value when changing game settings.			*																		*
//*******************************************************************************************

int getnumber(string number)
{
	int num;			// for storing the value entered by the user
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error

	do {
		cout << "Please enter a positive integer for " << number << " to change the number of coins." << endl;
		cout << number << " = ";
		cin >> num;

		// Validate the input
		if (num < 1)
			if (number == "n")
				cout << "\n There must be at least one coin in the pile. \n Please try again." << endl << endl;
			else
				cout << "\n You must be able to take at least one coin. \n Please try again." << endl << endl;

		if (cin.fail())
		{
			while (!(cin >> num) || num < 1)
			{
				cerr << "\n Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	} while (num < 1);


	cout << "________________________________________________________________________" << endl << endl;
	return num;
}

//*******************************************************************************************
// The randcoin function chooses a number that the computer will take away between 1 and m.	*													*																		*
//*******************************************************************************************

int randcoin()
{
	srand((unsigned int)time(NULL));

	if (k < m)		// We don't want a random value bigger than k!
		return (rand() % k) + 1;
	else
		return (rand() % m) + 1;
}

//*******************************************************************************************
// The nimgame function begins gameplay.													*																		*
//*******************************************************************************************

void nimgame()
{
	// Declare variables
	int coins;		// number of coins taken from the pile
	bool userturn;  //stores who's turn it is
	k = n;		//initialize the current number of coins in the pile.

	if (userfirst)
		userturn = true;
	else
		userturn = false;

	while (k > 0)
	{
		if (userturn)
		{
			// Say who's turn it is
			cout << "User's turn: ";

			// Prompt user to take some coins
			do {
				cout << "\n How many coins would you like to take? ";
				cin >> coins;
				cout << endl;

				// Validate the input
				if (coins > m)
					cout << "Computer's comments: \n Hey! You cannot take out more than " << m << " coins.";
				else if (coins < 1)
					cout << "Computer's comments: \n Hey! You have to take at least 1 coin.";
				else if (coins > k)
					cout << "Computer's comments: \n Hey! You are trying to take more coins than are left in the pile! ";

				if (cin.fail())
				{
					while (!(cin >> coins) || coins < 1 || coins > m || coins > k)
					{
						cerr << "\n Invalid input, try again: ";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				}
			} while (coins < 1 || coins > m || coins > k);

			// Update the value of k based on how many coins the user took.
			k = k - coins;

			// Tell the user how many coins are left
			cout << "There are now " << k << " coins left in the pile." << endl;

			// Now it will be the computer's turn
			userturn = false;
			cout << "________________________________________________________________________" << endl << endl;
		}
		else
		{
			// Say who's turn it is
			cout << "Computer's turn: ";

			// Computer takes away coins
			coins = randcoin();
			cout << "\n The computer took away " << coins << " coins." << endl << endl;

			// Update k based on how many coins the computer took
			k = k - coins;

			// Tell the user how many coins are left
			cout << "There are now " << k << " coins left in the pile." << endl;

			// Now it will be the user's turn
			userturn = true;
			cout << "________________________________________________________________________" << endl << endl;
		}
	}
	// Now that k = 0, we need to determine who won.
	if (lastwins)
		if (userturn)		//This means the computer took the last turn and thus the last coin.
			cout << "I win! Do you want to play again?" << endl << endl;
		else
			cout << "Congratulations! You won!" << endl << endl;
	else					//last loses
		if (userturn)		//Computer took the last turn and thus the last coin.
			cout << "Congratulations! You won!" << endl << endl;
		else
			cout << "I win! Do you want to play again?" << endl << endl;


	// Wait for the user input before continuing the program
	cout << "Please type any character followed by an enter, and I will display the \n menu again: ";
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter; // Wait to read in a character input from the keyboard
	cout << "________________________________________________________________________" << endl << endl;

}