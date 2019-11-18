#include <iostream>
#include <iomanip> // setw()
#include <string>
#include <cmath> //abs()
#include <climits> //INT_MAX
#include "interface.h"
using namespace std;

int  getNumber(string  prompt)
{
    int number = 0;
    cout << prompt;
    cin >> number;
    while(!cin.good())
    {
        cin.clear();
        cin.ignore(100,'\n');
        cout << prompt;
        cin >> number;
    }
    return number;   
}

void newArray(int*& a, int& size)
{
    size = getNumber("Enter array size: ");
    a = new int[size];
}

void fillArray(int* a, int size)
{
    for(int i=0; i<size; ++i)
    {
        a[i] = getNumber("Enter an integer: ");
    }
}

void makeUserInputArray(int*&a, int& size)
{
    newArray(a,size);
    fillArray(a,size);
}

void printArray(int* a, int size)
{
    int max = 0; //find biggest number in array
    for (int i=0; i<size; i++)
    {
        if (abs(a[i])>max)
            max = abs(a[i]);
    }
    if (max > INT_MAX)
        max = INT_MAX;

    // determine the number of  digits 
    int digits = 0;
    while(max > 0)
    {
        max /= 10;
        ++digits;
    }
    int terminal = 80;
    int count = terminal/(digits+2);
    // evenly spaced output
    cout << endl;
    for (int i=0; i<size; ++i)
    {
        if(i % count == 0)
        {    
            cout << endl;
        }
        cout << setw(digits+1) << a[i] <<" ";
    }
    cout << endl;
}
