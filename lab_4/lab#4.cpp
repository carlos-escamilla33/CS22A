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
double calcWaterAllocation(int numOfPeople);
double calcLandscape(int monthOfYear, char residenceType);
double calcBillTotal(double perPersonCalc, double landscapeBudget);
double calcBudgetTotal(double waterBudget, double cubicFeet);

//////////////////////////////////////////////////

int main() {
    // Initializing user household variables
    int numOfResidents = 4, monthOfYear = 3;
    char residenceType = 'S';
    double waterCalc, landScapeCalc, billCalc, budgetTotalCalc, cubicFeet = 12.0;

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
    // cin >> cubicFeet;

    if (residenceType != tolower(residenceType)) {
        residenceType = tolower(residenceType);
    }
    if (!(residenceType == 'a' || residenceType == 'A' || residenceType == 's' || residenceType == 'S' || residenceType == 'c' || residenceType == 'C')) {
        cout << '"'<< residenceType << '"'  << " is not a valid input. Please try again.." << endl;
        exit(0);
    }

    // Calculate Info
    waterCalc = calcWaterAllocation(numOfResidents);
    landScapeCalc = calcLandscape(monthOfYear, residenceType);
    billCalc = calcBillTotal(waterCalc, landScapeCalc);
    budgetTotalCalc = calcBudgetTotal(waterCalc, cubicFeet);


    cout << setprecision(2) << fixed;
    cout << "WATER BUDGET--> " << waterCalc << endl;
    cout << "LANDSCAPE COST---> " << landScapeCalc << endl;
    cout << "TOTAL BILL CALC----> " << billCalc << endl;
    cout << budgetTotalCalc << endl;

    return 0;
}

//////////////////////////////////////////////////

#define GALLONS_PER_PERSON 50.00

double calcWaterAllocation(int numOfPeople) {
    /*Pre: numOfPeople - number of people per household
    Post: budgetPerPerson
    Purpose: output water allocation
    */
    double waterBudget;

    waterBudget = (GALLONS_PER_PERSON * numOfPeople) * (30.00 / 748.00);

    return waterBudget;
} // calcBudget

//////////////////////////////////////////////////

double calcLandscape(int month, char typeOfResidence) {
    /*Pre: month - month of the year
      typeOfResidence - single family/condo/apartment residence type
      Post: output landscpre cost
      Purpose: output landscpre cost based on month and type of residence
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
} // calcLandScape

//////////////////////////////////////////////////

double calcBillTotal(double waterBudget, double landscapeBudget) {
    /*Pre: waterBudget - water allocation for all people
      landscapeBudget - landscape cost based on month and residence type
      Post: output billTotal
      Purpose: output water allocation plus landscape budget
    */
    double billTotal;

    billTotal = waterBudget + landscapeBudget;

    return billTotal;
} //calcBillTotal

//////////////////////////////////////////////////

double calcBudgetTotal(double waterBudget, double cubicFeet) {
      /*Pre: billTotal - waterBudget + landscapeBudget
      cubicFeet - water volume measured in cubicFeet
      Post: output budget total
      Purpose: output cost based on cubic feet used
    */
    double budgetTotal;

    return 0;
}





















