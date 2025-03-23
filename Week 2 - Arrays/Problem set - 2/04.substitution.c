// This program is a substitution cipher implementation in C.
// It takes a 26-character key as a command-line argument and enciphers a user-provided plaintext using that key.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool is_valid(int argc, string argv[]);
int has_duplicate(char *str);
string encipher(string text, string key);

int main(int argc, string argv[])
{
    // Validate the key
    if (!is_valid(argc, argv))
    {
        printf("Usage: ./program key\n");
        return 1;
    }

    // Get the key from command-line arguments
    string key = argv[1];

    // Get the plaintext from user input
    string plainText = get_string("Text: ");

    // Encipher the plaintext using the key
    string cipherText = encipher(plainText, key);

    // Print the resulting ciphertext
    printf("ciphertext: %s\n", cipherText);

    // Free allocated memory for ciphertext
    free(cipherText);

    return 0;
}

// Function to validate the command-line arguments and the key
bool is_valid(int argc, string argv[])
{
    bool isValid = true;

    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        return false;
    }

    // Check if the key length is 26 characters
    if (strlen(argv[1]) != 26)
    {
        isValid = false;
    }

    // Check if all characters in the key are alphabetic
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            isValid = false;
        }
    }

    // Check if the key contains duplicate characters
    if (has_duplicate(argv[1]))
    {
        isValid = false;
    }

    return isValid;
}

// Function to check if a string has duplicate characters
int has_duplicate(char *str)
{
    int seen[26] = {0}; // Array to track letters (case-insensitive)

    // Iterate through each character in the string
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

// Function to encipher the plaintext using the provided key
string encipher(string text, string key)
{
    int len = strlen(text);

    // Allocate memory for the ciphertext
    char *cipherText = malloc(len + 1);

    // Iterate through each character in the plaintext
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            // For uppercase letters
            if (isupper(text[i]))
            {
                int alphaIndex = text[i] - 65;

                if (isupper(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex];
                }
                else if (islower(key[alphaIndex]))
                {
                    cipherText[i] = key[alphaIndex] - 32;
                }

            }
            // For lowercase letters
            else
            {
                int alphaIndex = text[i] - 97;

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
