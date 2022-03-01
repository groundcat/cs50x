#include "helpers.h"
#include <stdio.h>
#include <math.h>

// declare functions
void swap(RGBTRIPLE *a, RGBTRIPLE *b);


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // TEST: make filter && ./filter -g images/yard.bmp images/yard-output-g.bmp

    // grayscale's channel value is an int
    int grayscale_avg = 0;

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // look through each pixel in this row
        for (int col = 0; col < width; col++)
        {
            // as long as the red, green, and blue values are all equal, the result will be varying shades of gray
            // take average of the red, green, and blue values to determine what shade of grey to make the new pixel
            grayscale_avg = round((image[row][col].rgbtRed + image[row][col].rgbtGreen + image[row][col].rgbtBlue) / 3.0);

            // apply new channel value to each pixel in the image, the result will be an image converted to grayscale
            image[row][col].rgbtRed = grayscale_avg;
            image[row][col].rgbtGreen = grayscale_avg;
            image[row][col].rgbtBlue = grayscale_avg;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    // TEST: make filter && ./filter -s images/yard.bmp images/yard-output-s.bmp

    // sepia channels
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // look through each pixel in this row
        for (int col = 0; col < width; col++)
        {

            float originalRed = image[row][col].rgbtRed;
            float originalGreen = image[row][col].rgbtGreen;
            float originalBlue = image[row][col].rgbtBlue;

            // For each pixel, the sepia color values should be calculated based on the original color values per the below.
            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            // the maximum value for an 8-bit color value.
            // In that case, the red, green, and blue values should be capped at 255.
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // apply new channel value to each pixel in the image
            image[row][col].rgbtRed = sepiaRed;
            image[row][col].rgbtGreen = sepiaGreen;
            image[row][col].rgbtBlue = sepiaBlue;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // TEST: make filter && ./filter -r images/yard.bmp images/yard-output-r.bmp

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // look through each pixel in this row but only for the left half of pixels, up to the midpoint (width / 2)
        for (int col = 0; col < width / 2; col++)
        {
            // swap the pixels
            swap(&image[row][col], &image[row][width - 1 - col]);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // TEST: make filter && ./filter -b images/yard.bmp images/yard-output-b.bmp

    // create an empty new image
    RGBTRIPLE copy[height][width];

    // Initiate variables
    float rsum, gsum, bsum; // sum of channels
    int count; // denomiters

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // look through each pixel in this row
        for (int col = 0; col < width; col++)
        {
            // empty sum and count
            rsum = gsum = bsum = 0;
            count = 0;

            // loop through 9 pixels around this pixel from -1 to 1
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    int m = row + x;
                    int n = col + y;

                    if (m < 0 || m > (height - 1) || n < 0 || n > (width - 1))
                    {
                        continue;
                    }

                    rsum += image[m][n].rgbtRed;
                    gsum += image[m][n].rgbtGreen;
                    bsum += image[m][n].rgbtBlue;
                    count++;
                }

                copy[row][col].rgbtRed = round(rsum / count);
                copy[row][col].rgbtGreen = round(gsum / count);
                copy[row][col].rgbtBlue = round(bsum / count);
            }

        }
    }

    // write from copy back to the original img

    // loop through each row
    for (int row = 0; row < height; row++)
    {
        // look through each pixel in this row
        for (int col = 0; col < width; col++)
        {
            image[row][col].rgbtRed = copy[row][col].rgbtRed;
            image[row][col].rgbtGreen = copy[row][col].rgbtGreen;
            image[row][col].rgbtBlue = copy[row][col].rgbtBlue;
        }
    }

    return;
}



// functions

// swap values by pointers
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}