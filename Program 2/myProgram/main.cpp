

// Program #2: A payroll program


#include <iostream> 

using namespace std;


int main()

{
	// Declaration of variables
	int age;
	double hours_worked, overtime_hours, regular_hours,
		regular_pay_rate, overtime_pay_rate, overtime_pay, regular_pay, 
		gross_pay, union_dues, net_pay;

	// Declaration of constants
	double YOUNG_UNION_DUES = 15.0,
		OLD_UNION_DUES = 5.0,
		OVERTIME_RATE_MULTIPLIER = 1.5;


	// Get the worker's age, hours worked that week, and their hourly pay rate
	cout << "Hello, welcome to the pay calculating program!" << endl << endl;
	cout << "What is your age?" << endl;
	cin >> age;

	cout << "How many hours did you work this week?" << endl;
	cin >> hours_worked;

	cout << "What is your hourly pay rate? Enter the amount in $." << endl;
	cin >> regular_pay_rate;


	// Calculate the pay for regular hours and overtime hours
	if (hours_worked > 40) //In this case, there is overtime
	{
		regular_hours = 40.0;
		overtime_hours = hours_worked - 40.0;
	}
	else //no overtime
	{
		regular_hours = hours_worked;
		overtime_hours = 0;
	}
	
	// Calculate the Gross Pay
	overtime_pay_rate = OVERTIME_RATE_MULTIPLIER * regular_pay_rate;
	overtime_pay = overtime_pay_rate * overtime_hours;
	regular_pay = regular_pay_rate * regular_hours;
	gross_pay = regular_pay + overtime_pay;

	// Calculate the Union Dues
	if (gross_pay >= 200)
	{
		if (age < 60)
			union_dues = YOUNG_UNION_DUES;
		else
			union_dues = OLD_UNION_DUES;
	}
	else
		union_dues = 0;

	// Calculate the Net Pay
	net_pay = gross_pay - union_dues;

	// Tell the user their results
	cout << endl << "Your gross pay is $" << gross_pay << "." << endl;
	cout << "Your union due is $" << union_dues << "." << endl;
	cout << "Therefore, your net pay is $" << net_pay << "." << endl <<endl;
	
	// Display a goodbye message

	cout << "It is a pleasure to calculate your pay for you." << endl;

	cout << "Please enter any charcter and a return to quit the program." << endl;

	// Wait for the user input before ending the program
	char goodbye_char;  
	cin >> goodbye_char;


	//Finish the program and return the control to the operating system.
	return 0;

}


