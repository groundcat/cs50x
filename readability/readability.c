#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

//int count_letters(string text);
//int count_words(string text);
//int count_sentences(string text);

int main(void)
{
    // Get input words from both players
    string text = get_string("Text: ");

    // initiate variables
    int i = 0;
    int words_count = 0;
    int sentences_count = 0;
    int letters_count = 0;
    int index = 0;
    float l = 0;
    float s = 0;

    // loop through the text
    while (text[i] != '\0')
    {
        //printf("letter is %c\n", text[i]);
        if (isalnum(text[i]))
        {
            letters_count++;
        }
        else if (isspace(text[i]))
        {
            words_count++;
        }
        else if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            sentences_count++;
        }
        i++;
    }

    // Add 1 to word count
    words_count++;

    // print the count
    //printf("Letters = %d\n",letters_count);
    //printf("Words = %d\n",words_count);
    //printf("Sentences = %d\n",sentences_count);

    // Calculate L and S
    l = (double)letters_count / (double)words_count * 100;
    s = (double)sentences_count / (double)words_count * 100;
    index = round(0.0588 * (double)l - 0.296 * (double)s - 15.8);

    // Print results
    if (index < 0)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

}



