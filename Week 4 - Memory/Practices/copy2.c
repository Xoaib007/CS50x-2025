#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // to use malloc

int main(void)
{
    // Get two strings
    char *s = get_string("s: "); // input: hi!
    char *t = malloc(strlen(s) + 1); //tells computer to allocate free spaces equal to the length of s and 1 more space for "/0"
    if(t == NULL)
    {
        return 0;
    } // return if malloc allocates memory

    for(int i = 0, n = strlen(t), i <= n, i++)
    {
        t[i] = s[i];
    } // copy the s string

    if(strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    } // capitalize the copied string only if the string exists

    printf("s: %s\n", s); //output: Hi!
    printf("t: %s\n", t); //output: Hi!

}
