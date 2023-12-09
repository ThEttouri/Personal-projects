#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Declaring The Fonctions
bool check_correctness(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
void Coleman_Liau_index(int letters, int words, int sentences);

int main(void)
{
    // Get the Text from the user
    string text = get_string("Text: ");
    while (check_correctness(text) == false)
    {
        text = get_string("Text: ");
    }
    // Store the variables
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences =  count_sentences(text);
    // Compute the index and printing it
    Coleman_Liau_index(letters, words, sentences);
}

// Checking the Correctness
bool check_correctness(string text)
{
    for (int i = 0, n = strlen(text); i < n - 1; i++)
    {
        // Elimination of consecutive spaces
        if (text[i] == ' ' && text[i + 1] == ' ')
        {
            printf("It looks like you used consecutive spaces in your text.\n");
            return false;
        }
        // Elimination of wrong Punctuation
        else if ((text[i] == '!' && (i == 0 || i == 1)) || (text[i] == '?' && (i == 0 || i == 1)) || (text[i] == '.' && (i == 0 || i == 1))
                 || (text[i] == ',' && (i == 0 || i == 1)))
        {
            printf("It looks like you used Punctuation in the beginning of your text.\n");
            return false;
        }
    }
    return true;
}

// Finding the number of Letters
int count_letters(string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            sum++;
        }
    }
    return sum;
}

// Finding the number of Words
int count_words(string text)
{
    int sum = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            sum++;
        }
    }
    return sum + 1;
}

// Finding the number of Sentences
int count_sentences(string text)
{
    int sum = 0;
    int n = strlen(text);
    if (text[n - 1] == '!' || text[n - 1] == '?' || text[n - 1] == '.')
    {
        sum++;
    }
    for (int i = 0; i < n; i++)
    {
        // Exceptional cases filtering
        if (text[i] == '.' && text[i - 3] != ' ' && text[i - 4] != ' ' && i != n - 1 && i != 2 && i != 3)
        {
            sum++;
        }
        else if ((text[i] == '.' && text[i - 3] == ' ' && isupper(text[i - 2]) == 0 && i != n - 1 && i != 2 && i != 3) || (text[i] == '.'
                 && text[i - 4] == ' ' && isupper(text[i - 3]) == 0 && i != n - 1 && i != 2 && i != 3))
        {
            sum++;
        }
        else if (text[i] == '!' && isupper(text[i + 2]) != 0 && i != n - 1)
        {
            sum++;
        }
        else if (text[i] == '?' && isupper(text[i + 2]) != 0 && i != n - 1)
        {
            sum++;
        }
    }
    return sum;
}

// Computing the index and printing it
void Coleman_Liau_index(int letters, int words, int sentences)
{
    // Parameters calculation
    float l = ((float) letters / (float) words) * 100;
    float s = ((float) sentences / (float) words) * 100;
    // Index calculation
    int g = round(0.0588 * l - 0.296 * s - 15.8);
    // Index Printing
    if (g < 1)
    {
        printf("Before Grade 1\n");
    }
    if (g >= 1 && g <= 15)
    {
        printf("Grade %i\n", g);
    }
    if (g >= 16)
    {
        printf("Grade 16+\n");
    }
}