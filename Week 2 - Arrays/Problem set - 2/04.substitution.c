#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool is_valid(int argc, string argv[]);
int has_duplicate(char *str);
string encipher (string text, string key);

int main (int argc, string argv[])
{
    if (!is_valid(argc, argv))
    {
        printf("Usage: ./program key\n");
        return 1;
    }

    string key = argv[1];

    string plainText = get_string("Text: ");

    string cipherText = encipher(plainText, key);

    printf("ciphertext: %s\n", cipherText);

    free(cipherText);

    return 0;
}

bool is_valid(int argc, string argv[])
{
    bool isValid = true;

    if(argc != 2)
    {
        return false;
    }

    if (strlen(argv[1]) != 26)
    {
        isValid = false;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            isValid = false;
        }
    }

    if (has_duplicate(argv[1]))
    {
        isValid = false;
    }

    return isValid;
}

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


string encipher (string text, string key)
{
    int len = strlen(text);

    char *cipherText = malloc(len + 1);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
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
