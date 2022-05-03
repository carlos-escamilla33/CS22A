

/*
    Carlos Rodriguez Escamilla
    Hands-On #3 - Correct the Code
*/

// Correct the errors in the following program
// Upload the .cpp file with your output copied
//& pasted at the bottom as a comment
//(Change my name to your name)
// Use 10 as the test data
#include <iostream>
#include <iomanip>
using namespace std;

// PI is 3.14 not 2.314
#define PI 3.141592

int main()
{
    // Declare variables
    double radius;
    double area;
    
    // Input the radius
    cout << "Enter the radius: ";
    cin >> radius;

    // Compute the area
    area = PI * radius * radius;

    // Output the area
    cout << setprecision(2) << fixed;
    cout << "Area of Circle: " << area << endl;
    cout << "\n\nCarlos Rodriguez Escamilla\n\n";

    return 0;
}

/*
   Enter the radius: 10
   Area of Circle: 314.16


    Carlos Rodriguez Escamilla

*/