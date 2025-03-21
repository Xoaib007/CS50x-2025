// This program prompts the user for their name and then greets them.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt the user for their name
    string name = get_string("What's your name, buddy?");
    
    // Print a greeting message
    printf("Hello, %s\n", name);
}
