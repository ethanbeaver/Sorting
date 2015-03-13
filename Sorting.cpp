#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

void readFile(char myArray[])
{
    ifstream file ("marbles.txt");
    if(file.is_open())
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

    char myArray[2000];
    readFile(myArray);
    int i, j, n, t;

    clock_t t1, t2;
    // Input and initializations occur here before the clock starts.
    t1 = clock();
    for(long int q=1; q <= 1000000; q++) // Loop only if using clock()
    {
        i = j = 0;
        n = 1999;
        while (j <= n)
        {
            if (myArray[j] == 'R')
            {
                t = myArray[i];
                myArray[i] = myArray[j];
                myArray[j] = t;
                i++;
                j++;
            }
            else if (myArray[j] == 'B')
                {
                    t = myArray[j];
                    myArray[j] = myArray[n];
                    myArray[n] = t;
                    n--;
                }
                else if (myArray[j] == 'W')
                    {
                        j++;
                    }
        }
    }
    t2 = clock();
    // Output for verification occurs here after the clock stops.
    cout << myArray;
    cout<< "Time difference is " << (t2-t1)/CLK_TCK << " microseconds";
    return 0;
}
