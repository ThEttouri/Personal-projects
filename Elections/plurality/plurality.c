#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates and voters
int candidate_count;
int voter_count;

// Function prototypes
void print_winner(void);
bool vote(string name);

int main(int argc, string argv[])
{
    // Check for invalid usage
    candidate_count = argc - 1;
    if (argc < 3)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }
    else if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    voter_count = get_int("Number of voters: ");

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int j = 0; j < candidate_count; j++)
    {
        if (strcmp(candidates[j].name, name) == 0)
        {
            candidates[j].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int m = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > m)
        {
            m = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == m)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}