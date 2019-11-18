#include <stdlib.h> //srand()
#include "makeArray.h"
using namespace std;

void orderedArray(int a[], int size)
{
    for(int i=0; i<size; ++i)
    {
        a[i]=i;
    }
}

// n is number of unordered element
void nearlyOrderedArray(int a[], int size, int n)
{   
    srand(42);
    orderedArray(a,size);
    for(int i=0; i<n; ++i)
    {
        int x  = rand()%size;
        int y = rand()%size;
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
    }
}

// n is number of unique elements
void fewUniquesArray(int a[], int size, int n)
{
    srand(42);
    for(int i=0; i<size; ++i)
    {
        a[i] = rand()%n;
    }
}

void reversedArray(int a[], int size)
{
    for(int i=0; i<size; ++i)
    {
        a[i]=size-i;
    }
}
