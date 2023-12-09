#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// Declaring The Fonction
float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    //Prompt the user for the Weeks
    int weeks = get_int("Number of weeks taking CS50: ");
    // Array of Hours
    int hours[weeks];

    //Prompt the user for the Hours
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    //Prompt the user for the Output
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    // Printing The Hours
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// Calculating The Hours
float calc_hours(int hours[], int weeks, char output)
{
    float total = 0;
    for (int i = 0; i < weeks; i++)
    {
        total += hours[i];
    }

    float average = total / (float) weeks;

    if (output == 'T')
    {
        return total;
    }
    else if (output == 'A')
    {
        return average;
    }
    return 0;
}