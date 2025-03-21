#include <stdio.h>
#include <string.h>
#include <cs50.h>

string uppercase_convert(string s);

int main (void)
{
    string s = get_string("Before: ");
    string converted = uppercase_convert(s);

    printf("After: %s\n", converted);
}

string uppercase_convert(string s)
{
    for(int i = 0 , n = strlen(s); i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
        else
        {
            s[i] = s[i];
        }
    }

    return s;
}
