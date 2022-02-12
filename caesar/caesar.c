#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    // Determine if input is valid
    if (argc != 2)
    {
        // if user input wrong aruments in CLI
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // validate the key
    for (int j = 0, e = strlen(argv[1]); j < e; ++j)
    {
        if (argv[1][j] < 48 || argv[1][j] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // cast key as an int
    int k = atoi(argv[1]);
    printf("Key is %d\n", k);
    if (k == 0 || !atoi(argv[1]))
    {
        // if user input wrong aruments in CLI
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // get plaintext
    string plaintext = get_string("Plaintext: ");

    // shift text to enciper the text
    printf("Ciphertext: ");
    int i = 0;
    while (plaintext[i] != '\0')
    {
        if islower(plaintext[i])
        {
            printf("%c", (((plaintext[i] + k) - 97) % 26) + 97);
        }
        else if isupper(plaintext[i])
        {
            printf("%c", (((plaintext[i] + k) - 65) % 26) + 65);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
        i++;
    }
    printf("\n");


}