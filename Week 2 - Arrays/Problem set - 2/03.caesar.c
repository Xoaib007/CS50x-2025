#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encipher (string text, int key);

int main (int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]);
    string plainText = get_string("Text: ");

    string cipherText = encipher(plainText, key);

    printf("Ciphertext: %s\n", cipherText);
}

string encipher (string text, int key)
{
    int len = strlen(text);

    char *cipherText = malloc(len + 1);

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            if(isupper(text[i]))
            {
                cipherText[i] = (text[i] - 65 + key) % 26 + 65;
            }
            else
            {
                cipherText[i] = (text[i] - 97 + key) % 26 + 97;
            }
        }
        else
        {
            cipherText[i] = text[i]; // Preserve non-alphabetic characters
        }
    }

    return cipherText;
}
