/*
    Carlos Rodriguez Escamilla
    Lab #7 - Universities
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int inputUniversityData(string[], string[], string[], int[], int[], double[], double[], ifstream &);
void outputUniversityData(string[], string[], string[], int[], int[], double[], double[], int, ofstream &);
double averageTuition(int[], int);

int main() {
    // Initialize school info variables
    int arrSize = 1000, dataLength;
    string universities[arrSize], states[arrSize], cities[arrSize];
    int yrlyTuition[arrSize], enrollments[arrSize];
    double avgFreshmanRetention[arrSize], gradsInSixYrs[arrSize];
    double tuitionAvg;

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

    // Calculate Tuition Average
    tuitionAvg = averageTuition(yrlyTuition, dataLength);

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
        // Skips next 100 input characters, until new line is read
        fileIn >> states[idx];
        getline(fileIn, cities[idx]);
        fileIn >> yrlyTuition[idx] >> enrollments[idx];
        fileIn >> placeHolder;
        fileIn >> avgFreshmanRetention[idx] >> gradsInSixYrs[idx];
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
      Purpose: ouput and format unversity data
  */

    // Format headers of output file
    fileOut << setprecision(2) << fixed;
    fileOut << setw(38) << left << "University" << setw(6) << right << "State" <<
     setw(12) << right << "Tuition" << setw(16) << right <<"Enrollment" <<
     setw(20) << right << "%Fresh Succeed" << setw(26) << right << "%Graduate in six years" << endl << endl;
    
    // Iterate through university data
    for (int i = 0; i < dataLength; i++) {
        fileOut << universities[i];
        fileOut <<  setw(40) << ' ' << setw(5) << left << states[i] << setw(10) << right << yrlyTutition[i]<< setw(14) << right << enrollments[i] * 100 <<
         setw(18) << right << avgFreshmanRetention[i] * 100 << '%' << setw(18) << right << gradsInSixYrs[i] * 100 << '%' << endl;
    }

    return;
} // outputUniversityData

/////////////////////////////////////////////////////////////////////////

double averageTuition(int tuition[], int size) {
      /*
      Pre: yrlyTutition - reference to yrlyTuition array
      size - length of data
      Post: average of total tuition
      Purpose: return the average tuition
  */

    // Initialize variables
    double totalTuition = 0;
    double avgTuition;

    // Iterate through data
    for (int i = 0; i < size; i++) {
        // sum up total tuition
        totalTuition+=tuition[i];
    }

    // Calculate average tuition
    avgTuition = totalTuition / size;

    // Return average tuition calculation
    return avgTuition;
}