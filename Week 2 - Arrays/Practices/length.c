// This program prompts the user for their name and then calculates and displays the length of the provided name.

#include <stdio.h>
#include <cs50.h>

// Function prototype for calculating the length of a string
int string_length(string name);

int main(void)
{
    // Prompt user for their name
    string name = get_string("Name: ");
    
    // Calculate the length of the provided name
    int length = string_length(name);

    // Print the length of the name
    printf("The length of your name is %i\n", length);
}

// Function to calculate the length of a string
int string_length(string name)
{
    int n = 0;
    // Iterate through each character in the string until the null terminator is reached
    while(name[n] != '\0')
    {
        n++;
    }
    // Return the length of the string
    return n;
}
