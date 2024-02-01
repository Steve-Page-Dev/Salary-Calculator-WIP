// Salary Calculator 2.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include "salary_Calculator.h"
using namespace std;

//Creating function to handle pay frequency determination.
int payFrequency() {

	//Asking for pay frequency.
	cout << "\nPlease select if you are paid weekly or bi-weekly. Enter 1 for weekly and 2 for bi-weekly: ";
	cin >> payCycleChoice;

	//Switch statement nested inside a while loop to handle pay frequency and errors from invalid entries.
	while (isPayCycleValid == false) {
		switch (payCycleChoice) {
		case 1:
			isPayCycleValid = true;
			weeklyPay = true;
			break;
		case 2:
			isPayCycleValid = true;
			biweeklyPay = true;
			break;
		default:
			isPayCycleValid = false;
			cout << "\nError. Please enter 1 for weekly pay or 2 for bi-weekly pay: ";
			cin >> payCycleChoice;
		}
	}
	return 0;
}

//Creating function to handle overtime calculations.
double overtimeCalculator() {
	//Calculating overtime hours and displaying them.
	overtimeHourlyWage = hourlyWage * overtimeMultiplier;
	cout << "\nYour estimated overtime hourly wage is: $" << overtimeHourlyWage << ".";

	//Calculating overtime total wage for a week and displaying it.(
	if (weeklyPay == true) {
		overtimeTotalWeek = overtimeHourlyWage * overtimeHours;
		cout << "\nYour estimated total wages from overtime in a week is: $" << overtimeTotalWeek << ".";
	}
	else if (biweeklyPay == true) {
		overtimeTotalWeek = overtimeHourlyWage * overtimeHours;
		overtimeTotalBiweekly = overtimeTotalWeek * 2;
		cout << "\nYour estimated total wages from overtime in two weeks is: $" << overtimeTotalBiweekly << ".";
	}

	//Calculating overtime total wage for a month and displaying it.
	overtimeTotalMonth = overtimeTotalWeek * weeksInMonth;
	cout << "\nYour estimated total wages from overtime in a month is: $" << overtimeTotalMonth << ".";

	//Calculating overtime total wage for a year and displaying it.
	overtimeTotalAnnual = overtimeTotalWeek * weeksInYear;
	cout << "\nYour estimated total wages from overtime in a year is: $" << overtimeTotalAnnual << ".";

	return 0;
}
//Creating function to handle wage calculations.
double wageCalculator() {
	/*TO DO::
	- Streamline the process using only weeksInYear for better accuracy
	*/
	//Creating a blank line for ease of reading.
	cout << endl;

	//Calculating weekly wages with overtime, displaying result and checking if pay frequency is weekly.
	if (weeklyPay == true) {
		weeklyWage = hourlyWage * hoursWorkedWeek;
		weeklyWageOT = weeklyWage + overtimeTotalWeek;
		cout << "\nYou make an estimated $" << weeklyWage << " per week, and $" << weeklyWageOT << " per week with overtime.";

		//Calculating monthly wages with overtime and displaying result.
		monthlyWage = (weeklyWageOT * weeksInYear) / 12;
		monthlyWageOT = monthlyWage + overtimeTotalMonth;
		cout << "\nYou make an estimated $" << monthlyWage << " per month, and $" << monthlyWageOT << " per month with overtime.";

		//Calculating annual wages with overtime and displaying the result.
		annualWage = weeklyWage * weeksInYear;
		annualWageOT = annualWage + overtimeTotalAnnual;
		cout << "\nYou make estimated $" << annualWage << " per year, and $" << annualWageOT << " per year with overtime.";

		//If function to handle overtime wage factor calculations displaying true hourly wage estimate with overtime considerations.
		if (overtimeHours != 0) {
			//Initializing variables to factor overtime into hourly wage. Dividing annual wage by 52 weeks, dividing that number by hoursWorkedWeek.
			double trueWageS1 = annualWageOT / 52;
			double trueWageS2 = trueWageS1 / hoursWorkedWeek;

			//Displaying result.
			cout << "\nWith overtime consideration, your estimated 'true' hourly wage is: $" << trueWageS2 << " an hour.";
		}
		else if (overtimeHours <= 0) {
			cout << "\nOperating with 0 hours of overtime. Your true wage is your hourly wage: " << hourlyWage;
			cout << "\nThis estimate would change if overtime is added.";
		}
	}
	//Calculating bi-weekly wages with overtime, displaying result, and checking if pay frequency is bi-weekly.
	else if (biweeklyPay == true) {

		weeklyWage = hourlyWage * hoursWorkedWeek;
		biweeklyWage = weeklyWage * 2;
		weeklyWageOT = weeklyWage + overtimeTotalWeek;
		biweeklyWageOT = weeklyWageOT * 2;
		cout << "\nYou make an estimated $" << biweeklyWage << " every 2 weeks, and $" << biweeklyWageOT << " every 2 weeks with overtime.";

		//Calculating monthly wages with overtime and displaying result.
		monthlyWage = (weeklyWageOT * weeksInYear) / 12;
		monthlyWageOT = monthlyWage + overtimeTotalMonth;
		cout << "\nYou make an estimated $" << monthlyWage << " per month, and $" << monthlyWageOT << " per month with overtime.";

		/* TO DO::
		 - Fix this!! Currently multiplying monthlyWage by 52 in grossly bloating calculations!!!
		 */
		 //Calculating annual wages with overtime and displaying the result.
		annualWage = monthlyWage * 12;
		annualWageOT = annualWage + overtimeTotalAnnual;
		cout << "\nYou make an estimated $" << annualWage << " per year, and $" << annualWageOT << " per year with overtime.";

		//If function to handle overtime wage factor calculations displaying true hourly wage estimate with overtime considerations.
		if (overtimeHours != 0) {
			//Initializing variables to factor overtime into hourly wage. Dividing annual wage by 52 weeks, dividing that number by hoursWorkedWeek.
			double trueWageS1 = annualWageOT / 52;
			double trueWageS2 = trueWageS1 / hoursWorkedWeek;

			//Displaying result.
			cout << "\nWith overtime consideration, your estimated 'true' hourly wage is: $" << trueWageS2 << " an hour.";
		}
		else if (overtimeHours <= 0) {
			cout << "\nOperating with 0 hours of overtime. Your true wage is your hourly wage: " << hourlyWage;
			cout << "\nThis estimate would change if overtime is added.";
		}
	}
	return 0;
}
//Creating function to handle state selection, feeding choice into tax calculator function.
double stateSelection() {
	//Declaring local variables
	bool isValidState = false;
	string state;
	double stateTax;

	//Struct to hold variables for state name, abbreviation and tax rates for the function to aid in the calulation of state taxes later in the program.
	struct State {
		string name;
		string abbreviation;
		double stateTax;
	};

	/* TO DO::
		- Add functionality so that input allows for different types of entry for a state. Ex// using lowercase letters for state abbreviation, capitals for state name, and so on.
	*/
	//Array of structs holding all 50 states, their abbreviations, and their tax rates.
	State states[50] = {
		{"Alabama", "AL", 0.04}, {"Alaska", "AK", 0}, {"Arizona", "AZ", 0.056}, {"Arkansas", "AR", 0.065}, {"California", "CA", 0.0725}, {"Colorado", "CO", 0.029}, {"Connecticut", "CT", 0.0635},
		{"Delaware", "DE", 0}, {"Florida", "FL", 0.06}, {"Georgia", "GA", 0.04}, {"Hawaii", "HI", 0.04}, {"Idaho", "ID", 0.06}, {"Illinois", "IL", 0.0625}, {"Indiana", "IN", 0.07}, {"Iowa", "IA", 0.06},
		{"Kansas", "KS", 0.065}, {"Kentucky", "KY", 0.06}, {"Louisiana", "LA", 0.0445}, {"Maine", "ME", 0.055}, {"Maryland", "MD", 0.06}, {"Massachusettes", "MA", 0.0625}, {"Michigan", "MI", 0.06},
		{"Minnesota", "MN", 0.06875}, {"Mississippi", "MS", 0.07}, {"Missouri", "MO", 0.04225}, {"Montana", "MT", 0}, {"Nebraska", "NE", 0.055}, {"Nevada", "NV", 0.0685}, {"New Hampshire", "NH", 0},
		{"New Jersey", "NJ", 0.06625}, {"New Mexico", "NM", 0.05125}, {"New York", "NY", 0.04}, {"North Carolina", "NC", 0.0475}, {"North Dakota", "ND", 0.05}, {"Ohio", "OH", 0.0575},
		{"Oklahoma", "OK", 0.045}, {"Oregon", "OR", 0}, {"Pennsylvania", "PA", 0.06}, {"Rhode Island", "RI", 0.07}, {"South Carolina", "SC", 0.06}, {"South Dakota", "SD", 0}, {"Tennessee", "TN", 0.07},
		{"Texas", "TX", 0.0625}, {"Utah", "UT", 0.0485}, {"Vermont", "VT", 0.06}, {"Virginia", "VA", 0.043} , {"Washington", "WA", 0.065}, {"West Virginia", "WV", 0.06}, {"Wisconsin", "WI", 0.05},
		{"Wyoming", "WY", 0.04}
	};

	/*Debug for array to verify size
	int size = sizeof(states) / sizeof(states[0]);
	cout << "Array size: " << size << endl;*/

	//Variable to hold the state entered by the user.
	State selectedState;

	//Checking user input against 52 states in array to insure that information entered is valid and repeating the query if it is not valid.
	while (!isValidState) {
		//Prompting the user for input to determine which state to use for state tax calculations.
		cout << "\nPlease enter the state that you work in: ";
		cin >> state;

		for (int i = 0; i < 52; i++) {
			if (state == states[i].name || state == states[i].abbreviation) {
				isValidState = true;
				//Sets the user entered state to the matching state in the array above.
				selectedState = states[i];
				break;
			}
		}
		if (!isValidState) {
			cout << "\nState choice invalid, please try again and enter the state name or abbreviation: " << endl;
		}
	}
	//Sets the stateTax variable to the user entered state's tax from the array above.
	if (isValidState) {
		stateTax = selectedState.stateTax;
	}
	//Displaying acceptance of state choice
	cout << "\nYour state selection is: " << state;
	//While loop to check for entry accuracy, looping the function if state entered is not correct.
	while (!isCorrectState) {
		cout << "\nIs your selection correct (yes or no): ";

		string stateAccuracyAnswer;
		cin >> stateAccuracyAnswer;

		if (stateAccuracyAnswer == "yes") {
			isCorrectState = true;

			cout << "\nYour estimated state tax rate is : " << stateTax;
		}
		else if (stateAccuracyAnswer == "no") {
			stateSelection();
		}
		else {
			cout << "\nInvalid input. Please enter 'yes' or 'no': " << endl;
		}
	}

	return stateTax;
}
//Creating function to handle tax calculations.
double taxCalculator() {
	//Spacer.
	cout << endl;

	//Calculating federal tax with if else if statements.
	if (annualWageOT > 0 && annualWageOT < 10275) {
		incomeTax = 0.10;

		cout << "\nYour estimated federal tax rate is 10%.";
	}
	else if (annualWageOT > 10275 && annualWageOT < 41775) {
		incomeTax = 0.12;

		cout << "\nYour estimated federal tax rate is 12%.";
	}
	else if (annualWageOT > 41775 && annualWageOT < 89075) {
		incomeTax = 0.22;

		cout << "\nYour estimated federal tax rate is 22%.";
	}
	else if (annualWageOT > 89075 && annualWageOT < 17050) {
		incomeTax = 0.24;

		cout << "\nYour estimated federal tax rate is 24%.";
	}
	else if (annualWageOT > 17050 && annualWageOT < 215950) {
		incomeTax = 0.32;

		cout << "\nYour estimated federal tax rate is 32%.";
	}
	else if (annualWageOT > 215950 && annualWageOT < 323925) {
		incomeTax = 0.35;

		cout << "\nYour estimated federal tax rate is 35%.";
	}
	else if (annualWageOT > 323925) {
		incomeTax = 0.37;

		cout << "\nYour estimated federal tax rate is 37%.";
	}
	//Spacer for ease of reading.
	cout << endl;

	//Checking pay cycle.
	if (weeklyPay == true) {
		//Initializing variables for weekly tax calculations.
		double firstWTax = weeklyWageOT * incomeTax;
		double secondWTax = weeklyWageOT * stateTax;
		double thirdWTax = weeklyWageOT * socialSecurityTax;
		double fourthWTax = weeklyWageOT * medicareTax;
		double weeklyTax = firstWTax + secondWTax + thirdWTax + fourthWTax;
		double weeklyTakeHome = weeklyWageOT - weeklyTax;

		//Diplaying result.
		cout << "\nYou pay an estimated $" << weeklyTax << " every week in taxes, with an estimated take home amount of $" << weeklyTakeHome << " after taxes.";
	}
	else if (biweeklyPay == true) {
		//Initializing variables for biweekly tax calculations.
		double firstBWTax = biweeklyWageOT * incomeTax;
		double secondBWTax = biweeklyWageOT * stateTax;
		double thirdBWTax = biweeklyWageOT * socialSecurityTax;
		double fourthBWTax = biweeklyWageOT * medicareTax;
		double biweeklyTax = firstBWTax + secondBWTax + thirdBWTax + fourthBWTax;
		double biweeklyTakeHome = biweeklyWageOT - biweeklyTax;

		//Diplaying result.
		cout << "\nYou pay an estimated $" << biweeklyTax << " every two weeks in taxes, with an estimated take home amount of $" << biweeklyTakeHome << " after taxes.";

	}
	//Initializing variables for monthly tax calculations.
	double firstMTax = monthlyWageOT * incomeTax;
	double secondMTax = monthlyWageOT * stateTax;
	double thirdMTax = monthlyWageOT * socialSecurityTax;
	double fourthMTax = monthlyWageOT * medicareTax;
	double monthlyTax = firstMTax + secondMTax + thirdMTax + fourthMTax;
	double monthlyTakeHome = monthlyWageOT - monthlyTax;

	//Diplaying result.
	cout << "\nYou pay an estimated $" << monthlyTax << " every month in taxes, with an estimated take home amount of $" << monthlyTakeHome << " after taxes.";

	//Initializing variables for annual tax calculations.
	double firstATax = annualWageOT * incomeTax;
	double secondATax = annualWageOT * stateTax;
	double thirdATax = annualWageOT * socialSecurityTax;
	double fourthATax = annualWageOT * medicareTax;
	double annualTax = firstATax + secondATax + thirdATax + fourthATax;
	double annualTakeHome = annualWageOT - annualTax;

	//Displaying result.
	cout << "\nYou pay an estimated $" << annualTax << " every year in taxes, with an estimated take home amount of $" << annualTakeHome << " after taxes.";
	//Spacer.
	cout << endl;

	
	/*
			TO DO:::
			- Add functionality for groceries, bills, and other non deduction based expenses for calculations.
			- Add functionality to determine if deductions are pre-tax or post tax (insurance, 401k, etc.)
			- Calculate and display a final amount accounting for all deductions and espenses to provide a
			  gross estimate of funds available to spend (FAS) per week/month/year.

	//Asking for user input for wage deductions.
	cout << "\nDo you have any wage deductions per pay cycle?? Please enter 1 for Yes or 2 for No: ";
	cin >> deductionChoice;
	//Nesting switch statment inside of while statement to handle choice loop.
	while (deductionLoop == false) {
		switch (deductionChoice) {
		case 1:
			deductionLoop = true;
			//Asking for user input on deductions and calculating weekly, monthly, and annual deductions.
			cout << "\nPlease enter your deductions (THIS FEATURE IS SEMI-FUNCTIONAL AND WILL BE FUNCTIONAL NEXT UPDATE): ";
			cin >> deductionAmount;

			 //Calculating weeklyTakeHome to aid in calculations.
			weeklyTakeHome = weeklyWageOT - weeklyTax;
			//Calculating weekly deductions.
			weeklyTakeHomeDeduction = weeklyTakeHome - deductionAmount;
			//Calculating monthlyTakeHome to aid in calculations.
			monthlyTakeHome = monthlyWageOT - monthlyTax;
			//Calculating monthly deductions.
			monthlyDeduction = deductionAmount * 4;
			monthlyTakeHomeDeduction = monthlyTakeHome - monthlyDeduction;
			//Calculating annualTakeHome to aid in calculations.
			annualTakeHome = annualWageOT - annualTax;
			//Calculating annual deductions.
			annualDeduction = monthlyDeduction * 12;
			annualTakeHomeDeduction = annualTakeHome - annualDeduction;

			//Displaying result.
			cout << "\nYour weekly deductions are: $" << deductionAmount << " bringing your weekly take home to: $" << weeklyTakeHomeDeduction << ".";
			cout << "\nYour monthly deductions are: $" << monthlyDeduction << " bringing your monthly take home to: $" << monthlyTakeHomeDeduction << ".";
			cout << "\nYour annual deductions are: $" << annualDeduction << " bringing your annual take home to: $" << annualTakeHomeDeduction << ".";
			break;
		case 2:
			deductionLoop = true;
			cout << "\nOperating with 0 deductions.";
			break;
		default:
			deductionLoop = false;
			cout << "\nError, invalid input. Please enter either a 1 for Yes or a 2 for No: ";
			cin >> deductionChoice;
		}
	}*/
	return 0;
}
double hoursTotals() {
	//Spacer.
	cout << endl;

	//Displaying total hours worked and total overtime hours worked for weekly and bi weekly pay.
	//FIX ME: Currently does not deduct overtimeHours from hoursWorkedWeek.
	totalHoursWorked = hoursWorkedWeek - overtimeHours;
	totalHoursWorkedBiWeekly = hoursWorkedWeek * 2;
	totalOvertimeHoursWorked = hoursWorkedWeek - 40;
	//If else statement to handle branch for determining biweekly pay.
	if (biweeklyPay == false) {

		cout << "You work " << totalHoursWorked << " hours a week." << endl;
		cout << "You work " << totalOvertimeHoursWorked << " hours of overtime a week." << endl;
		//Spacer.
		cout << endl;
	}
	else if (biweeklyPay == true) {
		//Multiplying totalOverTimeHoursWorked by 2 to accurately calculate overtime hours.
		totalOvertimeHoursWorked = overtimeHours * 2;

		cout << "You work " << totalHoursWorkedBiWeekly << " hours every two weeks." << endl;
		cout << "You work " << totalOvertimeHoursWorked << " hours of overtime every two weeks." << endl;
		//Spacer.
		cout << endl;
	}
	
	return 0;
}
//Main function to handle user input
int main() {
	//Declaring local variables.


	//Legal disclaimer with spacer.
	cout << "THIS APP IN NO WAY ACTS AS TAX OR FINANCIAL ADVICE. THIS PROJECT IS MADE TO PURELY GIVE ESTIMATIONS TO BETTER PLAN" << endl;
	cout << "FINANCIALLY." << endl;

	//Calling payFrequency function to handle cycle determination.
	payFrequency();

	//Calling stateSelection to handle state determination for calculations.
	stateSelection();

	//Asking for user input for wage.
	cout << "\nPlease enter your hourly wage: ";
	cin >> hourlyWage;
	/* TO DO::
		- add functionality so that user can type Yes, YES, Y, No, NO, or N for user experience.
	*/
	//While loop to handle errors in accuracy for wage entry.
	while (!isWageValid) {
		cout << "You entered: " << hourlyWage << ". Is this correct (yes or no)? " << " ";
		string wageAnswer;
		cin >> wageAnswer;

		if (wageAnswer == "yes") {
			isWageValid = true;
		}
		else if (wageAnswer == "no") {
			cout << "\nPlease enter your hourly wage: ";
			cin >> hourlyWage;
		}
		else {
			cout << "\nInvalid input. Please enter 'yes' or 'no': " << endl;
			cin >> hourlyWage;
		}
	}
	//Asking for useer input for hours.
	cout << "\nPlease enter in your hours worked in one week: ";
	cin >> hoursWorkedWeek;
	//While loop to handle errors in accuracy for hours entry.
	while (!isHoursValid) {
		cout << "You entered: " << hoursWorkedWeek << ". Is this correct (yes or no)? " << " ";
		string hoursAnswer;
		cin >> hoursAnswer;

		if (hoursAnswer == "yes") {
			isHoursValid = true;
		}
		else if (hoursAnswer == "no") {
			cout << "\nPlease enter your hours worked in one week: ";
			cin >> hoursAnswer;
		}
		else {
			cout << "\nInvalid input. Please enter 'yes' or 'no': " << endl;
			cin >> hoursAnswer;
		}
	}

	//If statement to initiate overtime hours.
	if (hoursWorkedWeek > 40) {
		overtimeHours = hoursWorkedWeek - 40;
		cout << "\nYou have " << overtimeHours << " hour(s) in overtime.";
	}
	else {
		overtimeHours = 0;
		cout << "\nYou have " << overtimeHours << " hour(s) in overtime.";
	}
	//Calling calculator functions.
	overtimeCalculator();
	wageCalculator();
	taxCalculator();
	hoursTotals();

	//Spacer.
	cout << endl;

	return 0;
}
