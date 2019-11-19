#include "sortfunctions.h"
void swap(int a[], int x, int y) 
{
    int temp = a[x];
    a[x] = a[y];
    a[y] = temp;
}

// from class note. modified to call insertion sort if array is small 
void quicksort(int a[], int first, int last)
{

    if (last - first < 21)
    {
    	insertionsort(a, first, last);
    	return;
    }
    int i = first + 1, j = last;
    while (a[i] < a[first] && i <= j)
        ++i;
    while (a[j] > a[first])
        --j;

    while (i < j)
    {
        swap(a, i, j);

        do
            ++i;
        while (a[i] < a[first]);

        do
            --j;
        while (a[j] > a[first]);
    }

    swap(a, first, j);
    quicksort(a, first, j - 1);
    quicksort(a, j + 1, last);
} // quicksort()


// from class note. modified to work with with subarray
// given the first and last indices.
void insertionsort(int a[], int first, int last)
{
    for (int p = first + 1; p <= last; ++p)
    {
        int temp = a[p];
        int i = p - 1;
        while (i >= 0 && a[i] > temp)
        {
            a[i + 1] = a[i];
            --i;
        }
        a[i + 1] = temp;
    }
} // insertionsort()


// shell sort function. implemented to work with subarray
// given the first and last indices.
void shellsort(int a[], int first, int last)
{
    for (int gap = (last - first) / 2; gap > 0; gap /= 2)
    {
        for (int i = first + gap; i <= last; ++i)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
        a[j] = temp;
        }
    }
} // shellsort()

// dual pivot quicksort. a simplified implementation of the algorithm by
// Vladimir Yaroslavskiy
void dualpivotQuicksort(int a[], int first, int last)
{
    if (last - first < 27)
    {
        insertionsort(a, first, last);
        return;
    }

    if (a[first] > a[last])
    {
        swap(a, first, last);
    }
    int p1 = a[first];
    int p2 = a[last];

    // pointers
    int lt = first + 1;
    int gt = last - 1;

    // sort
    for (int i = lt; i <= gt; i++)
    {
        if (a[i] < p1)
        {
            swap(a, i, lt++);
        }
        else if (a[i] > p2)
        {
            while (i < gt && a[gt] > p2)
            {
                --gt;
            }
            swap(a, i, gt--);
            if (a[i] < p1)
            {
                swap(a, i, lt++);
            }
        }
    }
    swap(a, lt - 1, first);
    swap(a, gt + 1, last);
    dualpivotQuicksort(a, first, lt - 2);
    dualpivotQuicksort(a, gt + 2, last);

    // equal elements
    if (gt - lt > last - first -13 && p1 != p2)
    {
        for (int i = lt; i <= gt; i++)
        {
            if (a[i] == p1)
            {
                swap(a, i, lt++);
            }
            else if (a[i] == p2)
            {
                swap(a, i, gt--);
                if (a[i] == p1)
                {
                    swap(a, i, lt++);
                }
            }
        }
    }

    // mid array

    if (p1 < p2)
    {
        dualpivotQuicksort(a, lt, gt);
    }
} // dualpivotQuicksort()


void dualHybridsort(int a[], int first, int last)
{
    if(last - first < 27 )
    {
        insertionsort(a, first, last);
        return;
    }
    int k = 0;
    for(int i=first; i<last;++i)
    {
        if(a[i]<a[i+1])
            ++k;
        else
            --k;
    }
    // if more than 3/4 is increasing 
    if(k > (last-first)*3/4)
    {
        insertionsort(a, first, last);
        return;
    }
    // if more than 3/4 is decreasing
    else if (k < -(last-first)*3/4)
    {
        shellsort(a, first, last);
        return;
    } 
    dualpivotQuicksort(a, first, last); 
}
