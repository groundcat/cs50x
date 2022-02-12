#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Promot for user to input the name
    string name = get_string("What's your name? ");

    // Print the user's name
    printf("hello, %s\n", name);
}