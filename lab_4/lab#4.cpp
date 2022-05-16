/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#4
*/

#include <iostream>
using namespace std;

int main() {
    // Initializing user household variables
    int numOfResidents, monthOfYear;
    char residenceType;

    // Input user household info
    cout << "Enter number of residents in household: ";
    cin >> numOfResidents;
    cout << "Enter month as a number (1-12): ";
    cin >> monthOfYear;
    cout << "Enter the type of residence: " << endl;
    cout << "S - Single-family Residence" << endl;
    cout << "C- Condo" << endl;
    cout << "A- Apartment" << endl;
    cin >> residenceType;

    return 0;
}