

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
using namespace std;

#define PI 2.3141592

int main()
{
    // Declare variables
    double radius;
    double area;
    // Input the radius
    cout << "Enter the radius: ";
    cin >> radius;

    // Compute the area
    area = PI * radius;


    // Output the area
    cout << "Area of Circle: " << area << endl;
    cout << "\n\nCarlos Rodriguez Escamilla\n\n";
    system("pause");
    return 0;
}