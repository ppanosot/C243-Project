/***************************************************************
  Author:	Patarut Panosot,
		Aaron Spicer
  Class: 	C243 Data Structures
  File name:	main.cc
  Last updated:	November 2019
  Description:	a program that uses optimized sorting algorithm 
		to sort and time user input integer arrays.
		to be compiled with g++ on linux.
***************************************************************/
#include <iostream>
#include <string>
#include <sys/time.h> // time function
#include <limits.h>
#include "interface.h" // create, input,  print arrays 
#include "sortfunctions.h" // sorting functions
using namespace std;

int main()
{
    struct timeval before, after;
    double timing;
    int size = 0;
    int* a = NULL;

    newUserInputArray(a, size);
    
    //printArray(a, size);
    gettimeofday(&before, 0);
    hybridsort(a, 0, size-1);
    gettimeofday(&after, 0);
    timing = (double)((double)after.tv_sec + (double)after.tv_usec / (1000 * 1000)) -
        (double)((double)before.tv_sec + (double)before.tv_usec / (1000 * 1000));
    cout << "sorted array";
    printArray(a, size);
    cout << "sort function execution time: " << timing << endl;

    return 0;
}
