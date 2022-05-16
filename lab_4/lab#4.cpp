/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#4
*/

#include <iostream>
using namespace std;

// Prototype
double calcWaterAllotment(int numOfPeople);
double calcLandscape(int monthOfYear, char residenceType);

//////////////////////////////////////////////////

int main() {
    // Initializing user household variables
    int numOfResidents = 4, monthOfYear;
    double waterCalc;
    char residenceType;

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

    // Calculate Info

    waterCalc = calcWaterAllotment(numOfResidents);

    cout << waterCalc << endl;


    return 0;
}

//////////////////////////////////////////////////

double calcWaterAllotment(int numOfPeople) {
      /*Pre: numOfPople - number of people per household
      Post: water allocation for people
      Purpose: output water allocation
      */
     double waterAllocation;

     waterAllocation = (50.00 * numOfPeople) * (30.00 / 748.00);

     return waterAllocation;
} //calcBudget