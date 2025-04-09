#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(100); // allocate sufficient space
    if (s == NULL)
    {
        return 1;
    }

    printf("s: ");
    scanf("%99s", s); // safer to limit input to 99 characters

    printf("s: %s\n", s);
    free(s);
    return 0;
}
