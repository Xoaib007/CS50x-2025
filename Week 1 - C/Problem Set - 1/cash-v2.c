#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int coin_amount(int cents, int value);

int main(void)
{
    int cents = get_cents();

    int quarters = coin_amount(cents, 25);
    cents = cents - quarters * 25;

    int dimes = coin_amount(cents, 10);
    cents = cents - dimes * 10;

    int nickels = coin_amount(cents, 5);
    cents = cents - nickels * 5;

    int pennies = coin_amount(cents, 1);
    cents = cents - pennies * 1;

    printf("%i\n", quarters + dimes + nickels + pennies);
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

int coin_amount(int cents, int value)
{
    int count = 0;
    while (cents >= value)
    {
        cents = cents - value;
        count++;
    }
    return count;
}
