#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int quarter_amount(int cents);
int dime_amount(int cents);
int nickel_amount(int cents);
int penny_amount(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = quarter_amount(cents);
    cents = cents - quarters * 25;

    int dimes = dime_amount(cents);
    cents = cents - dimes * 10;

    int nickels = nickel_amount(cents);
    cents = cents - nickels * 5;

    int pennies = penny_amount(cents);
    cents = cents - pennies * 1;

    int totalCoins = quarters + dimes + nickels + pennies;
    printf("%i\n", totalCoins);
}

int get_cents(void)
{
    int n;
    do
    {
        n = get_int("changed owed:");
    }
    while (n < 1);
    return n;
}

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
