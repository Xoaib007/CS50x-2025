/*
 * This program converts a given string to uppercase.
 * It prompts the user for a string input and then converts
 * all lowercase letters in the string to uppercase.
 */

#include <stdio.h>
#include <string.h>
#include <cs50.h>

// Function prototype
string uppercase_convert(string s);

int main (void)
{
    // Get input string from user
    string s = get_string("Before: ");
    
    // Convert the input string to uppercase
    string converted = uppercase_convert(s);

    // Print the converted string
    printf("After: %s\n", converted);
}

// This function takes a string as input and converts all lowercase letters to uppercase. It returns the modified string.
string uppercase_convert(string s)
{
    // Iterate through each character in the string
    for(int i = 0 , n = strlen(s); i < n; i++)
    {
        // Check if the character is a lowercase letter
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            // Convert to uppercase by subtracting 32
            s[i] = s[i] - 32;
        }
        else
        {
            // Leave non-lowercase characters unchanged
            s[i] = s[i];
        }
    }

    // Return the converted string
    return s;
}
