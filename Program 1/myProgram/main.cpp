



// Program #1: Converts US dollar amounts to Taiwanese dollars

# include <iostream>

using namespace std;


int main()

{
	// Declaration of variables
	int pennies, nickles, dimes, quarters,
		UScent, totUS, USdol,
		TaiCent, totTai, TaiDol;

	// Ask the user what type of money they have
	cout << "Hello, welcome to the US to Taiwanese exchange rate program!" << endl << endl;
	cout << "First off, how many pennies do you have?" << endl;
	cin >> pennies;
	cout << endl << "How many nickles do you have?" << endl;
	cin >> nickles;
	cout << endl << "How many dimes do you have?" << endl;
	cin >> dimes;
	cout << endl << "Lastly, how many quarters do you have?" << endl;
	cin >> quarters;

	// The total in US cents
	totUS = 25 * quarters + 10 * dimes + 5 * nickles + 1 * pennies;
	cout << endl << endl << "The total you have is " << totUS << " US cents." << endl;

	// The amount in US dollars and cents
	USdol = totUS / 100;
	UScent = totUS % 100;
	cout << "This is equivalent to " << USdol << " US dollars and " << UScent << " US cents." << endl;

	// The total in Taiwanese cents
	totTai = totUS * 33;
	cout << "This can exchange for " << totTai << " Taiwanese cents." << endl;

	// The amount in Taiwanese dollars and cents
	TaiDol = totTai / 100;
	TaiCent = totTai % 100;
	cout << "This is equal to " << TaiDol << " Taiwanese dollars and " << TaiCent << " Taiwanese cents." << endl;

	// Ask the user to quit the program
	cout << endl << endl << "Thank you for using the US to Taiwanese exchange rate program!" << endl << endl
		<< "To exit the program, hit any key followed by a return." << endl;
	char exit_key;
	cin >> exit_key;

	//Finish the program and return the control to the operating system.
	return 0;

}

//End of the main function.



