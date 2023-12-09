#include <cs50.h>
#include <stdio.h>

// Function Prototype
bool prime(int number);

int main(void)
{
    // Asking for The Min
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Asking for The Max
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Loop over all Numbers
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            //Print The Primes
            printf("%i\n", i);
        }
    }
}

// Checking if Prime
bool prime(int number)
{
    if (number == 1 || number == 2)
    {
        return true;
    }
    for (int i = (number - 1); i > 1; i--)
    {
        if (number % i == 0)
        {
            return false;
        }
    }
    return true;
}
