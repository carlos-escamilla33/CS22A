/*
    Carlos Rodriguez Escamilla
    Lab #6 - Cost of Living
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

// Protoype
double calcCompositeIdx(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous);
void signature();

int main() {
    // Initialize variable
    double groceries, house, utilities, transportation, health, miscellaneous;
    double compositeIdx, lowestIdx = 99, highestIdx = 0;
    string lowestIdxState, highestIdxState, state;

    // Initialize References to file
    ifstream fileIn;
    ofstream fileOut;

    // Open file
    fileIn.open("Lab6_StateCOL.txt");
    fileOut.open("tester.txt");

    // If could not open file then send error message
    if (!fileIn.is_open()) {
        cout << "Could not open file..." << endl;
        exit(100);
    }


    cout << setw(10) << left << "State" << setw(21) << right << "Composite Index" << endl;
    cout << "-------" << "\t\t" << "---------------" << endl;
    while (!fileIn.eof()) {
        // Read line of the file
        getline(fileIn, state);
        // If the line of the file has a length enter if statement
        if (state.length()) {
            // Read values into variables
            fileIn >> groceries >> house >> utilities >> transportation >> health >> miscellaneous;
            fileIn.ignore(100,'\n');
            cout << setprecision(1) << fixed;

            // calculate the composite indexes of each state
            compositeIdx = calcCompositeIdx(groceries, house, utilities, transportation, health, miscellaneous);

            // Ouput state and composite index
            fileOut << state << endl;
            fileOut << "\t" << compositeIdx << endl;
            // fileOut << setw(20) << left << state  << setw(20) << right << compositeIdx << endl;
            cout << state << "\t\t\t" << setw(5) << right << compositeIdx << endl;

            if (compositeIdx < lowestIdx) { // If the current composite index is less than the last lowestIdx then reassign lowestIdx and lowestIdx state
                lowestIdx = compositeIdx;
                lowestIdxState = state;
            } else if (compositeIdx > highestIdx) { // If the current composite index is less than the last highestIdx then reassign highestIdx and highesttIdx state
                highestIdx = compositeIdx;
                highestIdxState = state;
            }
        }
    }

    // Closing fileIn
    fileIn.close();
    
    // Writing to fileOut
    fileOut << setprecision(1) << fixed;
    fileOut << endl;
    fileOut << "Min Idx: " << lowestIdxState << "\t" << setw(5) << right << lowestIdx << endl;
    fileOut << "Max Idx: " << highestIdxState << "\t" << setw(5) << right <<  highestIdx << endl;

    // Ouput Min and Max Composite Indexes
    cout << setprecision(1) << fixed;
    cout << endl;
    cout << "Min Idx: " << lowestIdxState << "\t\t\t" << setw(5) << right << lowestIdx << endl;
    cout << "Max Idx: " << highestIdxState << "\t\t\t" << setw(5) << right <<  highestIdx << endl;

    signature();

    // Closing fileOut
    fileOut.close();

    return 0;
}

double calcCompositeIdx(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous) {
    /*Pre: groceries - items of food from a grocery store
    housing - homeowner's monthly mortgage principal and interest payments plus any other monthly expenses 
    utilities - the cost incurred by using utilities such as electricity, water, waste disposal, heating, and sewage
    transportation - transport expenses when traveling from one place to another
    health - any costs incurred in the prevention or treatment of injury or disease
    miscellaneous - random expenses
    Post: calculate composite index
    Purpose: return the calculated index of a state
    */
   
   // Initialize the total calculated state index
   double calculatedStateIdx;

    // Calcuated state index
    calculatedStateIdx = (0.15 * groceries) + (0.29 * housing) + (0.10 * utilities) +
        (0.11 * transportation) + (0.12 * health) + (0.23 * miscellaneous);
    
    return calculatedStateIdx;
} // calcCompositeIdx

void signature() {
    /*Pre: nothing
   Post: nothing
   Purpose: output signature
   */

    cout << endl;
    cout << "Programmed By: Carlos Rodriguez Escamilla" << endl;

    return;
} // signature

/*
    State           Composite Index
    -------         ---------------
    Mississippi              85.0
    Hawaii                  187.0
    Nebraska                 94.0
    Tennessee                89.5
    West Virginia            88.8
    Indiana                  91.0
    California              148.4
    New Mexico               91.1
    South Carolina           94.2
    Maryland                120.4
    Arkansas                 90.2
    Minnesota                98.9
    Louisiana                92.8
    South Dakota             96.5
    Nevada                  104.7
    Massachusetts           133.5
    Maine                   111.8
    District of Columbia    152.8
    Alabama                  88.0
    Utah                    100.8
    Rhode Island            114.7
    Vermont                 114.9
    Kansas                   87.9
    Wisconsin                96.5
    Connecticut             119.2
    Delaware                106.2
    New Jersey              117.8
    Idaho                    97.1
    North Carolina           96.8
    Georgia                  89.4
    Pennsylvania            100.3
    Colorado                105.3
    Montana                 100.6
    Wyoming                  92.7
    Missouri                 91.3
    Washington              113.7
    Alaska                  129.0
    Iowa                     90.5
    Kentucky                 92.1
    New Hampshire           111.6
    New York                144.0
    Oregon                  128.4
    Arizona                 106.6
    Michigan                 91.4
    Illinois                 90.7
    Texas                    92.3
    Ohio                     92.4
    Florida                 101.5
    North Dakota             99.2
    Oklahoma                 88.4
    Virginia                 98.1

    Min Idx: Mississippi     85.0
    Max Idx: Hawaii         187.0

    Programmed By: Carlos Rodriguez Escamilla
*/