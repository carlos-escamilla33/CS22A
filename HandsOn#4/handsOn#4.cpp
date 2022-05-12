/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Hands-On #4
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Prototype
double calcTuition(double units, double studentFees);
void output(double);

//////////////////////////////////////////////////

int main() {
    // Initalizing student expense and student unit variables
    double schoolUnits, studentFees, tuitionTotal;

    // Input user units and fees
    cout << "Input number of units taken this quarter: ";
    cin >> schoolUnits;
    cout << "Input student fees this quarter: ";
    cin >> studentFees;

    // Calculate tuition
    tuitionTotal = calcTuition(schoolUnits, studentFees);

    // Output student totals
    output(tuitionTotal);

    return 0;
}

//////////////////////////////////////////////////

// Cost tuition per unit
#define UNIT_COST 31.00

double calcTuition(double units, double fees) {
    /* Pre: units - student units taken
    fees - non-unit expenses
    Post: tutitionTotal
    Purpose: compute and return the value of student total tuition
    */

    // Initializing total tuition variable
    double tuitionTotal;

    // Calculating tution with units and fees
    tuitionTotal = (UNIT_COST * units) + fees;

    return tuitionTotal;
} // calcTuition

//////////////////////////////////////////////////

void output(double totalTuition) {
       /*Pre: totalTution - total student tuition
      Post: nothing
      Purpose: output total student tuition
      */

    //Carlos' total tution output
    cout << setprecision(2) << fixed << endl;
    cout << "Total tuition this quarter: $" << totalTuition << endl << endl;
    cout << "Programmed By Carlos Rodriguez Escamilla" << endl;
    cout << "CWID#: 20235135" << endl;

    return;
}

/*
    Input number of units: 9.5
    Input student fees this quarter: 80.00

    Total tuition is: $374.50

    Programmed By Carlos Rodriguez Escamilla
    CWID#: 20235135
*/