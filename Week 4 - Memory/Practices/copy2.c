#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: "); // input: hi!
    char *t = malloc(strlen(s) + 1); //tells computer to allocate free spaces equal to the length of s and 1 more space for "/0"

    for(int i = 0, n = strlen(t), i <= n, i++)
    {
        t[i] = toupper(t[i]);
    }

    printf("s: %s\n", s); //output: hi!
    printf("t: %s\n", t); //output: HI!

}
