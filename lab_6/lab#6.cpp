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
string calcCompositeIdxs(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous);

int main()
{
    // Declare variable
    string state, line;
    double groceries, house, utilities, transportation, health, miscellaneous;
    ifstream fileIn;
    char ch='\n';

    fileIn.open("Lab6_StateCOL.txt");

    // If could not open file then send error message
    if (!fileIn.is_open())
    {
        cout << "Could not open file..." << endl;
        exit(100);
    }
    // Reading file while it is not empty
    while (!fileIn.eof()) {
        // Read line of the file
        getline(fileIn, state);
        // If the line of the file has a length enter if statement
        if (state.length()) {
            fileIn >> groceries >> house >> utilities >> transportation >> health >> miscellaneous;
            fileIn.ignore(100,ch); 
            cout << setprecision(1) << fixed;
            cout << endl;
            cout << "State Name: " << state << endl;
            cout << groceries << " " << house << " " << utilities << " " << transportation << " " << health << " " << miscellaneous << endl;
            // calcCompositeIdxs(groceries, house, utilities, transportation, health, miscellaneous);
        }
    }

    // Closing file
    fileIn.close();

    return 0;
}

string calcCompositeIdxs(double groceries, double housing, double utilities, double transportation, double health, double miscellaneous)
{
    /*Pre:fileLineInfo - line of the file
    Post: nothing
    Purpose: return the calculatedhousing of each state;

    */
    string calculatedStateIdxs = "idfdsaf";

    // for (int i = 0; i <housing.length(); i++)
    // {
        // cout << groceries << housing << utilities << transportation << health << miscellaneous << endl;
    // }

    return calculatedStateIdxs;
}