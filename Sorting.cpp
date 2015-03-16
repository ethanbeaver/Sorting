#include <ctime>
#include <iostream>
#include <fstream>
/*
    Given an unsorted string of characters R,W,B, representing a collection
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
    by dividing by 1000.
*/
using namespace std;

int main()
{
    char myArray[2000]; // Create array for data from .txt
    ifstream file ("marbles.txt");
    if(file.is_open())
    {
        int i = 0;
        // Place contents of file into array
        while(file.good() && i<2000)
        {
            myArray[i] = file.get();
            i++;
        }
    }
    // Input and initializations occur before the clock starts.
    int i, j, n, t;
    i = j = 0;
    n = 1999;
    clock_t t1, t2;

    t1 = clock(); // Begin timer
    // For accuracy, perform the function a billion times and average for execution time
    for(int k = 1; k <= 1000000000; k++) // Loop only if using clock();
    {
        while (j <= n)
        {
            // If red marble, place at beginning of array
            if (myArray[j] == 'R')
            {
                t = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = t;
                i++;
                j++;
            }
            // If blue marble, place at end of array
            else if (myArray[j] == 'B')
                {
                    t = myArray[j];
                    myArray[j] = myArray[n];
                    myArray[n] = t;
                    n--;
                }
            // Leave white marbles in the middle
            else
                {
                    j++;
                }
        }
    }
    t2 = clock(); // End timer

    // Output for verification occurs after clock stops.
    for(int j = 0; j < 2000 ; j++)
        cout << myArray[j];
    // Take the difference of the two times
    cout << endl << "Time difference is " << (double)(t2-t1)/(double)(CLK_TCK) << " microseconds" << endl;
    return 0;
}
