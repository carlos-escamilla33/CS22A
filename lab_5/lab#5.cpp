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
void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, int yrsOfLoan, double salesPrice, double dwnPercentage, double &interestRate);
void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double salesPrice, double dwnPercentage, int yrsOfLoan);
void output(double mortagePymt, double dwnPymt, double amtLoan, double interestRate, double yrsLoan);

// Preprocessor statements
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_ULTILITIES 300.00

int main() {
    // Initializing variables
    const double downPymtPercentage = 0.20;
    double sellingPrice, rateOfInterest, amountOfLoan, mortagePymt, downPayment;
    int numYearsLoan;

    // Call user info function for home information
    userInfo(sellingPrice, rateOfInterest, numYearsLoan);

    // Calc Montly expenses
    calcMonthlyCosts(downPayment, amountOfLoan, mortagePymt, numYearsLoan, sellingPrice, downPymtPercentage, rateOfInterest);

    // Output home info

    output(mortagePymt, downPayment, amountOfLoan, rateOfInterest, numYearsLoan);

    return 0;
} //

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
} // userInfo

void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, int yrsOfLoan, double salesPrice, double dwnPercentage, double &rateOfInterest) {
    /*Pre:
   dwnPymt - reference to downPayment
   amtOfLoan - reference to amountOfLoan
   mortagePymt - reference to mortagePymt
   yrsOfLoan - total number of years left to pay off home loan
   salesPrice - total cost of home
   dwnPercentage - percent paid based off the value of the home
   Post: nothing
   Purpose: Calculate home expenses, make all neccessary compuations
  */

    // Calaculate down payment, amount of loan, and mortage payment
    calcDownLoanMortage(dwnPymt, amtOfLoan, mortagePymt, salesPrice, dwnPercentage, yrsOfLoan);

    // Calculate interest rate
    rateOfInterest = (TAX_RATE)*30;

    return;

} // calcMontlyCosts

void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double salesPrice, double dwnPercentage, int yrsOfLoan) {
    /*Pre:
    dwnPymt - reference to downPayment
    amtOfLoan - reference to amountOfLoan
    mortagePymt - reference to mortagePymt
    salesPrice - total cost of home
    Post: nothing
    Purpose: Calculate down payment, amount of loan, mortage payment
   */

    // Calculate down payment on home
    dwnPymt = (salesPrice * dwnPercentage);

    // Calculate amouont of loan after down payment
    amtOfLoan = (salesPrice - dwnPymt);

    // Calculate mortage payment monthly
    mortagePymt = (amtOfLoan * (TAX_RATE / 12) * pow(1 + (TAX_RATE / 12), (yrsOfLoan * 12))) / (pow((1 + (TAX_RATE / 12)), (yrsOfLoan * 12)) - 1);

    return;

} // calcDownLoanMortage

void output(double mortagePymt, double dwnPymt, double amtLoan, double interestRate, double yrsLoan) {
    /*Pre: dwnPymt - amount given based off the down payment percentage
    amtLoan - amount of money left to pay after giving down payment
    interestRate -
    yrsLoan - years left to pay off home
   Post: nothing
   Purpose: output monthly cost of house and montly payment
   */

    // output
    cout << setprecision(2) << fixed;

    cout << "MORTAGE PAYMENT: $" << mortagePymt << endl;
    cout << "DOWN PAYMENT: $" << downPymt << endl;
    cout << "AMOUNT OF LOAN: $" << amtOfLoan << endl;
    cout << "INTEREST RATE: " << interestRate << "%" << endl;
    cout << "TAX RATE: " << (TAX_RATE * 100) << "%" << endl;
    cout << "DURATION OF LOAN: " << yrsLoan << endl;

    return;
} // output