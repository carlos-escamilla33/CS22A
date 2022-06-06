/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#5
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Prototype
void userInfo(double &salesPrice, double &interestRate, int &yearsOfLoan);

// Preprocessor statements
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_ULTILITIES 300.00

int main() {
    // Initializing variables
    const double downPymtPercentage = 0.20;
    double sellingPrice, rateOfInterest;
    int numYearsLoan;

    // Call user info function
    userInfo(sellingPrice, rateOfInterest, numYearsLoan);

    return 0;
}

void userInfo(double &salePrice, double &interestRate, int &yearsOfLoan) {
    /*Pre: 
   salePrice - reference to sellingPrice
   interestRate - reference to rateOfInterest
   yearsOfLoan - reference to numYearsLoan
   Post: nothing
   Purpose: Prompt user to input home selling price, interest rate, and years on the loan
   */

    // Prompt user info input
    cout << "MONTHLY COST OF HOUSE" << endl;
    cout << "SELLING PRICE: $";
    cin >> salePrice;
    cout << "DURATION OF LOAN(YEARS): ";
    cin >> yearsOfLoan;

    return;
}