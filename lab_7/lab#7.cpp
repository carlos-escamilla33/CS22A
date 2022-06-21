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
int lowestUniTuition(string[], int[], int);
void selectionSort(string[], string[], string[], int[], int[], double[], double[], int);

int main() {
    // Initialize variables
    int arrSize = 1000, dataLength;
    string universities[arrSize], states[arrSize], cities[arrSize];
    int yrlyTuition[arrSize], enrollments[arrSize];
    double avgFreshmanRetention[arrSize], gradsInSixYrs[arrSize];
    double tuitionAvg;
    int lowestTuition;

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

    // Checking fileOut for corrupt/unusable data
    if (!fileOut.is_open()) {
        cout << "Error reading output file..." << endl;
        exit(1);
    }

    // Get univeristy data
    dataLength = inputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, fileIn);

    // Output University data
    outputUniversityData(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength, fileOut);

    // Calculate Tuition Average
    // tuitionAvg = averageTuition(yrlyTuition, dataLength);

    // Ouput the average tuition for all universities
    // cout << setprecision(2) << fixed;
    // cout << "Average University Tuition: " << '$' << tuitionAvg << endl << endl;

    // Find user schools they can afford
    // maxTuition(yrlyTuition, universities, dataLength);

    // Write colleges found by state to fileOut
    // collegesByState(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength, fileOut);

    // Find universities with the lowest tuition
    // lowestTuition = lowestUniTuition(states, yrlyTuition, dataLength);

    // Ouput university/universities with the lowest tuition
    // cout << "University/Universities with the lowest tuition cost......" << endl;
    // cout << setprecision(2) << fixed << endl;
    // for (int i = 0; i < dataLength; i++) {
    //     if (yrlyTuition[i] == lowestTuition) {
    //         cout <<setw(38) << left << universities[i] << setw(8) << left << '$' << yrlyTuition[i] << endl;
    //     }
    // }

    // cout << "----------------------------" << endl << endl;

    // Sorting universities
    selectionSort(universities, states, cities, yrlyTuition, enrollments, avgFreshmanRetention, gradsInSixYrs, dataLength);

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
        if (universities[idx].substr(universities[idx].size()-1) == "\n" || universities[idx].substr(universities[idx].size()-1) == "\r") {
                universities[idx] = universities[idx].substr(0, universities[idx].size()-1);
        }
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
    fileOut << setw(38) << left << "University" << setw(6) << right << "State" << setw(10) << right << "Tuition" <<
        setw(14) << right << "Enrollment" << setw(18) << right << "%Fresh Succeed" << setw(25) << right << "%Graduate in six years" << endl;
    fileOut << setw(38) << left << "----------" << setw(6) << right << "-----" << setw(10) << right << "-------" <<
        setw(14) << right << "----------" << setw(18) << right << "--------------" << setw(25) << right << "----------------------" << endl;

    // Iterate through university data
    for (int i = 0; i < dataLength; i++) {
        fileOut <<setw(40) << left << universities[i];
        fileOut << setw(5) << left << states[i] << setw(8) << right << yrlyTutition[i] << setw(14) << right <<
         enrollments[i] * 100 << setw(14) << right << avgFreshmanRetention[i] * 100 << '%' << setw(18) << right << gradsInSixYrs[i] * 100 << '%' << endl;
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

    // Output description of action
    cout << "These are the schools that cost $" << userTutition << " or less...." << endl << endl;
    // Iterate through schools
    for (int i = 0; i < size; i++) {
        // if the school tuition is less than or equal to user input output university name
        if (tuition[i] <= userTutition) {
            cout << universities[i] << endl;
        }
    }

    // Separating by section
    cout << "----------------------------" << endl << endl;

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
        capState += toupper(userState[j]);
    }

    // Seperate user school information from school data info
    fileOut << "-------------------------------------------------------------------------"
            << "---------------------------------------------" << endl
            << endl;
    fileOut << setw(70) << right << "SEARCH RESULTS FOR SCHOOLS IN THE STATE OF " << capState << "....." << endl
            << endl;

    // Iterate through states
    for (int i = 0; i < size; i++) {
        // Check if user state is in the states array
        if (capState == states[i]) {
            // if found then assign the state to variable found state
            foundState = states[i];
            fileOut << setw(40) << left << universities[i];
            fileOut << setw(5) << left << states[i] << setw(8) << right << yrlyTutition[i] << setw(14) << right <<
                enrollments[i] * 100 << setw(14) << right << avgFreshmanRetention[i] * 100 << '%' << setw(18) << right << gradsInSixYrs[i] * 100 << '%' << endl;
        }
    }

    cout << endl;

    // If there is no state found tell user there is no match
    if (foundState.length() == 0) {
        fileOut << "No colleges in " << userState << " state in list." << endl;
    }

     // Separating by section
    cout << "Refer to output file for results..." << endl;
    cout << "----------------------------" << endl << endl;

    return;
} // collegesByState

/////////////////////////////////////////////////////////////////////////

int lowestUniTuition(string states[], int tuition[], int size) {
    /*
      Pre: states- reference to states array
      tuition - reference to yrlyTuition array
      size - length of data
      Post: nothing
      Purpose: return the lowest university tuition
  */

    // Initializing variables
    int lowestTuition = tuition[0];

    // Iterate over tuition array
    for (int i = 0; i < size; i++) {
        if (tuition[i] < lowestTuition) {
            lowestTuition = tuition[i];
        }
    }

    // Return university subscript
    return lowestTuition;
} // lowestUniTuition

/////////////////////////////////////////////////////////////////////////

void selectionSort(string universities[], string states[], string cities[], int yrlyTutition[],
                     int enrollments[], double avgFreshmanRetention[], double gradsInSixYrs[], int size) {
    /*
        Pre: universities - reference to universities array
        state - reference to states array
        cities - reference to cities array
        yrlyTutition - reference to yrlyTuition array
        enrollments - reference to enrollment array
        avgFreshmanRetention - reference to avgFreshmanRetention
        gradsInSixYrs - reference to gradsInSixYrs
        size - length of data
        Post: nothing
        Purpose: sort gradsInSixYrs array in decending order using selection sort
    */

    // Initializing variables
    double temp;
    int min_value, j, i;

    // Iterate through gradsInSixYrs data
    for (i = 0; i < size - 1; i++) {
        // declare min idx
        min_value = i;
        // iterate through numbers to the right of i
        for (j = i + 1; j < size; j++) {
            // If index j value is greater than min_value index value
            if (gradsInSixYrs[j] > gradsInSixYrs[min_value]) {
                // Assign min_value the index of j
                min_value = j;
            }
        }

        // If the min_value index is not the same we know there was a reassigment
        if (min_value != i) {
            // Swap values
            temp = gradsInSixYrs[min_value];
            gradsInSixYrs[min_value] = gradsInSixYrs[i];
            gradsInSixYrs[i] = temp;
        }

        cout << gradsInSixYrs[i] << " " << endl;
    }
    

    return;
}