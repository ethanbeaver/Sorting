#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

/*void marble_sort(string myArray[]);
{

}*/

void readFile(string myArray[])
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

    string myArray[2000];
    readFile(myArray);

    /*for(int j = 0; j<2000 ; j++)
    cout << myArray[j];*/

    clock_t t1, t2;
    // Input and initializations occur here before the clock starts.
    t1 = clock();
    for(long int i=1; i <= 1000000; i++) // Loopp only if using clock()
    {
        marble_sort(myArray)
    }
    t2 = clock();
    // Output for verification occurs here after the clock stops.
    cout<< "Time difference is " << (t2-t1)/CLK_TCK << " microseconds";
    return 0;
}
