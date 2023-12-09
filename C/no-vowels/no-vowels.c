// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Declaring The Fonction
string replace(string argv[]);

int main(int argc, string argv[])
{
    // Checking the Key
    while (argc <= 1 || argc >= 3)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    // Printing The Word
    printf("%s", replace(argv));
    printf("\n");
}

string replace(string argv[])
{
    int n = strlen(argv[1]);
    string novowels = argv[1];

    // Replacing vowels with numbers
    for (int i = 0; i < n; i++)
    {
        if (argv[1][i] == 'o')
        {
            novowels[i] = '0';
        }
        if (argv[1][i] == 'a')
        {
            novowels[i] = '6';
        }
        else if (argv[1][i] == 'e')
        {
            novowels[i] = '3';
        }
        else if (argv[1][i] == 'i')
        {
            novowels[i] = '1';
        }
        else
        {
            novowels[i] = argv[1][i];
        }
    }
    return novowels;
}