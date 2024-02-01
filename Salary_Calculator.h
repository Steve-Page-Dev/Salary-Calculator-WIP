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
double overtimeTotalBiweekly;
double overtimeTotalMonth;
double overtimeTotalAnnual;

//Defining variables for wageCalculator function.
//Defining variables for for standard and overtime wage calculations.
double hourlyWage;
double biweeklyWage;
double biweeklyWageOT;

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

//Defining boolean to check if the state selection is correct.
bool isCorrectState = false;

//Defining variables for tax calculator function.
double incomeTax;
double stateTax;
double socialSecurityTax;
double medicareTax;

//Defining boolean to check if the wage entry is valid.
bool isWageValid;

//Defining boolean to check if hours entered are valid.
bool isHoursValid;

//Defining variables for hoursTotals function.
double totalHoursWorked;
double totalHoursWorkedBiWeekly;
double totalOvertimeHoursWorked;
