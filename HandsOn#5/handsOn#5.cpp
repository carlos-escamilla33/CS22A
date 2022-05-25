/*
    Carlos Rodriguez Escamilla
    Hands-On #5 - Counting Prime Numbers
*/

#include <iostream>
using namespace std;

int main() {
    // Initialized variables
    int primeNumberCount = 0, factorCount = 0, firstNumber, secondNumber;

    // User number range input
    cout << "Enter first number: ";
    cin >> firstNumber;
    cout << "Enter second number: ";
    cin >> secondNumber;

    // For loop through the range given by the user
    for(int i = firstNumber; i <= secondNumber; i++) {
        // For loop starting with 1 to the range of secondNumber
        for(int j = 1; j <= secondNumber; j++) {
            // If first loop number(i) divisible by second loop number(j), update factorCount by 1
            if (i % j == 0) {
                factorCount++;
            }
        }
        // If only two factors update primeNumberCount by 1
        if(factorCount == 2) {
            primeNumberCount++;
        }
        // Reset factorCount for next iteration
        factorCount = 0;
    }

    cout << "There are " << primeNumberCount << " prime numbers in this range." << endl << endl;
    cout << "Programmed By Carlos Rodriguez Escamilla" << endl;

    return 0;
}

/*
    Enter first number: 50
    Enter second number: 100
    There are 10 prime numbers in this range.

    Programmed By Carlos Rodriguez Escamilla
*/