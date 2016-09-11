

// Midterm Project: Nim Game -- Coach Version
//Currnetly need to finish void nimgame() and bool isOptimalMove(int coins)


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

// Function Prototypes for the Main Menu
void displayhelp();
void displaymenu();
void displaysettings();
int  getnumber(string);

// Function Prototypes for gameplay
void nimgame();
int  optimal();
int  randcoin();
bool existsGoodMove();
int  takecoins();



int main()

{
	// Display a welcome message
	cout << endl << "Hello! Welcome to the Nim game!" << endl;
	cout << "________________________________________________________________________" << endl << endl;
	
	// Declaration of variables and initial values
	m = 3;
	n = 13;
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
	cout << "Please enter any character and a return to quit the program. ";

	// Wait for the user input before ending the program
	char inputCharacter;    // Declare a variable for storing a character input from the keyboard
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter; // Wait to read in a character input from the keyboard


	//Finish the program and return the control to the operating system.
	return 0;
}


//*******************************************************************************************
// The displayhelp function displays directions for the game, and also instructions on		*
// how to change the game settings.															*
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
// The displaymenu function displays the menu for changing game settings.					*
//*******************************************************************************************
void displaymenu()
{
	
	cout << "Please input the character corresponding to the menu choice." << endl << endl;

	cout << "P : Play the game with the current settings." << endl;
	cout << "H : display the Help secion." << endl;
	cout << "Q : Quit the program." << endl << endl;

	cout << "Change Settings: \n";
	cout << "N : change the Number of coins to begin with. \n";
	cout << "M : change the Maximum number of coins a player can take on a turn. \n";
	cout << "U : select the User, you, as the player who takes the first turn. \n";
	cout << "C : select the Computer as the player who takes the first turn. \n";
	cout << "W : the person who takes the last coin will be the Winner. \n" ;
	cout << "L : the person who takes the last coin will be the Loser." << endl << endl;
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
// The getnumber function gets the new m or n value when changing game settings.			*
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
// The nimgame function begins gameplay.													*
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

			// Say if there is a good move for the user
			if (existsGoodMove())
				cout << "\n There is an optimal move for you to take." << endl;
			else
				cout << "\n There is no good move for you." << endl;


			// Need a boolean variable for continuing the loop
			bool checkMoveAgain;
			char inputChar;

			do {
				// Prompt user to take some coins
				coins = takecoins();

				// Offer user to take a different number of coins if they did not do the optimal move. 
				if (existsGoodMove())
					if (coins == optimal())			//this is a safe move because there is a good move -- optimal will not use randcoin().
						checkMoveAgain = false;			//exits the do-while loop
					else
					{
						//Ask them if they want to redo their move?
						cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
						cout << "The move you took is not the optimal move." << endl;
						cout << "Do you want to try your move again? \n Press Y for yes or N for no, followed by an enter. ";
						cin >> inputChar;
						if (inputChar == 'y' || inputChar == 'Y')
							checkMoveAgain = true;	//this will check for the optimal move again
						else
							checkMoveAgain = false;		//this will exit the loop
					}
				else
					checkMoveAgain = false;			//there was no good move possible
			} while (checkMoveAgain);


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

			// Say if there is a good move for the computer
			if(existsGoodMove())
				cout << "\n There is an optimal move for the computer to take." << endl;
			else
				cout << "\n There is no good move for the computer." << endl;

			// Computer takes away coins
			coins = optimal();
			
			// Offer the user the opportunity to have the computer take away a random number of coins instead
			char inputChar2;
			if (existsGoodMove())
			{
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
				cout << endl << "There will not be a good move for your turn. Do you want";
				cout << "\n the computer to take away a random number of coins instead?";
				cout << "\n Press Y for yes or N for no, followed by an enter. ";
				cin >> inputChar2;
				cout << endl;
				if (inputChar2 == 'y' || inputChar2 == 'Y')
					coins = randcoin();
			}

			// Update k based on how many coins the computer took
			k = k - coins;

			// Tell the user how many coins are left
			cout << "\n The computer took away " << coins << " coins." << endl << endl;
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


//*******************************************************************************************
// The optimal function determines the number of coins that is the optimal move. If there	*
// is no optimal move, it implements randcoin().
//*******************************************************************************************
int optimal()
{
	//Define coins in this function
	int coins;
	int i;		//counter variable

	if (lastwins)
	{
		if (!existsGoodMove())
			coins = randcoin();
		else
			for (i = 1; i < m + 1; i++)
			{
				if ((k - i) % (m + 1) == 0)
				{
					coins = i;
					break;
				}
			}
	}
	else
	{
		if (!existsGoodMove())
			coins = randcoin();
		else
			for (i = 1; i < m + 1; i++)
			{
				if ((k - 1 - i) % (m + 1) == 0)
				{
					coins = i;
					break;
				}
			}
	}

	return coins;
}


//*******************************************************************************************
// The randcoin function chooses a number between 1 and m that represents how many coins	*
// that the computer will take away from the pile.											*
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
// The existsGoodMove function returns false or true based on whether there is a good move 	*
// for the player whose turn it currently is.													*
//*******************************************************************************************
bool existsGoodMove()
{
	if (lastwins)
	{
		if (k % (m + 1) == 0)
			return false;
		else
			return true;
	}
	else
	{
		if ((k - 1) % (m + 1) == 0)
			return false;
		else
			return true;
	}
}


//*******************************************************************************************
// The takecoins function gets the number of coins the user wants to take out of the pile.	*
// It checks to make sure that the number is valid.
//*******************************************************************************************
int takecoins()
{
	int coins;

	do {
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
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

	return coins;
}