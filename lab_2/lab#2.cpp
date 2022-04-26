/*
  Carlos Rodriguez Escamilla
  Lab#2 Mary's Bikes
*/

#include <iostream>
#include <string>

using namespace std;

/*Sales tax rate set at 8.75%
  Tip rate set with global preprocessor directive at 20%
  User enters amount of bill
  Compute tax, tip (memory constant), and total
  Output amount of bill, tax, tip, and total in tabular format

*/

int main() {
  // Initializing variables
  string monthYear;
  double cupertinoAmount;
  double losAltosAmount;
  double sunnyvaleAmount;

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
  

  cout << monthYear << endl;

  return 0;
}