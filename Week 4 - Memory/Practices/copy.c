#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: "); // input: hi!
    char *t = s;

    t[0] = toupper(t[0]); // unfortunately it also changes the s string because t[0] is referencing the pointer of same s[0]

    printf("s: %s\n", s); //output: Hi!
    printf("t: %s\n", t); //output: Hi!

}
