/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#4
*/

#include <iostream>
#include <cctype>
using namespace std;

// Prototype
double calcWaterAllotment(int numOfPeople);
double calcLandscape(int monthOfYear, char residenceType);

//////////////////////////////////////////////////

int main() {
    // Initializing user household variables
    int numOfResidents = 4, monthOfYear = 3;
    char residenceType = 'C';
    double waterCalc, landScapeCalc;

    // Input user household info
    // cout << "Enter number of residents in household: ";
    // cin >> numOfResidents;
    // cout << "Enter month as a number (1-12): ";
    // cin >> monthOfYear;
    // cout << "Enter the type of residence: " << endl;
    // cout << "S - Single-family Residence" << endl;
    // cout << "C- Condo" << endl;
    // cout << "A- Apartment" << endl;
    // cin >> residenceType;

    if (residenceType != tolower(residenceType)) {
        residenceType = tolower(residenceType);
    }
    if (!(residenceType == 'a' || residenceType == 'A' || residenceType == 's' || residenceType == 'S' || residenceType == 'c' || residenceType == 'C')) {
        cout << '"'<< residenceType << '"'  << " is not a valid input. Please try again.." << endl;
        exit(0);
    }

    // Calculate Info
    waterCalc = calcWaterAllotment(numOfResidents);
    landScapeCalc = calcLandscape(monthOfYear, residenceType);

    cout << waterCalc << endl;
    cout << landScapeCalc << endl;

    return 0;
}

//////////////////////////////////////////////////

#define GALLONS_PER_PERSON 50.00

double calcWaterAllotment(int numOfPeople) {
    /*Pre: numOfPeople - number of people per household
    Post: water allocation for people
    Purpose: output water allocation
    */
    double waterAllocation;

    waterAllocation = (GALLONS_PER_PERSON * numOfPeople) * (30.00 / 748.00);

    return waterAllocation;
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
}
