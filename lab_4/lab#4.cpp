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
double calcCostTotal(double budgetTotal, double ccfUsed);
void output(double budgetTotal, double totalCost);

//////////////////////////////////////////////////

int main() {
    // Initializing user household variables
    int numOfResidents, monthOfYear;
    char residenceType;
    double peopleBudget, landscapeBudget, budgetTotal, totalCost, ccfUsed;

    // Input user household info
    cout << "Enter number of residents in household: ";
    cin >> numOfResidents;
    cout << "Enter the type of residence" << endl;
    cout << "S - Single-family Residence" << endl;
    cout << "C- Condo" << endl;
    cout << "A- Apartment" << endl << ": ";
    cin >> residenceType;
    cout << "Enter month as a number (1-12): ";
    cin >> monthOfYear;
    cout << "Enter Actual CCF (cubic feet) used: ";
    cin >> ccfUsed;

    if (residenceType != tolower(residenceType)) {
        residenceType = tolower(residenceType);
    }
    if (!(residenceType == 'a' || residenceType == 's' || residenceType == 'c')) {
        cout << '"' << residenceType << '"' << " is not a valid input. Please try again.." << endl;
        exit(0);
    }

    // Calculate budget and total cost
    peopleBudget = calcPeopleBudget(numOfResidents);
    landscapeBudget = calcLandscape(monthOfYear, residenceType);
    budgetTotal = calcBudgetTotal(peopleBudget, landscapeBudget);
    totalCost = calcCostTotal(budgetTotal, ccfUsed);

    // Output calculations
    output(budgetTotal, totalCost);

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
    double daysInMonth = 30.00;
    double gallonsOfWater = 748.00;
    
    peopleBudget = (GALLONS_PER_PERSON * numOfPeople) * (daysInMonth / gallonsOfWater);

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

    // Calculate landscape based on day of the month and type of residence
    switch(month) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 10:
        case 11:
        case 12:
            if (typeOfResidence == 's') {
                landscapeBudget = 2.30;
            } else if (typeOfResidence == 'c') {
                landscapeBudget = 0.75;
            } else {
                landscapeBudget = 0.00;
            }
        break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            if (typeOfResidence == 's') {
                landscapeBudget = 4.25;
            } else if (typeOfResidence == 'c') {
                landscapeBudget = 1.50;
            } else {
                landscapeBudget = 0.00;
            }
        break;
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
} // calcBudgetTotal

//////////////////////////////////////////////////

double calcCostTotal(double budgetTotal, double ccfUsed) {
    /*Pre: budgetTotal - waterBudget + landscapeBudget
    ccfUsed - water volume measured in cubic feet used
    Post: total cost
    Purpose: return cost based on budget and ccfUsed(CCF) used
  */
    double underBudgetCost = 1.53;
    double overBudgetCost = 5.15;
    double totalCost;

    if (ccfUsed <= budgetTotal) {
        totalCost = (budgetTotal * underBudgetCost);
    }
    else {
        totalCost = (budgetTotal * underBudgetCost) + ((ccfUsed - budgetTotal) * overBudgetCost);
    }

    return totalCost;
}

//////////////////////////////////////////////////

void output(double budgetTotal, double totalCost) {
    /*Pre: budgetTotal - waterBudget + landscapeBudget
    totalCost - cost based on budget and cubic feet(CCF) used
   Post: nothing
   Purpose: output budget total, and total cost
   */
    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "Budget for people and landscape: " << budgetTotal << endl;
    cout << "Total Cost:$ " << totalCost << endl;

    return;
}


/*
    Enter the type of residence
    S - Single-family Residence
    C- Condo
    A- Apartment
    : S
    Enter month as a number (1-12): 3
    Enter Actual CCF (cubic feet) used: 12.0

    Budget for people and landscape: 10.32
    Total Cost:$ 24.44
*/