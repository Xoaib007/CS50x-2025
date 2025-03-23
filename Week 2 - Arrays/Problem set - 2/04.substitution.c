/*
 * Description:
 * This program takes a substitution cipher key as an argument and uses it to 
 * encipher a plaintext input by the user. The key must be exactly 26 
 * characters long and contain no duplicate letters. The program will 
 * output the enciphered text.
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
int has_duplicate(char *str);
string encipher (string text, string key);

int main (int argc, string argv[])
{
    // Ensure exactly one command-line argument is provided
    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    // Ensure the key is exactly 26 characters long
    if (strlen(argv[1]) != 26)
    {
        printf("Key must be exactly 26 characters long.\n");
        return 1;
    }

    // Ensure the key contains only alphabetic characters
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    // Ensure the key contains no duplicate characters
    if (has_duplicate(argv[1]))
    {
        printf("Key must not contain duplicate letters.\n");
        return 1;
    }

    // Get the key from the command-line argument
    string key = argv[1];

    // Get the plaintext from the user
    string plainText = get_string("Text: ");

    // Encipher the plaintext using the key
    string cipherText = encipher(plainText, key);

    // Output the ciphertext
    printf("ciphertext: %s\n", cipherText);
}

// Function to check for duplicate characters in the key
int has_duplicate(char *str)
{
    int seen[26] = {0}; // Array to track letters (case-insensitive)

    for (int i = 0; str[i] != '\0'; i++)
    {
        int index = tolower(str[i]) - 'a'; // Normalize to lowercase
        if (seen[index]) // If already seen, it's a duplicate
        {
            return 1;
        }
        seen[index] = 1;
    }
    return 0;
}

// Function to encipher the plaintext using the given key
string encipher (string text, string key)
{
    int len = strlen(text);
    char *cipherText = malloc(len + 1); // Allocate memory for the ciphertext

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
            {
                // Find the index in the key for uppercase letters
                int alphaIndex = text[i] - 65;

                // Use the corresponding character in the key
                if (isupper(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex];
                }
                else if (islower(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex] - 32;
                }
            }
            else
            {
                // Find the index in the key for lowercase letters
                int alphaIndex = text[i] - 97;

                // Use the corresponding character in the key
                if (isupper(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex] + 32;
                }
                else if (islower(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex];
                }
            }
        }
        else
        {
            cipherText[i] = text[i]; // Preserve non-alphabetic characters
        }
    }

    return cipherText;
}
