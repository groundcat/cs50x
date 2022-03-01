// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// TODO: Initialize the count of nodes (for the size function)
int count_nodes = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash word to obtain a hash value
    int hash_value = hash(word);

    // Access linked list at that index in the hash table
    node *n = table[hash_value];

    // Traverse linked list, looking for the word (strcasecmp)
    while (n != NULL)
    {
        // use strcasecmp to compare it case-insensitively
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        // move cursor to the next word
        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    //return toupper(word[0]) - 'A';

    // initialize leading char
    char lead [LENGTH + 1];

    // take the first letter of a word, also making is case insensitive
    lead[0] = tolower(word[0]);

    // returns an index from 0 to 25
    int index = lead[0] % N;
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    // Open up the dictionary file, also check if the return value is null
    // FILE *fopen(const char *filename, const char *mode)
    FILE *dictionary_text = fopen(dictionary, "r");
    if (dictionary_text == NULL)
    {
        return 1; // fail to open file
    }

    // Initialize node
    char dictionary_word[LENGTH + 1];
    //node *n = NULL;

    // Read strings from file one at a time, using fscanf, read the file until reaching the end (EOF)
    // Loop through each word
    while (fscanf(dictionary_text, "%s", dictionary_word) != EOF)
    {
        // create a new node for each word
        node *n = malloc(sizeof(node));

        // check if it returns NULL
        if (n == NULL)
        {
            return 1;
        }

        // copy word into node using strcpy
        strcpy(n->word, dictionary_word);

        // hash word to obtain a hash value by calling the
        // call hash() function which takes a string (dictionary_word) and returns an index (hash_value)
        int hash_value = hash(dictionary_word);

        // insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;

        // count the number of words for the size() function
        count_nodes++;
    }

    // close the dictionary file
    fclose(dictionary_text);
    return true;
    //return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count_nodes;
    //return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        // head
        if (table[i] != NULL)
        {

            // create a tmp variable to keep track of the linked list
            node *tmp = NULL;

            // moving cursor through the linked list one by one (to next) until reaching the end (NULL)
            for (node *n = table[i]; n != NULL; n = n->next)
            {
                tmp = n;
                free(tmp); // freeing tmp, not freeing cursor, otherwise we will lose the remaining linked
            }
        }
    }

    return true;
    //return false;

    // check using
    // $ help50 valgrind ./speller
}

