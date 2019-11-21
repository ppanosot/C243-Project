/***********************************************************
  Author:	Patarut Panosot,
		Aaron Spicer
  Class: 	C243 Data Structures
  File name:	sortfunctions.h
  Last updated:	November 2019
  Description:	Optimized sorting function for integer array
***********************************************************/
void swap(int a[], int x, int y);

// from class note. first and last index parameters to
// make it callable on subarray
void insertionsort(int a[], int first, int last);

// shell sort function. implemented to work with subarray
// given the first and last indices.
void shellsort(int a[], int first, int last);

// dual pivot quicksort. a simplified implementation of the algorithm by
// Vladimir Yaroslavskiy
void dualpivotQuicksort(int a[], int first, int last);

// call insertion sort if array is mostly ordered
// else call dualpivot quicksort
void hybridsort(int a[], int first, int last);
