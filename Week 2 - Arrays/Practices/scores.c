#include <stdio.h>
#include <cs50.h>

// Define a constant for the number of scores
const int N = 3;

// Function prototype for calculating the average
float average(int length, int scores[]);

int main(void)
{
    // Array to store the scores
    int scores[N];
    
    // Loop to get scores from the user
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("%i th score: ", i + 1);
    }

    // Print the average of the scores
    printf("Average: %f\n", average(N, scores));
}

// Function to calculate the average of an array of scores
float average(int length, int scores[])
{
    int sum = 0;
    
    // Loop to sum the scores
    for (int i = 0; i < length; i++)
    {
        sum += scores[i];
    }

    // Calculate the average by casting sum and length to float
    float average = (float)sum / (float)length;
    return average;
}
