#include <cs50.h>
#include <stdio.h>

long get_credit_card(void);
int luhns_algorithm(long number);

int main(void)
{
    long number = get_credit_card();
    int luhnsAlgorithm = luhns_algorithm(number);

    // Check card numbers
    if (((number >= 34e13 && number < 35e13) || ((number >= 37e13) && (number < 38e13))) && luhnsAlgorithm == 0)
    {
        printf("AMEX\n");
    }

    else if ((number >= 51e14) && (number < 56e14) && (luhnsAlgorithm == 0))
    {
        printf("MASTERCARD\n");
    }

    else if (((number >= 4e15 && number < 5e15) || ((number >= 4e12) && (number < 5e12))) && (luhnsAlgorithm == 0))
    {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    };
}

// Get credit card numbers
long get_credit_card(void)
{
    long n;
    do
    {
        n = get_long("Card number:");
    } while (n < 1);
    return n;
}

// Applying Luhn's Algorithm to check card is valid or not
int luhns_algorithm(long number)
{
    long cardNumber = number;
    int sum1 = 0, num = 0, remainder = 0, sum2 = 0;
    long temp = cardNumber;

    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2; // Multiplying every other digit by 2, starting with the number’s second-to-last digit
        while (num > 0)
        {
            remainder = num % 10;
            sum1 += remainder; // Adding those products’ digits together
            num /= 10;
        }
        temp /= 100;
    }

    // So as to restore the initial values of remainder and temp for the use in next loop
    remainder = 0;
    temp = cardNumber;

    while (temp > 0)
    {
        remainder = temp % 10;
        sum2 += remainder; // Sum of the digits that weren’t multiplied by 2
        temp /= 100;
    }

    int check = (sum1 + sum2) % 10;

    return check;
}
