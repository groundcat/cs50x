#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// define a BYTE as 8 bits, so we can refer to a byte as a type more easily
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // TEST: make recover && ./recover card.raw
    // Reference: https://cs50.harvard.edu/x/2022/notes/4/

    // check command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // open the file in read mode
    FILE *file = fopen(argv[1], "r");
    // check if the forensic image cannot be opened for reading
    if (file == NULL)
    {
        printf("The forensic image cannot be opened for reading!\n");
        return 1;
    }

    // “block size” is 512 bytes
    BYTE bytes[512];


    // set default to false
    bool jpeg_signature = false; // whether there is signature found

    // filename starts from 000, so initialize the count as -1
    int count = -1;
    char file_name[9];

    // Read 512 bytes
    while (fread(bytes, sizeof(BYTE), 512, file))
    {
        // look for JPEG signature in the first 3 bytes
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff)
        {
            // signature found
            jpeg_signature = true;

            // generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000
            count++;
            sprintf(file_name, "%03.f.jpg", (float) count);

            // create JPEG file
            FILE *img = fopen(file_name, "w");

            if (img == NULL)
            {
                printf("Could not open %s.\n", file_name);
                fclose(file);
                return 1;
            }

            // write JPEG file
            fwrite(bytes, sizeof(BYTE), 512, img);

            // close JPEG file
            fclose(img);

        }
        else
        {
            // only if signature found
            if (jpeg_signature)
            {
                FILE *img = fopen(file_name, "a");
                fwrite(bytes, sizeof(BYTE), 512, img);
                fclose(img);
            }
        }
    }
    fclose(file);


}