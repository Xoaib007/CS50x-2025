// Prints an n-heighted pyramid, re-prompting user for positive & greater than 8 integer

#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    int n = get_size();
    print_grid(n);
}

// Recieve input
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}

// Create block
void print_grid(int n)
{
    // Column
    for (int i = 0; i < n; i++)
    {
        // Row
        for (int k = 1; k < (n - i); k++)
        {
            printf(" ");
        }
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }


        printf("\n");
    }
}
