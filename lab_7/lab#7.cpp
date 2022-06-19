/*
    Carlos Rodriguez Escamilla
    Lab #7 - Universities
*/

#include <iostream>
#include <fstream>
// #include <string.h>
using namespace std;

void inputUniversityData(string[], string[], string[], int[], int[], double[], double[], ifstream &);

int main() {
    // Initialize school info variables
    int arrSize = 1000;
    string universities[arrSize], states[arrSize], cities[arrSize];
    int yrlyTuition[arrSize], enrollments[arrSize];
    double avgFreshmanRetention[arrSize], gradsInSixYrs[arrSize];

    // Initialize Reference to file
    ifstream fileIn;
    ofstream fileOut;

    // Open fileIn and fileOut
    fileIn.open("universities.txt");
    // fileOut.open("sample")

    // Checking fileIn for corrupt/unusable data
    if (!fileIn.is_open())
    {
        cout << "Error reading file..." << endl;
        exit(1);
    }

    // Get univeristy data
    inputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, fileIn);

    // Close files
    fileIn.close();

    // Output

    return 0;
}

void inputUniversityData(string universities[], string states[], string cities[], int yrlyTuition[],
                         int enrollments[], double avgFreshmanRetention[], double gradsInSixYrs[], ifstream &fileIn) {
    /*
        Pre: universities - reference to universities array
        state - reference to states array
        cities - reference to cities array
        yrlyTutition - reference to yrlyTuition array
        enrollments - reference to enrollment array
        avgFreshmanRetention - reference to avgFreshmanRetention
        gradsInSixYrs - reference to gradsInSixYrs
        fileIn - reference to fileIn
        Post: nothing
        Purpose:
    */
    double placeHolder;
    int idx = 0;

    while (!fileIn.eof()) {
        // Read line of files
        getline(fileIn, universities[idx]);
        fileIn >> states[idx];
        getline(fileIn, cities[idx]);
        fileIn >> yrlyTuition[idx] >> enrollments[idx] >> placeHolder;
        fileIn >> avgFreshmanRetention[idx] >> gradsInSixYrs[idx];

        // Skips next 100 input characters, until new line is read
        fileIn.ignore(100, '\n');

        // Increment the index by 1
        idx++;
    }

    return;
}