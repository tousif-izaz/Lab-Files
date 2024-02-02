// <chart.cpp>
// <Izaz> , <Tousif>
// <tizaz>

#include <iostream>
using namespace std;
/*
purpose : function to print that takes in array as input and prints
the pattern on the screen.
*/
// Input Parameters: array, length of array
// Output parameters: None

void printPattern(int arr[], int len, int max)
{
    /*setting a new variable numlines that indicates
     how many lines are left to print */
    int numLines = max;
    for (int i = 0; i < max; i++)
    {
        // current loop prints vertically, the number of lines
        for (int j = 0; j < len; j++)
        {
            // this loop prints horizontally, depending on the condition
            if (arr[j] >= numLines)
            {
                // if the line number is greater than corresponding value of array
                cout << '*';
            }
            else
            {
                // if the number is less than numlines, then print space
                cout << ' ';
            }
        }
        cout << "\n";
        numLines--; // decreasing numlines as we approach lower lines;
    }
}

int find_largest(int arr[], int len)
{
    int max = arr[0]; // setting initial value as max
    /*
    following function finds the max among the outputs,
    so that how many lines to print can be decided.
    */
    for (int i = 0; i < len; i++)
    {
        if (arr[i] >= max) // if current value is greater than max, then set max to current
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    // declare maximum input size of array
    const int MAX = 100;
    int input_array[MAX];
    int value;
    // counter to keep track of length of array
    int count = 0;
    while (cin >> value)
    {
        if (value == 0)
            break;
        input_array[count] = value;
        // counter is increased as we keep adding new element to array
        count++;
    }
    int max = find_largest(input_array, count);
    printPattern(input_array, count, max);
    return 0;
}