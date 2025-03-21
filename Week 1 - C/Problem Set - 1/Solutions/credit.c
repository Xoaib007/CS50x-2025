// This program determines the type of a credit card (AMEX, MASTERCARD, VISA) based on its number.
// It uses Luhn's algorithm to validate the card number and checks specific number patterns to identify the card type.

#include <cs50.h>
#include <stdio.h>

// Function prototypes
long get_credit_card(void);
int luhns_algorithm(long number);

int main(void)
{
    // Get the credit card number from the user
    long number = get_credit_card();
    // Apply Luhn's algorithm to check if the card number is valid
    int luhnsAlgorithm = luhns_algorithm(number);

    // Check card type based on number patterns and validity (using Luhn's algorithm)
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
    else
    {
        printf("INVALID\n");
    }
}

// Function to get the credit card number from the user
long get_credit_card(void)
{
    long n;
    do
    {
        n = get_long("Card number: ");
    } while (n < 1); // Ensure the number is positive
    return n;
}

// Function to apply Luhn's Algorithm to check if the card number is valid
int luhns_algorithm(long number)
{
    long cardNumber = number;
    int sum1 = 0, num = 0, remainder = 0, sum2 = 0;
    long temp = cardNumber;

    // Loop to multiply every other digit by 2, starting with the number’s second-to-last digit
    while (temp > 0)
    {
        num = ((temp / 10) % 10) * 2;
        while (num > 0)
        {
            remainder = num % 10;
            sum1 += remainder; // Add the digits of the products together
            num /= 10;
        }
        temp /= 100;
    }

    // Reset remainder and temp to their initial values
    remainder = 0;
    temp = cardNumber;

    // Loop to sum the digits that weren’t multiplied by 2
    while (temp > 0)
    {
        remainder = temp % 10;
        sum2 += remainder;
        temp /= 100;
    }

    // Calculate the final check value
    int check = (sum1 + sum2) % 10;

    return check; // Return 0 if valid, otherwise non-zero
}
