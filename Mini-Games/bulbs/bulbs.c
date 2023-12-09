#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

// Declaring The Fonction
void print_bulb(int bit);

int main(void)
{
    // Prompt the user for the Message
    string message = get_string("Message: ");

    // Converting The Message Into Binary
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int bits[BITS_IN_BYTE] = {0, 0, 0, 0, 0, 0, 0, 0};
        int d = (int) message[i];

        int q = 0;
        int k = 1;
        do
        {
            q = d / 2;
            bits[BITS_IN_BYTE - k] = d % 2;
            d = q;
            k++;
        }
        while (q != 0);
        // Printing The Bulbs
        for (int m = 0; m < BITS_IN_BYTE; m++)
        {
            print_bulb(bits[m]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
