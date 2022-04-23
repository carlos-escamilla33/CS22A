/*
    Carlos Rodriguez Escamilla
    Lab1B - Paying in Coins
*/

#include <iostream>

using namespace std;

int main() {
    // Initializing amountDue double variable 
    double amountDue;
    // Initializing integer coin variables
    int quarters, dimes, nickles, pennies;

    // Asking user to input amount I owe
    cout << "How much do I owe you?\n";
    cin >> amountDue;
    cout << endl;

    // Computing user input into cents
    amountDue = amountDue / 0.01;

    // Dividing amountDue by appropriate cent amount (repeat for all coins)
    quarters = amountDue / 25;
    // Subtracting from amountDue to reassign it the new amount due (repeat for all coins)
    amountDue = (amountDue - (quarters * 25));
    dimes = amountDue / 10;
    amountDue = (amountDue - (dimes * 10));
    nickles = amountDue / 5;
    amountDue = (amountDue - (nickles * 5));
    pennies = amountDue;

    // Output summary of bill split into cents
    cout << "QUARTER(S): " << quarters << endl;
    cout << "DIME(S): " << dimes << endl;
    cout << "NICKLE(S): " << nickles << endl;
    cout << "PENNIE(S): " << pennies << endl << endl;

    cout << "Programmed by: Carlos Rodriguez Escamilla" << endl;
    return 0;
}

/*
    How much do I owe you?
    15.45

    QUARTER(S): 61
    DIME(S): 2
    NICKLE(S): 0
    PENNIE(S): 0

    Programmed by: Carlos Rodriguez Escamilla
*/