// Program to calculate the minimum number of coins required for a given amount of cents.
// It uses functions to determine the number of quarters, dimes, nickels, and pennies needed.

#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_cents(void);
int quarter_amount(int cents);
int dime_amount(int cents);
int nickel_amount(int cents);
int penny_amount(int cents);

int main(void)
{
    // Get the amount of cents owed
    int cents = get_cents();

    // Calculate the number of quarters
    int quarters = quarter_amount(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes
    int dimes = dime_amount(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels
    int nickels = nickel_amount(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies
    int pennies = penny_amount(cents);
    cents = cents - pennies * 1;

    // Calculate the total number of coins
    int totalCoins = quarters + dimes + nickels + pennies;
    printf("%i\n", totalCoins);
}

// Function to get the amount of cents owed from the user
int get_cents(void)
{
    int n;
    do
    {
        n = get_int("change owed: ");
    }
    while (n < 1);
    return n;
}

// Function to calculate the number of quarters
int quarter_amount(int cents)
{
    int count = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        count++;
    }
    return count;
}

// Function to calculate the number of dimes
int dime_amount(int cents)
{
    int count = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        count++;
    }
    return count;
}

// Function to calculate the number of nickels
int nickel_amount(int cents)
{
    int count = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        count++;
    }
    return count;
}

// Function to calculate the number of pennies
int penny_amount(int cents)
{
    int count = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        count++;
    }
    return count;
}
