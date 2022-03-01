#include <cs50.h>
#include <string.h>
#include <stdlib.h>

// To run: make malloc && ./malloc

// statically create int --> memory on stack
int x;

// dynamically create int -- > memory on heap
int *px = malloc(sizeof(int)); // find 4 bytes of memory from heap and return a pointer called px to that memory

// Dynamic Memory Allocation
int x = get_int(); // get an int from user
float stack_array[x]; // array of floats on the stack
float *heap_awway = malloc(x * sizeof(float)); // array of floats on the heap

free(heap_awway); // release the memory; only free things you created using malloc, dont free more than once!

