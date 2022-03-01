#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

// To run: make memory && ./memory

int main(void)
{
    // Pointer:

    int k;
    k = 5;

    int * pk; //create a pointer called pk, and if we go to pk, we will find an int in that memory location
    pk = &k; // &k finds the memory address of k (i.e., &k is the address of k)
    printf("%i\n",k);
    printf("%p\n",pk);

    // Derefence operator: Update value using pointer (go to the actual address and update the value)

    * pk = 6; // * is a Derefence operator, meaning go to pk which is k's address and update its value to 6
    printf("%i\n",k);
    printf("%p\n",pk);

    // Change where pointer is pointing to
    int m;
    m = 4;
    pk = &m;
    printf("%p\n",pk); // now pk points to m, no longer points to k

    // Create multiple pointers
    int *pa, *pb, *pc;

    // NULL pointer: always set pointer to NULL whenever you don't assign a value to a pointer immediately.

    // Array: name of array is actually a pointer to the first element in the array.



}