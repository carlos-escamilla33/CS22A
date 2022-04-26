/*
    Carlos Rodriguez Escamilla
    Hands On #2 - Learn to Format
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    // Ultility-type expenses
    double pge = 247.5, xfinity = 186.5, garbage = 83, att = 177.40, water = 141.78;

    double total;

    // Calculate total
    total = pge + xfinity + garbage + att + water;

    // Output expenses
    cout << setprecision(2) << fixed;
    cout << left << setw(30) << "PG&E" << right << setw(6) << pge << endl;
    cout << left << setw(30) <<"TV and Internet" << right << setw(6) << xfinity << endl;
    cout << left << setw(30) << "Waste Management" << right << setw(6) << garbage << endl;
    cout << left << setw(30) << "Cell devices" << right << setw(6) << att << endl;
    cout << left << setw(30) << "Water" << right << setw(6) << water << endl;
    cout << right << setw(36) << "_____________" << endl;
    cout << left << setw(30) << "Total" << total << endl << endl;

    cout << "Programmed By: Carlos Rodriguez Escamilla" << endl;
    
    return 0;
}

/*
PG&E                          247.50
TV and Internet               186.50
Waste Management               83.00
Cell devices                  177.40
Water                         141.78
                       _____________
Total                         836.18

Programmed By: Carlos Rodriguez Escamilla
*/