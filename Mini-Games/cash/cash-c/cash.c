#include <stdio.h>
#include <cs50.h>

// Declaring The Fonctions
int get_cents(void);
int calculate_quarters(int c);
int calculate_dimes(int c);
int calculate_nickels(int c);
int calculate_pennies(int c);

int main(void)
{
    //Prompt the user for the Change
    int c = get_cents();

    //Calculate the number of Quarters to give the Customer
    int q = calculate_quarters(c);
    c = c - (q * 25);

    //Calculate the number of Dimes to give the Customer
    int d = calculate_dimes(c);
    c = c - (d * 10);

    //Calculate the number of Nickels to give the Customer
    int n = calculate_nickels(c);
    c = c - (n * 5);

    //Calculate the number of Pennies to give the Customer
    int p = calculate_pennies(c);
    c = c - (p * 1);

    //Sum Coins
    int m = q + d + n + p;

    //Print Total Number of Coins to give the Customer
    printf("%i\n", m);
}

//Cents Function
int get_cents(void)
{
    int z;
    do
    {
        z = get_int("Change owed: ");
    }
    while (z < 0);
    return z;
}

//Quarters Function
int calculate_quarters(int c)
{
    int qu;
    for (qu = 0 ; c > 25 || c == 25 ; qu++)
    {
        c = c - 25;
    }
    return qu;
}

//Dimes Function
int calculate_dimes(int c)
{
    int di;
    for (di = 0 ; c > 10 || c == 10 ; di++)
    {
        c = c - 10;
    }
    return di;
}

//Nickels Function
int calculate_nickels(int c)
{
    int ni;
    for (ni = 0 ; c > 5 || c == 5 ; ni++)
    {
        c = c - 5;
    }
    return ni;
}

//Pennies Function
int calculate_pennies(int c)
{
    int pe;
    for (pe = 0 ; c > 1 || c == 1 ; pe++)
    {
        c = c - 1;
    }
    return pe;
}