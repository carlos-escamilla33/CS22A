/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#4
*/

#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

// Prototype
double calcPeopleBudget(int numOfPeople);
double calcLandscape(int monthOfYear, char residenceType);
double calcBudgetTotal(double peopleBudget, double landscapeBudget);
double calcCostTotal(double budgetTotal, double ccfsUsed);


//////////////////////////////////////////////////

int main() {
    // Initializing user household variables
    int numOfResidents = 4, monthOfYear = 3;
    char residenceType = 'S';
    double peopleBudget, landscapeBudget, budgetTotal, totalCost, ccfsUsed = 12.0;

    // Input user household info
    // cout << "Enter number of residents in household: ";
    // cin >> numOfResidents;
    // cout << "Enter the type of residence: " << endl;
    // cout << "S - Single-family Residence" << endl;
    // cout << "C- Condo" << endl;
    // cout << "A- Apartment" << endl << ": ";
    // cin >> residenceType;
    // cout << "Enter month as a number (1-12): ";
    // cin >> monthOfYear;
    // cout << "Enter Actual CCF (cubic feet) used: ";
    // cin >> ccfsUsed;

    if (residenceType != tolower(residenceType)) {
        residenceType = tolower(residenceType);
    }
    if (!(residenceType == 'a' || residenceType == 's' || residenceType == 'c')) {
        cout << '"' << residenceType << '"'  << " is not a valid input. Please try again.." << endl;
        exit(0);
    }

    // Calculate budget and total cost
    peopleBudget = calcPeopleBudget(numOfResidents);
    landscapeBudget = calcLandscape(monthOfYear, residenceType);
    budgetTotal = calcBudgetTotal(peopleBudget, landscapeBudget);
    totalCost = calcCostTotal(budgetTotal, ccfsUsed);


    cout << setprecision(2) << fixed;
    cout << "PER PERSON CALC--> " << peopleBudget << endl;
    cout << "LANDSCAPE BUDGET CALC---> " << landscapeBudget << endl;
    cout << "TOTAL BUDGET CALC---->" << budgetTotal << endl;
    cout << "TOTAL COST CALC----> " << totalCost << endl;

    return 0;
}

//////////////////////////////////////////////////

#define GALLONS_PER_PERSON 50.00

double calcPeopleBudget(int numOfPeople) {
    /*Pre: numOfPeople - number of people per household
    Post: people budget
    Purpose: return budget based on number of people
    */
    double peopleBudget;

    peopleBudget = (GALLONS_PER_PERSON * numOfPeople) * (30.00 / 748.00);

    return peopleBudget;
} // calcBudgetPerson

//////////////////////////////////////////////////

double calcLandscape(int month, char typeOfResidence) {
    /*Pre: month - month of the year
      typeOfResidence - single-family/condo/apartment
      Post: landscpre budget
      Purpose: return landscpre budget based on month and type of residence
    */
   double landscapeBudget;

   if (month == 1 || month == 2 || month == 3 || month == 4 ||
   month == 10 || month == 11 || month == 12 && typeOfResidence == 's') {
       landscapeBudget = 2.30;
   } else if (month == 5 || month == 6 || month == 7 || month == 8 || month == 9 && typeOfResidence == 's') {
       landscapeBudget = 4.25;
   } else if (month == 1 || month == 2 || month == 3 || month == 4 || month == 10 ||
    month == 11 || month == 12 && typeOfResidence == 'c') {
       landscapeBudget = 0.75;
   }  else if (month == 5 || month == 6 || month == 7 || month == 8 || month == 9 && typeOfResidence == 'c') {
       landscapeBudget = 1.50;
   } else {
       landscapeBudget = 0.00;
   }

    return landscapeBudget;
} // calcLandscape

//////////////////////////////////////////////////

double calcBudgetTotal(double peopleBudget, double landscapeBudget) {
    /*Pre: peopleBudget - budget based on number of people
      landscapeBudget - landscape based on month and residence type
      Post: budget total
      Purpose: return people budget plus landscape budget
    */
    double budgetTotal;

    budgetTotal = peopleBudget + landscapeBudget;

    return budgetTotal;
} //calcBudgetTotal

//////////////////////////////////////////////////

double calcCostTotal(double budgetTotal, double ccfsUsed) {
      /*Pre: billTotal - waterBudget + landscapeBudget
      ccfsUsed - water volume measured in cubic feet used
      Post: total cost
      Purpose: return cost based on budget and ccfsUsed(CCF) used
    */
    double underBudgetCost = 1.53;
    double overBudgetCost = 5.15;
    double totalCost;

    if (ccfsUsed <= budgetTotal) {
        totalCost = (budgetTotal * underBudgetCost);
    } else {
        totalCost = (budgetTotal * underBudgetCost) + ((ccfsUsed - budgetTotal) * overBudgetCost);
    }

    return totalCost;
}





















