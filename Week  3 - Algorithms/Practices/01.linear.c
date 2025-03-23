#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int roll[] = {1, 2, 3, 4, 5, 6, 7};
    int search = get_int("Search roll: ");
    int n = sizeof(roll);

    for (int i = 0; i < n; i++)
    {
        if (roll[i] == search)
        {
            printf("Element found\n");
            return 1;
        }
    }

    printf("Element not found\n");
    return 0;
}
