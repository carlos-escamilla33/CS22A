/*
    Carlos Rodriguez Escamilla
    Crodriguezescamilla3@gmail.com
    Lab #3 - ETS Refresh 2022
*/

#include <iostream>
#include <iomanip>

using namespace std;

#define TAX_RATE (0.09250)

int main () {
    // Initalize variables
    int tables, dellThins, dellAllInOnes, keyboards, mouses;
    double tableTotal, dellThinTotal, dellAllInOneTotal, keyboardTotal, mouseTotal;
    const double tablePrice = 429.88;
    const double dellThinPrice = 616.00;
    const double dellAllInOnePrice = 851.00;
    const double keyboardPrice = 18.30;
    const double mousePrice = 16.45;
    double subTotal, total, tax;

    // Prompt user input
    cout << "How many 24 x 72 inch tables ordered? ";
    cin >> tables;
    cout << "How many Dell thin clients ordered? ";
    cin >> dellThins;
    cout << "How many Dell All-in-One Thin Clients ordered? ";
    cin >> dellAllInOnes;
    cout << "How many Dell Keyboards ordered? ";
    cin >> keyboards;
    cout << "How many Dell mouses ordered? ";
    cin >> mouses;
    cout << endl;

    // Calculate item totals
    tableTotal = tablePrice * tables;
    dellThinTotal = dellThinPrice * dellThins;
    dellAllInOneTotal = dellAllInOnePrice * dellAllInOnes;
    keyboardTotal = keyboardPrice * keyboards;
    mouseTotal = mousePrice * mouses;

    // Calculate total, tax, and subTotal
    subTotal = (tableTotal + dellThinTotal + dellAllInOneTotal + keyboardTotal + mouseTotal);
    tax = (subTotal) * TAX_RATE;
    total = (subTotal) + tax;

    // Output Invoice Description
    cout << setprecision(2) << fixed;
    cout << setw(7) << left << "QTY"<< setw(30) << left << "Description";
    cout << setw(10) << right << "Unit Price" << setw(15) << right << "Total Price" << endl;
    cout << setw(7) << left << tables << setw(30) << left <<  "TABLES 24 X 72 INCH";
    cout << setw(10) << right << tablePrice << setw(15) << right << tableTotal << endl;
    cout << setw(7) << left << dellThins << setw(30) << left <<  "DELL THIN CLIENTS";
    cout << setw(10) << right << dellThinPrice << setw(15) << right << dellThinTotal << endl;
    cout << setw(1) << " " << setw(6) << left <<  dellAllInOnes << setw(30) << left <<  "DELL ALL-IN-ONE THIN CLIENTS";
    cout << setw(10) << right << dellAllInOnePrice << setw(15) << right << dellAllInOneTotal << endl;
    cout << setw(1) << " " << setw(6) << left << keyboards << setw(30) << left <<  "DELL KEYBOARD";
    cout << setw(10) << right << keyboardPrice << setw(15) << right << keyboardTotal << endl;
    cout << setw(2) << " " << setw(5) << left << mouses << setw(30) << left <<  "DELL MOUSE";
    cout << setw(10) << right << mousePrice << setw(15) << right << mouseTotal << endl;

    cout << endl;

    cout << setw(30) << right << "SUBTOTAL" << setw(16) << right << subTotal << endl;
    cout << setw(30) << right << "TAX" << setw(16) << right << tax << endl;
    cout << setw(30) << right << "TOTAL" << setw(16) << right << total << endl;

    cout << endl << endl;

    cout << "Programmed By: Carlos Rodriguez Escamilla" << endl;

    return 0;
}

/*
How many 24 x 72 inch tables ordered? 180
How many Dell thin clients ordered? 180
How many Dell All-in-One Thin Clients ordered? 90
How many Dell Keyboards ordered? 12
How many Dell mouses ordered? 5

QTY    Description                   Unit Price    Total Price
180    TABLES 24 X 72 INCH               429.88       77378.40
180    DELL THIN CLIENTS                 616.00      110880.00
 90    DELL ALL-IN-ONE THIN CLIENTS      851.00       76590.00
 12    DELL KEYBOARD                      18.30         219.60
  5    DELL MOUSE                         16.45          82.25

                      SUBTOTAL       265150.25
                           TAX        24526.40
                         TOTAL       289676.65


Programmed By: Carlos Rodriguez Escamilla
*/