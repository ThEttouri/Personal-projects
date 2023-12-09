#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool check_validity(string);

int main(void)
{
    string phrase = get_string("What's The Secret Phrase? ");
    bool correct = check_validity(phrase);
    if (correct == true)
    {
        printf("Welcome!\n");
    }
    else
    printf("Access Denied!\n");
}

bool check_validity(string phrase)
{
    string password = "Adam";
    if (strcmp(phrase, password) == 0)
    {
        return true;
    }
    else
    return false;
}