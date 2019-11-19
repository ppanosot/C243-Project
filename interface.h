#include <string>
using namespace std;

// ask user for an integer
// return that integer
int getNumber(string prompt);

// new dynamically allocated array
void newArray(int*& a, int& size);
// fill array with inputs from user
void fillArray(int a[], int size);

void makeUserInputArray(int*& a, int& size);

void printArray(int a[], int size);
