/***********************************************************
  Author:	Patarut Panosot,
		Aaron Spicer
  Class: 	C243 Data Structures
  File name:	interface.h
  Last updated:	November 2019
  Description:	interface to dynamically create, input, and 
		output integer arrays.
************************************************************/
#include <string>
using namespace std;

// ask user for an integer
// return that integer
int getNumber(string prompt);

// new dynamically allocated array
void newArray(int*& a, int& size);
// fill array with inputs from user
void fillArray(int a[], int size);

void newUserInputArray(int*& a, int& size);

void printArray(int a[], int size);
