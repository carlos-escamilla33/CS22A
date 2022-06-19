/*
    Carlos Rodriguez Escamilla
    Lab #7 - Universities
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;

int inputUniversityData(string[], string[], string[], int[], int[], double[], double[], ifstream &);
void outputUniversityData(string[], string[], string[], int[], int[], double[], double[], int, ofstream &);

int main() {
    // Initialize school info variables
    int arrSize = 1000, dataLength;
    string universities[arrSize], states[arrSize], cities[arrSize];
    int yrlyTuition[arrSize], enrollments[arrSize];
    double avgFreshmanRetention[arrSize], gradsInSixYrs[arrSize];

    // Initialize Reference to file
    ifstream fileIn;
    ofstream fileOut;

    // Open fileIn and fileOut
    fileIn.open("universities.txt");
    fileOut.open("sample.txt");

    // Checking fileIn for corrupt/unusable data
    if (!fileIn.is_open()) {
        cout << "Error reading file..." << endl;
        exit(1);
    }

    // Get univeristy data
    dataLength = inputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, fileIn);

    // Output
    outputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength, fileOut);

    // Close files
    fileIn.close();
    fileOut.close();

    return 0;
}

/////////////////////////////////////////////////////////////////////////

int inputUniversityData(string universities[], string states[], string cities[], int yrlyTuition[],
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
        Purpose: input data from universities into respective arrays
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

    return idx;
} // inputUniversityData

/////////////////////////////////////////////////////////////////////////

void outputUniversityData(string universities[], string states[], string cities[], int yrlyTutition[],
                          int enrollments[], double avgFreshmanRetention[], double gradsInSixYrs[], int dataLength, ofstream &fileOut) {
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
      Purpose: ouput unversity data from arrays
  */

    // Iterate through university data
    fileOut << setprecision(2) << fixed;
    fileOut << setw(45) << left << "University" << setw(30) << " " << setw(10) << left << "State" << endl;
    fileOut << endl;
    for (int i = 0; i < dataLength; i++) {
        fileOut << setw(45) << left << universities[i] << endl;
    }

    return;
}