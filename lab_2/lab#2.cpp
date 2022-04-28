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
    // Initializing variable that holds month and year
    string monthYear;
    // Initializing amount of money collected and tax per store
    double cupertinoAmount, losAltosAmount, sunnyvaleAmount;
    double totalCollected, countySalesTax, stateSalesTax, sales;
    const double countyTaxRate = (2.75 / 100);

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
    cout << endl;

    // Total Sales Collected
    totalCollected = cupertinoAmount + losAltosAmount + sunnyvaleAmount;

    // Sales variable calculating total sales
    sales = (totalCollected) / (1.0 + STATE_TAX_RATE + countyTaxRate);

    // County Sales Tax
    countySalesTax = sales * countyTaxRate;
    stateSalesTax = sales * STATE_TAX_RATE;

    cout << setprecision(2) << fixed;
    cout << "Month: " << monthYear << endl;
    cout << left << setw(20) << "Total Collected:" << right << setw(25) <<  totalCollected << endl;
    cout << left << setw(20) << "Sales:" << right << setw(25) << sales << endl;
    cout << left << setw(20) << "County Sales Tax:" << right << setw(25) << countySalesTax << endl;
    cout << left << setw(20) << "State Sales Tax:" << right << setw(25) << stateSalesTax << endl;
    cout << left << setw(20) << "Total Sales Tax:" << right << setw(25) << countySalesTax + stateSalesTax << endl << endl;

    cout << "Programmed By: Carlos Rodriguez Escamilla" << endl;
    cout << "-----------------------------------------------" << endl;

    return 0;
}

/*
    Enter the month and year:       April 2022
    Enter amount collected for Cupertino store:     24300
    Enter amount collected for Los Altos store:     34876
    Enter amount collected for Sunnyvale store:     21999

    Month: April 2022
    Total Collected:                     81175.00
    Sales:                               74132.42
    County Sales Tax:                     2038.64
    State Sales Tax:                      5003.94
    Total Sales Tax:                      7042.58

    Programmed By: Carlos Rodriguez Escamilla
    -----------------------------------------------
*/