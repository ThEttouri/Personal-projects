#include <cs50.h>
#include <stdio.h>

int collaz(int n);

int main(void)
{
    int n = get_int("N = ");
    printf("The Collaz is: %i\n", collaz(n));
}

int collaz(int n)
{
    if ( n == 1 )
        return 0;
    else if ( n % 2 == 0)
        return 1 + collaz(n / 2);
    else
        return 1 + collaz(3*n + 1);
}