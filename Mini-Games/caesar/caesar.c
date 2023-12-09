#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char p, int k);
int main(int argc, string argv[])
{
    // Checking the Key
    if (argc >= 3 || argc <= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for (int j = 0, m = strlen(argv[1]); j < m; j++)
    {
        if (isdigit(argv[1][j]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    int k = atoi(argv[1]);
    // Elimination of Negativ Keys
    if (k <= 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // Get the Plaintext from the user
    string p = get_string("Plaintext:  ");
    int i = 0;
    int n = strlen(p);
    // Printing The Ciphertext
    printf("Ciphertext: ");
    while (i < n)
    {
        char l = (char) p[i];
        printf("%c", rotate(l, k));
        i++;
    }
    printf("\n");
}

// Finding The Ciphertext
char rotate(char p, int k)
{
    // Finding The Ciphertext for the Lowercases
    if (isalpha(p) != 0 && islower(p) != 0)
    {
        int pi = (int) p - 97;
        char ci = (char)((pi + k) % 26) + 97;
        return ci;
    }
    // Finding The Ciphertext for the Uppercases
    else if (isalpha(p) != 0 && isupper(p) != 0)
    {
        int Pi = (int) p - 65;
        char Ci = (char)((Pi + k) % 26) + 65;
        return Ci;
    }
    // Finding The Ciphertext for the non Alphabetical characters
    else if (isalpha(p) == 0)
    {
        return p;
    }
    return 0;
}