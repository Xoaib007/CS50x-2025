// This program demonstrates the use of command line arguments in C.
// It checks if a single command line argument is provided and prints a greeting message.

#include <cs50.h>
#include <stdio.h>

// Main function that takes command line arguments
int main(int argc, string argv[])
{
    // Check if the number of command line arguments is not equal to 2
    if(argc != 2)
    {
        // Print an error message if a command line argument is missing
        printf("missing command line argument\n");
        return 1; // Return an error code
    }

    // Print a greeting message with the provided command line argument
    printf("Hello, %s\n", argv[1]);
}
