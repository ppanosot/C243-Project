
void swap(int a[], int x, int y);

// from class note. modified to call insertion sort if array is small
void quicksort(int a[], int first, int last);

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
void dualHybridsort(int a[], int first, int last);
