#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Declaring The Variable
int m = 0;

// Function prototype
int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    // Check for invalid input
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int n = strlen(input);
    int i = n - 1;
    int temp = 0;

    // Base case
    if (n == 0)
    {
        return m;
    }

    while (i >= 0)
    {
        temp = input[i] - '0';
        input[i] = 0;
        // Calling The fonction again
        convert(input);
        m = round(m * 10 + temp);
        return m ;
    }

    return m ;
}