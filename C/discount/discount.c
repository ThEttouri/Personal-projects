#include <cs50.h>
#include <stdio.h>

float discount(float regular, float percent_off);

int main(void)
{
    float regular = get_float("Regular Price: ");
    float percent_off = get_float("Percent Off: ");
    float sale = discount(regular, percent_off);
    printf("Sale Price: %.2f\n", sale);
}

float discount(float regular, float percent_off)
{
    return regular = regular * (100 - percent_off) / 100;
}