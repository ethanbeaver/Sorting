/*****************************************************************************
 Program file name: SortingGroup2.cpp 			  OS: Ubuntu/Windows				    Assignment: Final
 Programmer(s): Ethan Beaver,Greg Ringering, Alexander Beckner, Ryker Bolden     Class: CPTR142 		        Date: 3/16/2015
 Compiler: Code::Blocks

 Assistance/references:

 Description: Given an unsorted string of characters R,W,B, representing a collection
    of unsorted marbles, this algorithm sorts the contents such that all of
    the R's are together, then all of the W's, and last all of the B's.

    Sorting is performed by placing any R at the beginning of the array and
    any B at the end of the array, leaving W's in the middle of the array.
    Trackers keep track the pointer that travels through the array, the end
    of the array or beginning of the B's, and the end of the R's.

    The algorithm is performed 1000000000 times in order to accurately
    determine how long the actual algorithm takes through averaging. A timer
    begins after variable declaration and the loading of the array, and ends
    after the sorting has finished. The difference between the timer variables
    determines how many nanoseconds it will take, translated into microseconds
    by dividing by 1000000.

 Inputs: None

 Outputs: The sorted marbles and how long it took.

 Special Comments:

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~

 Assignment Requirements: ___/3.0

 Code Format/Cosmetics: ___/3.0

 Header & Code Comments: ___/2.0

 Output Format/Cosmetics: ___/2.0
 ***Does Not Compile***: ___ (-10.0)
 ***Late Work Deduction***: ___ (-0.5/day)
 Total Grade: ___/10.0

*****************************************************************************/

#include <ctime>
#include <iostream>
#include <fstream>
/*
*/
using namespace std;

inline void readFile(char myArray[])
{
    ifstream file ("marbles.txt"); //Open the marbles file
    if(file.is_open()) // Place contents of file into array
    {
        int i = 0;
        while(file.good() && i<2000)
        {
            myArray[i] = file.get();
            i++;
        }
    }
}

int main()
{
    // Input and initializations occur here before the clock starts.
    int i, j, n, t;
    char myArray[2000]; // Create array for data from .txt
    readFile(myArray);
    char myArrayDefault[2000]; // Create array for data from .txt to be used to reset myArray at the end of each time running the function
    readFile(myArrayDefault);
    clock_t t1, t2;


    t1 = clock(); // Begin timer
    // For accuracy, perform the function a million times and average for execution time
    for(long int q=1; q <= 1000000; q++) // Loop only if using clock()
    {
        i = j = 0;
        n = 1999;
        for(int z=0; z<2000;z++) //Reset myArray to unsorted marbles after each iteration of running the function.
        {
            myArray[z]=myArrayDefault[z];
        }

        while (j <= n)
        {
            if (myArray[j] == 'R') // If red marble, place at beginning of array
            {
                t = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = t;
                i++;
                j++;
            }
            else if (myArray[j] == 'B') // If blue marble, place at end of array
            {
                t = myArray[j];
                myArray[j] = myArray[n];
                myArray[n] = t;
                n--;
            }
            else if (myArray[j] == 'W') // Leave white marbles in the middle
            {
                j++;
            }
        }
    }
    t2 = clock(); //End timer


    // Output for verification occurs here after the clock stops.
    for(int x=0; x<2000;x++)
        {
            cout << myArray[x];
        }
    // Take the difference of the two times
    cout<< "Time difference is " << (t2-t1)/CLK_TCK << " microseconds" << endl;
    return 0;
}
