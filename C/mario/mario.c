#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the Height
    int n;
    do
    {
        n = get_int("The Height: ");
    }
    while (n > 8 || n < 1);
    // Building the Spaces
    int z = n;
    for (int i = 0 ; i < n ; i++)
    {
        int m = 1;
        while (m < z)
        {
            printf(" ");
            m++;
        }
        z--;
        // Building the left-aligned Pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        // Building the -aligned Pyramid
        for (int x = 0; x <= i; x++)
        {
            printf("#");
        }
        printf("\n");
    }
}