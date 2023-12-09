#include <stdio.h>
#include <cs50.h>

// Declaring The Fonctions
void print_credit_card_brand(long ccn);
bool check_validity(long ccn);
int find_length(long ccn);
bool checksum(long ccn);

int main(void)
{
    // Prompt The User For The Number
    long ccn;
    do
    {
        ccn = get_long("Number: ");
    }
    while (ccn < 0);

    if (check_validity(ccn))
    {
        // Printing The Brand
        print_credit_card_brand(ccn);
    }
    else
    {
        printf("INVALID\n");
    }
}
// Check Validity Of CCN
bool check_validity(long ccn)
{
    // Finding Length
    int len = find_length(ccn);
    return (len == 13 || len == 15 || len == 16) && checksum(ccn);
}
// Check The Card Length
int find_length(long ccn)
{
    int len;
    for (len = 0; ccn != 0; ccn /= 10, len++);
    return len;
}
// Calculate Checksum
bool checksum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}
// Check The Starting Digits
void print_credit_card_brand(long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}