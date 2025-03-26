// This program implements a simple plurality voting system.
// It reads candidate names from the command line, allows voters to cast votes, and prints the winner(s).

#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Struct to represent a candidate
typedef struct {
    string name;  // Candidate's name
    int votes;    // Number of votes received
} candidate;

// Array to hold the candidates
candidate candidates[9];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for valid number of arguments
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > 9 || candidate_count < 1)
    {
        printf("Maximum number of candidates is 9\n");
        return 2;
    }

    // Initialize candidates
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Get the number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop through each voter
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print the winner(s)
    print_winner();
}

// Function to update vote totals given a new vote
bool vote(string name)
{
    // Loop through candidates to find the one voted for
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Function to print the winner(s) of the election
void print_winner(void)
{
    int max_votes = 0;

    // Find the maximum number of votes any candidate received
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print the name(s) of the candidate(s) with the most votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

    return;
}
