#include <iostream>

using namespace std;

int main() {

    // Ultility-type expenses
    double pge = 247.5, xfinity = 186.5, garbage = 83, att = 77.40, water = 141.78;

    double total;

    // Calculate total
    total = pge + xfinity + garbage + att + water;

    // Output expenses
    cout << "PG&E" << pge << endl;
    cout << "TV and Internet" << xfinity << endl;
    cout << "Waste Management" << garbage << endl;
    cout << "Cell devices" << att << endl;
    cout << "Water" << water << endl;
    cout << "_____________" << endl;
    cout << "Total" << total << endl;
    
    return 0;
}