// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

// Max number of cities
#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

// Function prototype
void sort_cities(void);

int main(void)
{
    // Intialising temps
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    // Sorting cities
    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    // Printing cities
    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Insertion sort
    for (int i = 0; i < NUM_CITIES - 1; i++)
    {
        if (temps[i].temp < temps[i + 1].temp)
        {
            string s = temps[i + 1].city;
            int t = temps[i + 1].temp;
            temps[i + 1].city = temps[i].city;
            temps[i + 1].temp = temps[i].temp;
            temps[i].city = s;
            temps[i].temp = t;
        }
        for (int j = 0; j < i; j++)
        {
            if (temps[i].temp > temps[j].temp)
            {
                string se = temps[i].city;
                int te = temps[i].temp;
                temps[i].city = temps[j].city;
                temps[i].temp = temps[j].temp;
                temps[j].city = se;
                temps[j].temp = te;
            }
        }
    }
    return;
}
