#include <stdio.h>
#include <cs50.h>

int get_current(void);
int get_goal(int get_current);

int main(void)
{
    int current = get_current();
    int goal = get_goal(current);


    int year = 0;
    while(current <= goal)
    {
        current += current / 3;
        current -= current / 4;
        year++;
    }

    printf("Years: %i\n", year);
}

// Get current population
int get_current(void)
{
    int n;
    do
    {
        n = get_long("Current population: ");
    }
    while (n < 9);
    return n;
}

// Get goal population
int get_goal(int get_current)
{
    int n;
    do
    {
       n = get_long("Goal population: ");
    }
    while (n <= get_current);
    return n;
}
