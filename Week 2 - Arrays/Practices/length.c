#include <stdio.h>
#include <cs50.h>

int string_length(string name);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);

    printf("The length of your name is %i\n", length);
}

int string_length(string name)
{
    int n = 0;
    while(name[n] != '\0')
    {
        n++;
    }
    return n;
}
