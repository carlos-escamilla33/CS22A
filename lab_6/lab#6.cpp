/*
    Carlos Rodriguez Escamilla
    Lab #6 - Cost of Living
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

int main() {
    // Declare variable
    string word;

    // Initializing pointers to file
    ifstream fileIn;

    fileIn.open("Lab6_StateCOL.txt");
    if(fileIn.fail()) {
        cout << "ERROR IN READING FILE..." << endl;
        exit(100);
    }

    // Loop through words in file
    while (!fileIn.eof()) {
        cout << word << endl;
        getline(fileIn, word);
    }

    // Closing file
    fileIn.close();


    return 0;
}