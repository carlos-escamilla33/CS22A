// /*
//     Carlos Rodriguez Escamilla
//     Hands On #7 - Reversing elements of an array
// */

#include <iostream>
using namespace std;

// Prototype
void backwards(int [], int);

int main() {
    int arr[] = {2,8,17,3,5,16};
    int i;

    backwards(arr, 6);

    for (i = 0; i < 6; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}

void backwards(int array[], int number) {
    /*Pre: array[] - array of integers
            number - number of elements in the array that have values
    Post: Nothing
    Purpose: Reverse the order of the elements of an array */
    int i; int temp; int j; int numberOfSwaps = number / 2;
    
    for (i = 0; i < numberOfSwaps; i++) {
        temp = array[i];
        array[i] = array[number - 1 - i];
        array[number - 1 - i] = temp;
    }

    return;
}