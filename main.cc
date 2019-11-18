#include "interface.h" // create, input,  print arrays 
#include "makeArray.h" // for generated array

using namespace std;


int main()
{
    int* array;
    int size;
    makeUserInputArray(array, size);
    printArray(array, size);


   return 0;
}
