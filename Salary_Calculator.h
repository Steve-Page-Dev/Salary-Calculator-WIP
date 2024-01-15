#include <iostream>
#include <string>
#pragma once
using namespace std;

//This header is used to contain the numerous variables used by the calculator for cleaner code and ease of use.

//Defining variables for payFrequency function.
//Defining variable to hold user choice for pay cycle.
int payCycleChoice;

//Defining booleans to handle switch statement checking if payCycleChoice entry is valid and for pa cycle selections.
//Setting initial values to false so switch statement can run and so that choices can be made.
bool isPayCycleValid = false;
bool weeklyPay = false;
bool biweeklyPay = false;

//Defining variables for overtimeCalculator function.
//Defining overtime multiplier variable and variable to hold the number of overtime hours.
double overtimeMultiplier = 1.5;
double overtimeHours;

/*TO DO::
  -Streamline the process using only weeks in year for better accuracy.
*/
//Defining variables for overtime wage calculations for hourly, weekly, monthly, and yearly wages.
double overtimeHourlyWage;
double overtimeTotalWeek;
double overtimeTotalMonth;
double overtimeTotalAnnual;

//Defining variables for wageCalculator function.
/*TO DO::
  -Streamline the process using only weeks in year for better accuracy.
*/
//Defining variable to hold the number of hours worked.
double hoursWorkedWeek;

//Defining wage variables for weekly, monthly, and annual wages.
double weeklyWage;
double monthlyWage;
double annualWage;

//Defining variables for the number of weeks in a month and year.
int weeksInMonth = 4;
int weeksInYear = 52;

//Defining variables to hold totals for wage plus overtime.
double weeklyWageOT;
double monthlyWageOT;
double annualWageOT;

//Defining variables to hold values for true wage calculations.
double trueWageS1;
double trueWageS2;
