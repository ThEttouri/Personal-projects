// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Declaring factors
int factor1[26];
int factor2[26];

// Declaring the size
int s = 0;

// Declaring the number of buckets in hash table
const unsigned int N = 26 * 26 * 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hashing the word
    int h = hash(word);
    // Creating a cursor
    node *cursor = table[h];
    while (cursor != NULL)
    {
        // Comparing the words
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        else
        {
            // Moving the cursor
            cursor = cursor->next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Making the best possible hash function
    int f = 0;
    // Initialising the first factor
    for (int i = 0; i < 26; i++)
    {
        factor1[i] = i;
    }
    // Initialising the second factor
    for (int i = 0, j = 27; i < 26; i++)
    {
        if (i == 0)
        {
            factor2[i] = i;
        }
        else
        {
            factor2[i] = j;
            j = j + 27;
        }
    }

    // in case the word's lenght is bigger than 2
    if (strlen(word) > 2)
    {
        // in case the word's second character isn't alphabitical
        if (isalpha(word[1]) == 0)
        {
            f = factor2[tolower(word[0]) - 'a'];
            return (tolower(word[0]) + f * 25) - 'a';
        }
        // in case the word's third character isn't alphabitical
        else if (isalpha(word[2]) == 0)
        {
            f = factor2[tolower(word[0]) - 'a'] + factor1[tolower(word[1]) - 'a'];
            return (tolower(word[0]) + tolower(word[1]) + f * 25) - 194;
        }
        else
        {
            f = factor2[tolower(word[0]) - 'a'] + factor1[tolower(word[1]) - 'a'];
            return (tolower(word[0]) + tolower(word[1]) + tolower(word[2]) + f * 25) - 291;
        }
    }
    // in case the word's lenght is smaller than 3
    else if (strlen(word) > 1)
    {
        // in case the word's second character isn't alphabitical
        if (isalpha(word[1]) == 0)
        {
            f = factor2[tolower(word[0]) - 'a'];
            return (tolower(word[0]) + f * 25) - 'a';
        }
        else
        {
            f = factor2[tolower(word[0]) - 'a'] + factor1[tolower(word[1]) - 'a'];
            return (tolower(word[0]) + tolower(word[1]) + f * 25) - 194;
        }
    }
    // in case the word's lenght is 1
    else
    {
        f = factor2[tolower(word[0]) - 'a'];
        return (tolower(word[0]) + f * 25) - 'a';
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialising the hash function
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary file
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    char buffer[LENGTH + 1];
    int h = 0;
    while (fscanf(d, "%s", buffer) != EOF)
    {
        // Hashing the word
        h = hash(buffer);
        // Create a new node
        node *n = malloc(sizeof(node));
        if (d == NULL)
        {
            printf("Out of memory.\n");
            free(n);
            fclose(d);
            return false;
        }

        // Coping the word from the buffer
        strcpy(n->word, buffer);
        n->next = NULL;
        if (table[h] == NULL)
        {
            table[h] = n;
            s++;
        }
        else
        {
            n->next = table[h];
            table[h] = n;
            s++;
        }
    }

    // Close files
    fclose(d);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Calculating the number of words in dictionary
    return s;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Loping through arrays
    int i = 0;
    while (i < N)
    {
        node *tmp = table[i];
        // Loping through nodes
        while (tmp != NULL)
        {
            node *next = tmp->next;
            free(tmp);
            tmp = next;
        }
        i++;
    }

    if (i == N)
    {
        return true;
    }
    return false;
}