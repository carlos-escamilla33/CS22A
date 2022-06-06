/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab#5
*/

#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// Prototype
void userInfo(double &salesPrice, double &interestRate, int &yearsOfLoan);
void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, int yrsOfLoan);
void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt);


// Preprocessor statements
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_ULTILITIES 300.00

int main() {
    // Initializing variables
    const double downPymtPercentage = 0.20;
    double sellingPrice, rateOfInterest, amountOfLoan, mortagePymt;
    double downPayment;
    int numYearsLoan;

    // Call user info function and home calculations function
    userInfo(sellingPrice, rateOfInterest, numYearsLoan);
    calcMonthlyCosts(downPayment, amountOfLoan, mortagePymt, numYearsLoan);

    cout << "MORTAGE PAYMENT: " << mortagePymt << endl;

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

void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, int yrsOfLoan) {
     /*Pre: 
    dwnPymt - reference to downPayment
    amtOfLoan - reference to amountOfLoan
    mortagePymt - reference to mortagePymt
    yrsOfLoan - total number of years left to pay off home loan
    Post: nothing
    Purpose: Calculate home down payment, amount of loan, and mortage payment
   */

//   Calaculate down payment, amount of loan, and mortage payment
  calcDownLoanMortage(dwnPymt, amtOfLoan, mortagePymt);

  

  return;

}


void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt) {
    
}