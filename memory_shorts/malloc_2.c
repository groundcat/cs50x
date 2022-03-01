#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

// To run: make malloc_2 && ./malloc_2

int m; // stack
int *a;
int *b = malloc(sizeof(int)); // heap

a = &m;
a = b;

m = 10;
*b = m + 2;

free(b);
