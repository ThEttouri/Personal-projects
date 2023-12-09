// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

// Function prototype
int max(int array[], int n);

int main(void)
{
    //Prompt the user for the Number of elements
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    //Prompt the user for the Elements
    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    // Printing The max value
    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int s = 0;
    int max = array[0];

    // Calculating The Number Of Negativ Numbers
    for (int i = 0; i < n; i++)
    {
        if (array[i] <= 0)
        {
            s++;
        }
    }

    // In case of One Or More Positive Number
    if (s < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] > 0 && array[i] > max)
            {
                max = array[i];
            }

        }
        return max;
    }
    // In case of no Positive Number
    else if (s == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (array[i] > max)
            {
                max = array[i];
            }
        }
        return max;
    }
    return 0;
}