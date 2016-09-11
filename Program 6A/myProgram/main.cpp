

// Program 6A : Using Arrays and File Input/Output

#include <iostream>  
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

// Global Variable
bool isInService;					// for indicating whether the program should still be running

// Function prototypes
void displayMenu();
int keyboard(int & numStudents, double scores[]);
void writetofile(string filename, int numStudents, double scores[]);
int readfile(string filename, double scores[]);
void displayscores(int numStudents, double scores[]);
void modifyscores(int numStudents, double scores[]);


int main()

{
	// Declaration of variables
	char option;					// for storing the user's menu choice
	int numStudents = 0;
	double scores[100];				// stores their test scores
	string filename = "file";		// initializes the string

	// Display a greeting
	// Display a greeting
	cout << "Hello, and welcome to the test score program! ";
	cout << "\n This program lets you store the test scores of up to";
	cout << "\n 100 students and save the scores into a file." << endl << endl;

	// Beginning of while statement
	do
	{
		// Display a menu and get the user's menu choice
		displayMenu();
		cin >> option;
		cout << endl;

		// Call on the appropriate function depending on what the user entered.
		switch (option)
		{
		case 'K':
		case 'k': numStudents = keyboard(numStudents, scores);
			isInService = true;
			break;

		case 'W':
		case 'w':
			writetofile(filename, numStudents, scores);
			isInService = true;
			break;

		case 'R':
		case 'r': numStudents = readfile(filename, scores);
			isInService = true;
			break;

		case 'D':
		case 'd': displayscores(numStudents, scores);
			isInService = true;
			break;

		case 'M':
		case 'm': modifyscores(numStudents, scores);
			isInService = true;
			break;

		case 'Q':
		case 'q': isInService = false;		// The Service Mode is off
			break;

		default:
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
			//Display an error message
			cout << "That is not a valid menu option. \n Please try again, or type Q to quit." << endl << endl;
			isInService = true;		// The Service Mode is on
			break;
		}
	} while (isInService == true);

	// End of the while statement


	// Display a good-bye message
	cout << endl << "Thank you for using this program." << endl;
	cout << "Please type any charcter and press enter to quit the program." << endl;

	// Wait for the user input before ending the program
	char inputCharacter;
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
	cin >> inputCharacter;

	//Finish the program and return the control to the operating system.
	return 0;
}

//*******************************************************************************************
//The displayMenu function prints the menu out to the screen                                *
//*******************************************************************************************
void displayMenu()
{
	cout << "Please input the character corresponding to the menu choice." << endl;
	cout << "K : use the keybard to manually enter test scores." << endl;
	cout << "W : write the test scores into a file." << endl;
	cout << "R : read in test scores from a file." << endl;
	cout << "D : display the current list of scores." << endl;
	cout << "M : modify one of the scores." << endl;
	cout << "Q : quits the program." << endl << endl;
}


//*******************************************************************************************
//The keyboard function gets input from the keyboard and stores it in an array              *
//*******************************************************************************************
int keyboard(int & numStudents, double scores[])
{
	//Get the number of students from the user
	cout << "\n How many students do you want the enter scores for?";
	cout << "\n # of students = ";
	cin >> numStudents;

	// Validate the input
	while (numStudents > 100)
	{
		cout << "Sorry, that is too many students. Please enter 100 or less." << endl;
		cout << "\n # of students = ";
		cin >> numStudents;
	}
	while (numStudents < 1)
	{
		cout << "Sorry, that is too few students. Please enter 1 or more." << endl;
		cout << "\n # of students = ";
		cin >> numStudents;
	}

	if (cin.fail())		//The program will not move on until they enter an integer
	{
		while (!(cin >> numStudents))
		{
			cerr << "Invalid input, try again: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	// Tell the user how to enter the scores and stop the loop
	cout << "\n Please type the scores one-by-one, followed by an enter.";
	cout << "\n If you want to cancel entering scores, type -1 to stop.";
	cout << "\n Then you will return to the main menu." << endl << endl;

	// Write the array to store in the scores for that number of students
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Score for student " << i + 1 << " = ";
		cin >> scores[i];

		if (cin.fail())		//The program will not move on if it receives invalid input
		{
			while (!(cin >> scores[i]))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		//Stop the loop if they are done entering scores
		if (scores[i] == -1)
		{
			numStudents = i;
			cout << "You have scores entered for " << numStudents << " students." << endl << endl;
			break;
		}
	}
	cout << endl;
	return numStudents;
}


//*******************************************************************************************
//This writes into a file the number of student and the test scores currently in the scores *
// array.																					*
//*******************************************************************************************
void writetofile(string filename, int numStudents, double scores[])
{
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student. ";
		cout << "You may need to input scores. Press K or R on the main menu." << endl << endl;
	}
	else
	{
		//Get the file name from the user
		cout << "What would you like to name your file? ";
		cin >> filename;
		cout << endl;

		// Create the file
		filename = filename + ".txt";
		ofstream fout;
		fout.open(filename.c_str());

		// Output the data to the file
		cout << setprecision(3);
		fout << numStudents << endl;
		for (int i = 0; i < numStudents; i++)
		{
			fout << scores[i] << endl;
		}
		fout.close();
		cout << endl;
		cout << "Success! The scores were stored in " << filename << endl << endl;
	}
}

//*******************************************************************************************
//This reads the scores out of a file that was previously created by this program.			*
//*******************************************************************************************
int readfile(string filename, double scores[])
{
	int numStudents;
	double foo;

	//Get the file name from the user
	cout << "What is the name of the file you would like to open? ";
	cin >> filename;
	cout << endl;

	// Open the file
	filename = filename + ".txt";
	ifstream fin;
	fin.open(filename);
	cout << "I am trying to open " << filename << endl;


	// Validate that the file is open
	if (fin.is_open())
	{
		// Get numStudents
		fin >> numStudents;
		cout << "# of students = " << numStudents << endl;

		// Get scores
		for (int i = 0; i < numStudents; i++)
		{
			fin >> foo;
			scores[i] = foo;
			if (fin.fail())
			{
				cout << "Reached the end of the file." << endl;
				break;
			}
		}
		fin.close();
		cout << "Success! The scores were read in from the file." << endl << endl;
		return numStudents;
	}
	else
	{
		numStudents = 0;
		cout << "Unable to open file, please try again." << endl << endl;
		return numStudents;
	}
}


//*******************************************************************************************
// This displays the scores currently stored in the array. It also calculates and displays 	*
// the average of the scores, the highest score, and the lowest score.						*
//*******************************************************************************************
void displayscores(int numStudents, double scores[])
{
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student. ";
		cout << "You may need to input scores. Press K or R on the main menu." << endl;
	}
	else
	{
		cout << setprecision(3);
		cout << "The number of students that have scores entered is " << numStudents << "." << endl;
		for (int i = 0; i < numStudents; i++)
		{
			cout << scores[i] << endl;
		}
	}
	cout << endl;
}

void modifyscores(int numStudents, double scores[])
{
	int i;	//holds row number

	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student. ";
		cout << "You may need to input scores. Press K or R on the main menu." << endl << endl;
	}
	else
	{
		// Ask the user for the element they want to change
		cout << "Which row do you want to modify the score for? ";
		cin >> i;
		cout << endl;

		// Validate the row number
		while (i > numStudents)
		{
			cout << "Sorry, that row does not exist. Please enter " << numStudents << " or less." << endl;
			cout << "\n row = ";
			cin >> i;
			cout << endl;
		}
		while (i < 1)
		{
			cout << "Sorry, that row does not exist. Please enter 1 or more." << endl;
			cout << "\n row = ";
			cin >> i;
			cout << endl;
		}

		if (cin.fail())		//The program will not move on until they enter an integer
		{
			while (!(cin >> i))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Get the new content for row i
		double newscore;
		cout << "What is the new score you want to store in row " << i << "? ";
		cin >> newscore;

		//Validate the input for the new score
		if (cin.fail())		//The program will not move on if it receives invalid input
		{
			while (!(cin >> newscore))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		// Change the new score in the array
		scores[i - 1] = newscore;
		cout << endl;
	}
}