#include <stdio.h>
#include <cs50.h>

// function declaration
void eachlevel(int n, int h);

int main(void)
{

    int height;

    // Prompt for user to input the height
    do
    {
        height = get_int("What's your wanted height? ");
    }
    while (height < 1 || height > 8);

    // Print all levels' bricks
    for (int level = 1; level < height + 1; level++)
    {
        // Call function eachlevel()
        eachlevel(level, height);
    }

}

void eachlevel(int n, int h)
{
    // Level ID is n
    //int n = 1;

    // Count of first few spaces
    int count_spaces = h - n;

    // Print the first few spaces
    for (int i = 0; i < count_spaces; i++)
    {
        printf(" ");
    }

    // Print bricks
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }

    // Print two spaces
    printf("  ");

    // Print bricks
    for (int j = 0; j < n; j++)
    {
        printf("#");
    }

    // Line break
    printf("\n");
}