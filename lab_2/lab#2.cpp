/*
  Carlos Rodriguez Escamilla
  Lab#2 Mary's Bikes
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define STATE_TAX (7.25 / 100)

int main()
{
    // Initializing variables
    string monthYear;
    double cupertinoAmount = 23599.00;
    double losAltosAmount = 4788.00;
    double sunnyvaleAmount = 67123.00;
    double totalCollected;
    double countySalesTax;
    double stateSalesTax;
    double sales;
    double countyTaxRate = (1.75 / 100);

    // Input month and year
    // cout << "Enter the month and year:\t";
    // getline(cin, monthYear);

    // Input the total amount per store
    // cout << "Enter amount collected for Cupertino store:\t";
    // cin >> cupertinoAmount;
    // cout << "Enter amount collected for Los Altos store:\t";
    // cin >> losAltosAmount;
    // cout << "Enter amount collected for Sunnyvale store:\t";
    // cin >> sunnyvaleAmount;

    // Sales variable calculating total sales
    sales = (cupertinoAmount + losAltosAmount + sunnyvaleAmount) / (1.0 + STATE_TAX + (1.75 / 100.0));
    // Total Sales Collected
    totalCollected = cupertinoAmount + losAltosAmount + sunnyvaleAmount;
    // County Sales Tax
    countySalesTax = sales * countyTaxRate;
    stateSalesTax = sales * STATE_TAX;


    cout << monthYear << endl;
    cout << totalCollected << endl;
    cout << sales << endl;
    cout << countySalesTax << endl;
    cout << stateSalesTax << endl;
    cout << countySalesTax + stateSalesTax << endl;

    return 0;
}