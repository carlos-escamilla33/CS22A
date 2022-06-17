/*
    Carlos Rodriguez Escamilla
    Lab #7 - Universities
*/

#include <iostream>
#include <fstream>
// #include <string.h>
using namespace std;

void inputUniversityInfo();

int main() {
    // Initialize school info variables
    string universities[1000], state[1000], city[1000];
    int yrlyTutition[1000], enrollment[1000];
    double avgFreshmanRetention[1000], double gradsInSixYrs[1000];

    // Initialize Reference to file
    ifstream fileIn;
    ofstream fileOut;

    // Open fileIn and fileOut
    fileIn.open("/universities.txt");
    // fileOut.open("sample")

    // Checking fileIn for corrupt/unusable data
    if (!fileIn.is_open()) {
        cout << "Error reading file..." << endl;
        exit(1);
    }

    // Run loop till end of fileIn


    // Output


    return 0;
}