/*
    Carlos Rodriguez Escamilla
    Lab #6 - Cost of Living
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <iomanip>
#include <cstdio>
using namespace std;

// Protoype
double calcCompositeIdxs(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous);

int main() {
    // Declare variable
    string state, line;
    double groceries, house, utilities, transportation, health, miscellaneous;
    double compositeIdx, lowestIdx = 99, highestIdx = 0;
    string lowestIdxState, highestIdxState;
    ifstream fileIn;
    char ch='\n';

    fileIn.open("Lab6_StateCOL.txt");

    // If could not open file then send error message
    if (!fileIn.is_open()) {
        cout << "Could not open file..." << endl;
        exit(100);
    }
    // Reading file while it is not empty
    while (!fileIn.eof()) {
        // Read line of the file
        getline(fileIn, state);
        // If the line of the file has a length enter if statement
        if (state.length()) {
            // Give value to double variables
            fileIn >> groceries >> house >> utilities >> transportation >> health >> miscellaneous;
            fileIn.ignore(100,ch);
            // cout << setprecision(1) << fixed;
            // cout << endl;
            // cout << "State Name: " << state << endl;
            // cout << groceries << " " << house << " " << utilities << " " << transportation << " " << health << " " << miscellaneous << endl;

            // calculate the composite indexes of each state
            compositeIdx = calcCompositeIdxs(groceries, house, utilities, transportation, health, miscellaneous);

            if (compositeIdx < lowestIdx) {
                lowestIdx = compositeIdx;
                lowestIdxState = state;
            } else if (compositeIdx > highestIdx) {
                highestIdx = compositeIdx;
                highestIdxState = state;
            }
        }
    }

    // Closing file
    fileIn.close();
    cout << endl;
    cout << setprecision(1) << fixed; 
    cout << "LOWEST IDX----> " << lowestIdxState << endl;
    cout << lowestIdx << endl;
    cout << "HIGHEST IDX---> " << highestIdxState << endl;
    cout << highestIdx << endl;

    return 0;
}

double calcCompositeIdxs(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous) {
    /*Pre: groceries -
    housing - 
    utilities - 
    transportation - 
    health - 
    miscellaneous - 
    Post: nothing
    Purpose: return the calculated index of each state
    */
   double calculatedStateIdxs = (0.13 * groceries) + (0.29 * housing) + (0.10 * utilities) +
    (0.11 * transportation) + (0.12 * health) + (0.23 * miscellaneous);
    
    return calculatedStateIdxs;
}