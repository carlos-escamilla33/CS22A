/*
  Carlos Rodriguez Escamilla
  Lab#2 Mary's Bikes
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Initializing variables
    string monthYear;
    double cupertinoAmount;
    double losAltosAmount;
    double sunnyvaleAmount;
    double totalCollected;
    double countySalesTax;
    double sales;

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

    // Sales variable calculating total sales
    sales = (cupertinoAmount + losAltosAmount + sunnyvaleAmount) / (1.0 + (7.25 / 100) + (1.75 / 100));
    // Total Sales Collected
    totalCollected = cupertinoAmount + losAltosAmount + sunnyvaleAmount;
    // County Sales Tax
    countySalesTax = (cupertinoAmount * (1.75 / 100)) + (losAltosAmount * (1.75 / 100)) + (sunnyvaleAmount * (1.75 / 100));

    cout << monthYear << endl;
    cout << totalCollected << endl;
    cout << sales << endl;

    return 0;
}