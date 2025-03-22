// Caesar Cipher implementation in C
// This program takes a plaintext input and a key, and outputs the ciphertext
// with each letter shifted by the key value.

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function to encipher the given text using the provided key
string encipher (string text, int key);

int main (int argc, char* argv[])
{
    // Ensure exactly one command-line argument is provided
    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    // Check if the provided key is a valid integer
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the key from a string to an integer
    int key = atoi(argv[1]);

    // Prompt the user for the plaintext input
    string plainText = get_string("Text: ");

    // Encipher the plaintext using the provided key
    string cipherText = encipher(plainText, key);

    // Output the resulting ciphertext
    printf("Ciphertext: %s\n", cipherText);
}

string encipher (string text, int key)
{
    int len = strlen(text);

    // Allocate memory for the ciphertext
    char *cipherText = malloc(len + 1);

    // Encipher each character of the plaintext
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            // Encipher uppercase letters
            if (isupper(text[i]))
            {
                cipherText[i] = (text[i] - 65 + key) % 26 + 65;
            }
            // Encipher lowercase letters
            else
            {
                cipherText[i] = (text[i] - 97 + key) % 26 + 97;
            }
        }
        else
        {
            // Preserve non-alphabetic characters
            cipherText[i] = text[i];
        }
    }

    // Ensure the ciphertext is null-terminated
    cipherText[len] = '\0';

    return cipherText;
}
