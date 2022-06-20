/*
    Carlos Rodriguez Escamilla
    Lab #7 - Universities
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cctype>
using namespace std;

int inputUniversityData(string[], string[], string[], int[], int[], double[], double[], ifstream &);
void outputUniversityData(string[], string[], string[], int[], int[], double[], double[], int, ofstream &);
double averageTuition(int[], int);
void maxTuition(int[], string[], int);
void collegesByState(string[], string[], string[], int[], int[], double[], double[], int, ofstream &);
string lowestUniTuition(string[], int[], int);

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
        cout << "Error reading input file..." << endl;
        exit(1);
    }

    if (!fileOut.is_open()) {
        cout << "Error reading output file..." << endl;
        exit(1);
    }

    // Get univeristy data
    dataLength = inputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, fileIn);

    // Output
    outputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength, fileOut);

    // Calculate Tuition Average
    tuitionAvg = averageTuition(yrlyTuition, dataLength);

    // Ouput the average tuition for all universities
    cout << setprecision(2) << fixed;
    cout << "Average University Tuition: " << '$' << tuitionAvg << endl << endl;

    // Find user schools they can afford
    // maxTuition(yrlyTuition, universities, dataLength);

    // Write colleges found by state to fileOut
    // collegesByState(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength, fileOut);



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
        fileIn >> yrlyTuition[idx] >> enrollments[idx];
        fileIn >> placeHolder;
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
      fileOut - reference to fileOut
      Post: nothing
      Purpose: write and format unversity data to fileOut
  */

    // Format headers of output file
    fileOut << setprecision(2) << fixed;
    fileOut << setw(38) << left << "University" << setw(6) << right << "State" << setw(12) << right << "Tuition" << setw(16) <<
     right << "Enrollment" << setw(20) << right << "%Fresh Succeed" << setw(26) << right << "%Graduate in six years" << endl
            << endl;

    // Iterate through university data
    for (int i = 0; i < dataLength; i++) {
        fileOut << universities[i];
        fileOut << setw(40) << ' ' << setw(5) << left << states[i] << setw(10) << right << yrlyTutition[i] << setw(14) <<
         right << enrollments[i] * 100 << setw(18) << right << avgFreshmanRetention[i] * 100 << '%' << setw(18) <<
          right << gradsInSixYrs[i] * 100 << '%' << endl;
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
        totalTuition += tuition[i];
    }

    // Calculate average tuition
    avgTuition = totalTuition / size;

    // Return average tuition calculation
    return avgTuition;
} // averageTuition

/////////////////////////////////////////////////////////////////////////

void maxTuition(int tuition[], string universities[], int size) {
    /*
      Pre: yrlyTutition - reference to yrlyTuition array
      size - length of data
      Post: nothing
      Purpose: output schools that match or are less than user entered tuition
  */

    // Initialize variables
    int userTutition;

    // Prompt user to input preferred tuition
    cout << "Enter preferred yearly tuition cost: ";
    cin >> userTutition;

    // Iterate through schools
    cout << "These are the schools that are in your budget..." << endl << endl;
    for (int i = 0; i < size; i++) {
        // if the school tuition is less than or equal to user input output university name
        if (tuition[i] <= userTutition) {
            cout << universities[i] << endl;
        }
    }

    cout << endl;

    return;
} // maxTuition

/////////////////////////////////////////////////////////////////////////

void collegesByState(string universities[], string states[], string cities[], int yrlyTutition[],
                    int enrollments[], double avgFreshmanRetention[], double gradsInSixYrs[], int size, ofstream &fileOut) {
     /*
      Pre: universities - reference to universities array
      state - reference to states array
      cities - reference to cities array
      yrlyTutition - reference to yrlyTuition array
      enrollments - reference to enrollment array
      avgFreshmanRetention - reference to avgFreshmanRetention
      gradsInSixYrs - reference to gradsInSixYrs
      fileOut - reference to fileOut
      Post: nothing
      Purpose: output all information of colleges within user selected state
  */                    
    
    // Initialize variables
    string userState;
    string foundState;
    string capState = "";

    // Prompt user to enter state abbreviation
    cout << "Enter the two letter abbreviation of the state you want to attend school in: ";
    cin >> userState;

    // Capitalize user input
    for (int j = 0; j < 2; j++) {
        capState+=toupper(userState[j]);
    }

    // Seperate user school information from school data info
    fileOut << "-------------------------------------------------------------------------" <<
    "---------------------------------------------" << endl << endl;
    fileOut << "Search results for the state of " << capState << "....." << endl << endl;

    // Iterate through states
    for (int i = 0; i < size; i++) {
        // Check if user state is in the states array
        if (capState == states[i]) {
            // if found then assign the state to variable found state
            foundState = states[i];
            fileOut << universities[i];
            fileOut << setw(40) << ' ' << setw(5) << left << states[i] << setw(10) << right << yrlyTutition[i] << setw(14) <<
            right << enrollments[i] * 100 << setw(18) << right << avgFreshmanRetention[i] * 100 << '%' << setw(18) <<
            right << gradsInSixYrs[i] * 100 << '%' << endl;
        }
    }
    
    cout << endl;

    // If there is no state found tell user there is no match
    if (foundState.length() == 0) {
        fileOut << "No colleges in " << userState << " state in list." << endl;
    }

    return;
} // collegesByState

/////////////////////////////////////////////////////////////////////////

string lowestUniTuition(string states[], int tuition[], int size) {
    /*
      Pre: universities - reference to universities array
      tuition - reference to yrlyTuition array
        size - length of data
      Post: nothing
      Purpose: return the lowest university tuition
  */ 

    // Initializing variables
    string universitySubscript;
    int lowestTuition = tuition[0];


    // Iterate over tuition array
    for (int i = 0; i < size; i++) {
        if (tuition[i] < lowestTuition) {
            lowestTuition = tuition[i];
            
        }
    }

    return universitySubscript;

}

