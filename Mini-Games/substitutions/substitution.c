#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Checking the Key
    if (argc >= 3 || argc <= 1)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Elimination of Invalid Keys
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isalpha(argv[1][i]) == 0 || n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        // Elimination of Duplicated characters in the Key
        for (int j = 0; j < i; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must contain 26 characters.\n");
                return 1;
            }
        }
    }
    string k = argv[1];
    // Get the Plaintext from the user
    string p = get_string("Plaintext:  ");
    // Printing The Ciphertext
    printf("ciphertext: ");
    for (int z = 0, n = strlen(p); z < n; z++)
    {
        // Finding The Ciphertext for the Lowercases
        if (islower(p[z]) != 0)
        {
            int e = p[z] - 97;
            printf("%c", tolower(k[e]));
        }
        // Finding The Ciphertext for the Uppercases
        else if (isupper(p[z]) != 0)
        {
            int e = p[z] - 65;
            printf("%c", toupper(k[e]));
        }
        // Finding The Ciphertext for the non Alphabetical characters
        else if (isalpha(p[z]) == 0)
        {
            printf("%c", p[z]);
        }
    }
    printf("\n");
}