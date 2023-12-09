// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declaring The Fonction
bool valid(string password);

int main(void)
{
    //Prompt the user for the Password
    string password = get_string("Enter your password: ");

    // Checking the Password
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int d = 0, l = 0, s = 0, u = 0;

    for (int i = 0, n = strlen(password); i < n; i++)
    {
        if (isdigit(password[i]))
        {
            d++;
        }
        if (islower(password[i]))
        {
            l++;
        }
        if (isupper(password[i]))
        {
            u++;
        }
        if (password[i] == '#' || password[i] == '@' || password[i] == '!' || password[i] == '?')
        {
            s++;
        }
    }
    if (d > 0 && l > 0 && u > 0 && s > 0)
    {
        return true;
    }
    return false;
}