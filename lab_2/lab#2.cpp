/*
  Carlos Rodriguez Escamilla
  Lab#2 Mary's Bikes
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define STATE_TAX_RATE (6.75 / 100)

int main()
{
    // Initializing location and tax variables
    string monthYear;
    double cupertinoAmount;
    double losAltosAmount;
    double sunnyvaleAmount;
    double totalCollected;
    double countySalesTax;
    double stateSalesTax;
    double sales;
    double countyTaxRate = (2.75 / 100);

    // Input month and year
    cout << "Enter the month and year:\t";
    getline(cin, monthYear);

    // Input the total amount per store
    cout << "Enter amount collected for Cupertino store:\t";
    cin >> cupertinoAmount;
    cout << "Enter amount collected for Los Altos store:\t";
    cin >> losAltosAmount;
    cout << "Enter amount collected for Sunnyvale store:\t";
    cin >> sunnyvaleAmount;


    // Total Sales Collected
    totalCollected = cupertinoAmount + losAltosAmount + sunnyvaleAmount;

    // Sales variable calculating total sales
    sales = (totalCollected) / (1.0 + STATE_TAX_RATE + countyTaxRate);

    // County Sales Tax
    countySalesTax = sales * countyTaxRate;
    stateSalesTax = sales * STATE_TAX_RATE;


    cout << monthYear << endl;
    cout << totalCollected << endl;
    cout << sales << endl;
    cout << countySalesTax << endl;
    cout << stateSalesTax << endl;
    cout << countySalesTax + stateSalesTax << endl;

    return 0;
}