#include <iostream>
#include <sys/time.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct timeval before, after;
double timing;

void insertionsort(int a[], int first, int last);
void shellsort(int a[], int first, int last);
//void selectionsort(int a[], int first, int last);
// taken from class note entirely
// added an if block that checks whether the array is
// small enough to use the first element as pivot
void quicksort(int a[], int first, int last); 

void makeArrays(int*  b[], int size); // generate array of pointer to  arrays
void makeArray(int a[], int size); // generate array of random integers

const int SIZE = 10000;

int main(){
    int* b[100];
    double total  = 0;
    makeArrays(b,100);
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

    /*shellsort(b[0],0,SIZE);
    for (int i=0; i<SIZE; i++)
        cout << b[0][i] << " ";
    */
    return 0;
}

// taken from class note entirely.
// added an if block that checks whether the array is
// small enough to use the first element as pivot
void quicksort(int a[], int first, int last)
{
    if (last<=first)
        return;
    if (last - first < 21)
    {
        //shellsort(a,first,last);
        insertionsort(a,first,last);
        return;
    }
    /*if (last-first > 5000)// if array not small, use middle element as pivot
    {  
        int temp = a[first];
        a[first] = a[(last+first)/2];
        a[(last+first)/2] = temp;
    }*/
    int i = first + 1, j = last;
    while (a[i] < a[first] && i <= j)
        ++i;
    while (a[j] > a[first])
        --j;
    while ( i<j)
    {
        int temp =  a[i];
        a[i] =  a[j];
        a[j] = temp;
        do
            ++i;
        while (a[i] < a[first]);
        do 
            --j;
        while (a[j] > a[first]);
    }

    int temp = a[first];
    a[first] =  a[j];
    a[j] = temp;

    quicksort(a, first, j-1);
    quicksort(a, j+1, last);
} // quicksort()

// from class note
void insertionsort(int a[], int first, int last)
{
    for (int p = first; p < last; ++p)
    {
        int temp = a[p];
        int i = p -1;
        while (i >= 0 && a[i] > temp)
        {
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = temp;
    }
} // insertionsort()

// shellsort
void shellsort(int a[], int first, int last)
{
    for( int gap = (last-first)/2; gap > 0; gap/=2)
    {
        for (int i = first + gap; i < last; i++)
        {
            int temp = a[i];
            for (int j = i; j >= gap && a[j-gap] > temp; j-=gap)
            {
                a[j] = a[j-gap];
		a[j-gap] = temp;
            }
        }
    }
}

// from class note
/*void selectionsort(int a[], int first, int last)
{
    for (int k = last-1; k > first; --k)
    {
        int best = first;
        for (int j = first+1; j <= k; ++j)
        {
            if (a[j] > a[best])
                best = j;
        }
        int temp = a[best];
        a[best] =  a[k];
        a[k] = temp;
    }
}*/
// generate array of pointer to arrays
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

// generate array of random integers
void makeArray(int a[], int size)
{
    for (int i=0; i<size; i++)
    {
        a[i] = random();//%1000;
    }
    a[size] = INT_MAX;
}

