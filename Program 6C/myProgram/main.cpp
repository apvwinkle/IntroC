

// Program 6C : Using Files and Sorting Arrays

#include <iostream>  
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std; 

// Structure
struct Record
{
	string firstname;
	string lastname;
	double score;
};

// Global Variable
bool isInService;					// for indicating whether the program should still be running
int numStudents = 0;
Record studentRecord[100];				// stores their test scores

// Function prototypes
void displayMenu();
void keyboard();
void writetofile();
int readfile();
void displayscores();
void calculate();
void modifyscores();
void sortbyName();
void sortbyScore();


int main()

{
	// Declaration of variable
	char option;					// for storing the user's menu choice

	// Display a greeting
	cout << "Hello, and welcome to the test score program! ";
	cout << "\n This program lets you store the test scores of up to";
	cout << "\n 100 students and save their names and scores into a file." << endl << endl;

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
		case 'k': keyboard();
			isInService = true;
			break;

		case 'W':
		case 'w': 
			writetofile();
			isInService = true;
			break;

		case 'R':
		case 'r': numStudents = readfile();
			isInService = true;
			break;

		case 'D':
		case 'd': displayscores();
			isInService = true;
			break;

		case 'M':
		case 'm': modifyscores();
			isInService = true;
			break;

		case 'N':
		case 'n': sortbyName();
			displayscores();
			isInService = true;
			break;

		case 'S':
		case 's': sortbyScore();
			displayscores();
			isInService = true;
			break;

		case 'C':
		case 'c': calculate();
			isInService = true;
			break;

		case 'Q':
		case 'q': 
			if (numStudents > 0)
			{
				cout << "Are you sure you want to quit? All unsaved data will be lost.";
				cout << "\n Please press S to save data, or any other character to quit. ";
				// Wait for the user input before ending the program
				char inputCharacter;
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
				cin >> inputCharacter;
				cout << endl;

				//Determine if data needs to be saved.
				if (inputCharacter == 'S' || inputCharacter == 's')
				{
					writetofile();

					// Wait for the user input before ending the program
					char inputCharacter;
					cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
					cout << "Press any character to exit the program. ";
					cin >> inputCharacter;
					cout << endl;
				}
			}

			//Stop the loop
			isInService = false;		// The Service Mode is off
			break;

		default: 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error
			//Display an error message
			cout << "That is not a valid menu option. \n Please try again, or type Q to quit." << endl << endl;
			isInService = true;		// The Service Mode is on
			break;
		}
	} while (isInService == true);

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
	cout << "N : sort the students by last name." << endl;
	cout << "S : sort the students by their scores." << endl;
	cout << "C : calculate the average, highest, and lowest scores." << endl;
	cout << "Q : quits the program." << endl << endl;
}


//*******************************************************************************************
//The keyboard function gets input from the keyboard and stores it in an array              *
//*******************************************************************************************
void keyboard()
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
	cout << "\n Please type the student names and their scores one-by-one. ";
	cout << "\n Type the input asked for, followed by an enter. At the end,";
	cout << "\n you will return to the main menu." << endl;
	cout << "\n If there are spaces in the student's first or last name, ";
	cout << "\n please do not include them." << endl << endl;

	// Write the array to store in the scores for that number of students
	for (int i = 0; i < numStudents; i++)
	{
		cout << "For student " << i + 1 << ": ";

		//Get and validate the first name
		cout << "\n\t first name: ";
		cin >> studentRecord[i].firstname;

		if (cin.fail())		//The program will not move on if it receives invalid input
		{
			while (!(cin >> studentRecord[i].firstname))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		 //Get and validate the last name
		cout << "\t last name: ";
		cin >> studentRecord[i].lastname;

		if (cin.fail())		//The program will not move on if it receives invalid input
		{
			while (!(cin >> studentRecord[i].lastname))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}

		//Get and validate the score
		cout << "\t score = ";
		cin >> studentRecord[i].score;

		if (cin.fail())		//The program will not move on if it receives invalid input
		{
			while (!(cin >> studentRecord[i].score))
			{
				cerr << "Invalid input, try again: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	cout << endl;

	//Stop the loop if they are done entering scores
	cout << "You have scores entered for " << numStudents << " students." << endl << endl;

	return;
}


//*******************************************************************************************
//This writes into a file the number of student and the test scores currently in the scores *
// array.																					*
//*******************************************************************************************
void writetofile()
{
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
		cout << "\n You may need to input scores. Press K or R on the main menu." << endl << endl;
		return;
	}
	
	string filename = "file";		// initializes the string

	//Get the file name from the user
	cout << "What would you like to name your file? ";
	cin >> filename;
	cout << endl;

	// Create the file
	filename = filename + ".txt";
	ofstream fout;
	fout.open(filename.c_str());

	// Output the data to the file
	cout << setprecision(5);
	fout << numStudents << endl;			//First line in the file is the number of students
	for (int i = 0; i < numStudents; i++)
	{
		fout << studentRecord[i].firstname << endl;
		fout << studentRecord[i].lastname << endl;
		fout << studentRecord[i].score << endl;
	}
	fout.close();
	cout << endl;
	cout << "Success! The scores were stored in " << filename << endl << endl;
	return;
}


//*******************************************************************************************
//This reads the scores out of a file that was previously created by this program.			*
//*******************************************************************************************
int readfile()
{
	int numStudents;
	string filename = "file";		// initializes the string
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); //cleans up user error


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
			fin >> studentRecord[i].firstname;
			fin >> studentRecord[i].lastname;
			fin >> studentRecord[i].score;

			if (fin.fail())
			{
				cout << "Reached the end of the file." << endl;
				break;
			}
		}
		fin.close();
		cout << "Success! The scores were read in from the file." << endl << endl;
	}
	else
	{
		numStudents = 0;
		cout << "Unable to open file, please try again." << endl << endl;
	}
	return numStudents;
}


//*******************************************************************************************
// This displays the scores currently stored in the array.									*
//*******************************************************************************************
void displayscores()
{
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
		cout << "\n You may need to input scores. Press K or R on the main menu." << endl << endl;
		return;
	}

	//If there is data, write the scores to the screen one-by-one
	cout << setprecision(3);
	cout << "The number of students that have scores entered is " << numStudents << "." << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout.width(20);	cout << left << studentRecord[i].firstname;
		cout.width(20);	cout << left << studentRecord[i].lastname;
		cout.width(20);	cout << left << studentRecord[i].score << endl;
	}

	cout << endl;
	return;
}


//*******************************************************************************************
// This calculates and displays the average of the scores, the highest score, and the		*
// lowest score.																			*
//*******************************************************************************************
void calculate()
{
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
		cout << "\n You may need to input scores. Press K or R on the main menu." << endl << endl;
	}
	else
	{
		//Calculating the average, highest, and lowest scores.
		double highest = studentRecord[0].score;
		double lowest = studentRecord[0].score;
		double average = studentRecord[0].score;

		for (int i = 1; i < numStudents; i++)
		{
			if (studentRecord[i].score > highest)
				highest = studentRecord[i].score;
			if (studentRecord[i].score < lowest)
				lowest = studentRecord[i].score;

			average = average + studentRecord[i].score;
		}
		average = average / numStudents;
		cout << "The average score is " << average << "." << endl << endl;

		//Display the people who have the highest score
		cout << "The highest score is " << highest << ".";
		cout << "\nThe people with that score are:";
		for (int i = 0; i < numStudents; i++)
		{
			if (studentRecord[i].score == highest)
				cout << "\n  " << studentRecord[i].firstname << " " << studentRecord[i].lastname;
		}
		cout << endl << endl;

		//Display the people who have the lowest score
		cout << "The lowest score is " << lowest << ".";
		cout << " \nThe people with that score are:";
		for (int i = 0; i < numStudents; i++)
		{
			if (studentRecord[i].score == lowest)
				cout << "\n  " << studentRecord[i].firstname << " " << studentRecord[i].lastname;
		}
		cout << endl << endl;
	}
	return;
}

//*******************************************************************************************
// This allows the user to modify one of the  scores currently stored in the array.		 	*
//*******************************************************************************************
void modifyscores()
{
	int i;	//holds row number
	
	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
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

			// Make variables to store the new info 
			string newFirstname;
			string newLastname;
			double newScore;

			//Get and validate the new First Name
			cout << "What is the new first name for row " << i << "? ";
			cin >> newFirstname;

			if (cin.fail())		//The program will not move on if it receives invalid input
			{
				while (!(cin >> newFirstname))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			
			//Get and validate the new Last Name
			cout << "What is the new last name for row " << i << "? ";
			cin >> newLastname;

			if (cin.fail())		//The program will not move on if it receives invalid input
			{
				while (!(cin >> newLastname))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			//Get and validate the new score
			cout << "What is the new score for row " << i << "? ";
			cin >> newScore;

			if (cin.fail())		//The program will not move on if it receives invalid input
			{
				while (!(cin >> newScore))
				{
					cerr << "Invalid input, try again: ";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			// Change the new score in the array
			studentRecord[i - 1].firstname = newFirstname;
			studentRecord[i - 1].lastname = newLastname;
			studentRecord[i - 1].score = newScore;
			cout << endl;
	}
}


//*******************************************************************************************
// This allows the user to sort the scores of the students in numerical order.				*
//*******************************************************************************************
void sortbyScore()
{
	int i, j; //counter variables
	Record foo;

	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
		cout << "You may need to input scores. Press K or R on the main menu." << endl << endl;
	}
	else
	{
		// Sort the students by checking 
		for (i = 0; i < numStudents; i++)
			for (j = i; j < numStudents; j++)
				if (studentRecord[j].score < studentRecord[i].score)
				{
					//Store the info from index i
					foo.score = studentRecord[i].score;
					foo.lastname = studentRecord[i].lastname;
					foo.firstname = studentRecord[i].firstname;

					//Replace index i with index j
					studentRecord[i].score = studentRecord[j].score;
					studentRecord[i].lastname = studentRecord[j].lastname;
					studentRecord[i].firstname = studentRecord[j].firstname;

					//Replace index j with the stored info from index i
					studentRecord[j].score = foo.score;
					studentRecord[j].firstname = foo.firstname;
					studentRecord[j].lastname = foo.lastname;
				}
	}
	return;
}


//*******************************************************************************************
// This allows the user to sort the names of the students in alphabetical order.			*
//*******************************************************************************************
void sortbyName()
{
	int i, j; //counter variables
	Record foo;

	// Check to make sure there is data
	if (numStudents < 1)
	{
		cout << "Error! There is not even one student.";
		cout << "You may need to input scores. Press K or R on the main menu." << endl << endl;
	}
	else
	{
		// Sort the students by checking 
		for (i = 0; i < numStudents; i++)
			for (j = i; j < numStudents; j++)
			{
				if (studentRecord[j].lastname < studentRecord[i].lastname)
				{
					//Store the info from index i
					foo.score = studentRecord[i].score;
					foo.lastname = studentRecord[i].lastname;
					foo.firstname = studentRecord[i].firstname;

					//Replace index i with index j
					studentRecord[i].score = studentRecord[j].score;
					studentRecord[i].lastname = studentRecord[j].lastname;
					studentRecord[i].firstname = studentRecord[j].firstname;

					//Replace index j with the stored info from index i
					studentRecord[j].score = foo.score;
					studentRecord[j].firstname = foo.firstname;
					studentRecord[j].lastname = foo.lastname;
				}
				else if (studentRecord[j].lastname == studentRecord[i].lastname)
					if (studentRecord[j].firstname < studentRecord[i].firstname)
					{
						//Store the info from index i
						foo.score = studentRecord[i].score;
						foo.lastname = studentRecord[i].lastname;
						foo.firstname = studentRecord[i].firstname;

						//Replace index i with index j
						studentRecord[i].score = studentRecord[j].score;
						studentRecord[i].lastname = studentRecord[j].lastname;
						studentRecord[i].firstname = studentRecord[j].firstname;

						//Replace index j with the stored info from index i
						studentRecord[j].score = foo.score;
						studentRecord[j].firstname = foo.firstname;
						studentRecord[j].lastname = foo.lastname;
					}
			}
	}
	return;
}