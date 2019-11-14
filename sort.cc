#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct timeval before, after;
double timing;

void quicksort(int a[], int first, int last);
void makeArrays(int*  b[], int size); // generate of pointer to  arrays
void makeArray(int a[], int size); // generate array of random integers

const int SIZE = 10000;

int main(){
    int* b[100];
    double total  = 0;
    makeArrays(b,100);
    //gettimeofday(&before,0);
    for(int i=0;i<100; ++i)
    {
        gettimeofday(&before,0);
        quicksort(b[i],0,SIZE-1);
        gettimeofday(&after,0);
        timing = (double) ((double)after.tv_sec + (double)after.tv_usec/(1000*1000))-
                 (double) ((double)before.tv_sec + (double)before.tv_usec/(1000*1000));
        //cout << timing <<endl;
        total += timing;
    }
    
    cout <<"average is " << total/100 <<endl;
    return 0;
}

void quicksort(int a[], int first, int last)
{
    if (last<=first)
        return;
    if (last-first > 3)// if array not small, use middle element as pivot
        swap(a[first], a[(last+first)/2]);

    int i = first + 1, j = last;
    while (a[i] < a[first] && i <= j)
        ++i;
    while (a[j] > a[first])
        --j;
    while ( i<j)
    {
        swap (a[i], a[j]);
        do
            ++i;
        while (a[i] < a[first]);
        do 
            --j;
        while (a[j] > a[first]);
    }
    swap (a[first], a[j]);
    quicksort(a, first, j-1);
    quicksort(a, j+1, last);
} // quicksort()

void makeArrays(int* b[],int size)
{
    srand(42);//seed random
    for (int i=0; i<size; i++)
    {
        int*a = new int[SIZE+1];
        makeArray(a,SIZE);
        b[i] = a;
    }
}
void makeArray(int a[], int size)
{
    for (int i=0; i<size; i++)
    {
        a[i] = random();
    }
    a[size] = INT_MAX;
}

