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

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

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
// vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            // If name matches one of the names of the candidates in the election, then update that candidate’s vote total to
            // account for the new vote. The vote function in this case should return true to indicate a successful ballot.
            candidates[i].votes++;
            return true;
            //break;
        }
    }

    // If name does not match the name of any of the candidates in the election, no vote totals should change,
    // and the vote function should return false to indicate an invalid ballot.
    return false;

}

// Print the winner (or winners) of the election
void print_winner(void)
{

    // TODO
    // Loop and find the winner's vote count, which is the highest vote count

    int highest_count = 0;
    string winnner_name;

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes > highest_count)
        {
            highest_count = candidates[j].votes; // update the value of the highest vote count
        }
    }

    for (int k = 0; k < candidate_count; k++)
    {
        if (candidates[k].votes == highest_count)
        {
            printf("%s\n", candidates[k].name);
        }
    }


    return;
}