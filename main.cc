#include <iostream>
#include <string>
#include <sys/time.h> // time function
#include <limits.h>
#include "interface.h" // create, input,  print arrays 
#include "makeArray.h" // for generated array
#include "sortfunctions.h" // sorting functions
using namespace std;

struct timeval before, after;
double timing, total;

//string name[4] = { "insertionsort", "shellsort","quicksort","dualpivot quicksort" };

int main()
{
    int size = 500;
    int* a = NULL;
    a = new int[size];
    //makeUserInputArray(a, size);
    //orderedArray(a, size);
    //reversedArray(a, size);
    randomArray(a, size);
    //fewUniquesArray(a, size, 5);
    printArray(a, size);
    gettimeofday(&before, 0);
    //insertionsort(a, 0, size-1);
    //shellsort(a, 0, size-1);
    //a[size - 1] = INT_MAX;
    //quicksort(a, 0, size - 2);
    //dualpivotQuicksort(a, 0, size-1);
    //dualHybridsort(a, 0, size-1);
    gettimeofday(&after, 0);
    timing = (double)((double)after.tv_sec + (double)after.tv_usec / (1000 * 1000)) -
        (double)((double)before.tv_sec + (double)before.tv_usec / (1000 * 1000));
    cout << timing << endl;
    printArray(a, size);
    
    return 0;
}
