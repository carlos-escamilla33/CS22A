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
void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double &propertyTaxes, double &monthlyPymt, int yrsOfLoan, double salesPrice, double dwnPercentage, double interestRate);
void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double salesPrice, double dwnPercentage, int yrsOfLoan, double rateOfInterest);
void output(double salesPrice, double mortagePymt, double dwnPymt, double amtLoan, double interestRate, double yrsLoan, double propertyTaxes, double monthlyPymt);

// Preprocessor statements
#define TAX_RATE 0.0125
#define COST_OF_INSURANCE 550.00
#define COST_OF_ULTILITIES 300.00

int main() {
    // Initializing variables
    const double downPymtPercentage = 0.20;
    double sellingPrice, rateOfInterest, amountOfLoan, mortagePymt, downPayment, propertyTaxes, monthlyPymt;
    int numYearsLoan;

    // Call user info function for home information
    userInfo(sellingPrice, rateOfInterest, numYearsLoan);

    // Calc Montly expenses
    calcMonthlyCosts(downPayment, amountOfLoan, mortagePymt, propertyTaxes, monthlyPymt, numYearsLoan, sellingPrice, downPymtPercentage, rateOfInterest);

    // Output home info

    output(sellingPrice, mortagePymt, downPayment, amountOfLoan, rateOfInterest, numYearsLoan, propertyTaxes, monthlyPymt);

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
    cout << "MONTHLY COST OF HOUSE" << endl << endl;
    cout << "SELLING PRICE: $";
    cin >> salePrice;
    cout << "INTEREST RATE: ";
    cin >> interestRate;
    cout << "DURATION OF LOAN(YEARS): ";
    cin >> yearsOfLoan;

    return;
} // userInfo

void calcMonthlyCosts(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double &propertyTaxes, double &monthlyPymt, int yrsOfLoan, double salesPrice, double dwnPercentage, double rateOfInterest) {
    /*Pre:
   dwnPymt - reference to downPayment
   amtOfLoan - reference to amountOfLoan
   mortagePymt - reference to mortagePymt
   propertyTaxes - reference to propertyTaxes
   monthlyPymt - reference to montlyPymt
   yrsOfLoan - total number of years left to pay off home loan
   salesPrice - total cost of home
   dwnPercentage - percent paid based off the value of the home
   rateOfInterest - reference to rateOfInterest
   Post: nothing
   Purpose: Calculate monthly costs
  */

    // Convert rate of interest to decimal
    rateOfInterest = rateOfInterest / 100;

    // Calaculate down payment, amount of loan, and mortage payment
    calcDownLoanMortage(dwnPymt, amtOfLoan, mortagePymt, salesPrice, dwnPercentage, yrsOfLoan, rateOfInterest);

    // Calculate property taxes
    propertyTaxes = (amtOfLoan * TAX_RATE) / 30;

    monthlyPymt = mortagePymt + COST_OF_ULTILITIES + propertyTaxes + (COST_OF_INSURANCE / 12);

    return;

} // calcMontlyCosts

void calcDownLoanMortage(double &dwnPymt, double &amtOfLoan, double &mortagePymt, double salesPrice, double dwnPercentage, int yrsOfLoan, double rateOfInterest) {
    /*Pre:
    dwnPymt - reference to downPayment
    amtOfLoan - reference to amountOfLoan
    mortagePymt - reference to mortagePymt
    salesPrice - total cost of home
    dwnPercentage - percent paid based off the value of the home
    yrsOfLoan - total number of years left to pay off home loan
    rateOfInterest - percentage of interest on home annually
    Post: nothing
    Purpose: Calculate down payment, amount of loan, mortage payment
   */

    // Calculate down payment on home
    dwnPymt = (salesPrice * dwnPercentage);

    // Calculate amouont of loan after down payment
    amtOfLoan = (salesPrice - dwnPymt);

    // Calculate mortage payment monthly
    mortagePymt = (amtOfLoan * (rateOfInterest / 12) * pow(1 + (rateOfInterest / 12), (yrsOfLoan * 12))) / (pow((1 + (rateOfInterest / 12)), (yrsOfLoan * 12)) - 1);

    return;

} // calcDownLoanMortage

void output(double salesPrice, double mortagePymt, double dwnPymt, double amtLoan, double interestRate, double yrsLoan, double propertyTaxes, double monthlyPymt) {
    /*Pre: dwnPymt - amount given based off the down payment percentage
    amtLoan - amount of money left to pay after giving down payment
    interestRate -
    yrsLoan - years left to pay off home
    propertyTaxes - tax paid on property owned by an individual or other legal entity
    montlyPymt - total montly cost of home with utilities + property taxes
   Post: nothing
   Purpose: output monthly cost of house and montly payment
   */

    // output
    cout << setprecision(2) << fixed;
    cout << setw(30) << left << "SELLING PRICE" << setw(3) << right << "$" <<  setw(9) << right << salesPrice << endl;
    cout << setw(30) << left << "DOWN PAYMENT" << setw(12) << right << dwnPymt << endl;
    cout << setw(30) << left << "AMOUNT OF LOAN" << setw(12) << right << amtLoan << endl;
    cout << setw(30) << left << "INTEREST RATE" << setw(11) << right << interestRate << "%" << endl;
    cout << setw(30) << left << "TAX RATE" << setw(11) << right << (TAX_RATE * 100) << "%" << endl;
    cout << setw(30) << left << "DURATION OF LOAN (YEARS)" << setw(12) << right << yrsLoan << endl;

    cout << endl;

    cout << "MONTHLY PAYMENT" << endl;
    cout << setw(5) << " " << setw(10) << left <<  "MORTAGE PAYMENT" << setw(22) << right <<  mortagePymt << endl;
    cout << setw(5) << " " << setw(10) << left << "UTILITIES" << setw(27) << right << COST_OF_ULTILITIES << endl;
    cout << setw(5) << " " << setw(10) << left << "PROPERTY TAXES" << setw(23) << right << propertyTaxes<< endl;
    cout << setw(5) << " " << setw(10) << left << "INSURANCE" << setw(27) << right << (COST_OF_INSURANCE / 12) << endl;
    cout << setw(42) << "----------" << endl;
    cout << setw(33) << right << "$" << setw(9) << right << monthlyPymt << endl;

    cout << endl;

    cout << "Programmed By: Carlos Rodriguez Escamilla" << endl;

    return;
} // output

/*
MONTHLY COST OF HOUSE

SELLING PRICE: $600000
INTEREST RATE: 4
DURATION OF LOAN(YEARS): 30
SELLING PRICE                   $600000.00
DOWN PAYMENT                     120000.00
AMOUNT OF LOAN                   480000.00
INTEREST RATE                        4.00%
TAX RATE                             1.25%
DURATION OF LOAN (YEARS)             30.00

MONTHLY PAYMENT
     MORTAGE PAYMENT               2291.59
     UTILITIES                      300.00
     PROPERTY TAXES                 200.00
     INSURANCE                       45.83
                                ----------
                                $  2837.43

Programmed By: Carlos Rodriguez Escamilla
*/