// Prints an n-heighted pyramid, re-prompting user for positive & greater than 8 integer

#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_size(void);
void print_grid(int n);

int main(void)
{
    // Get the size of the pyramid from the user
    int n = get_size();
    // Print the grid based on the size
    print_grid(n);
}

// Function to receive input for the pyramid height
int get_size(void)
{
    int n;
    // Prompt user until a valid height (1 to 8) is entered
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Function to print the pyramid grid
void print_grid(int n)
{
    // Loop for each row
    for (int i = 0; i < n; i++)
    {
        // Print leading spaces
        for (int k = 1; k < (n - i); k++)
        {
            printf(" ");
        }
        // Print left side of the pyramid
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        // Print gap between the two sides of the pyramid
        printf("  ");
        // Print right side of the pyramid
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        // Move to the next line after printing one row
        printf("\n");
    }
}
