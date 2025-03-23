#include <stdio.h>
#include <cs50.h>

int search(int array[], int n, int x);

int main() {
  int array[] = {2, 4, 0, 1, 9};
  int x = get_int("Search: ");
  int n = sizeof(array) / sizeof(array[0]);

  int result = search(array, n, x);

  (result == -1) ? printf("Element not found\n") : printf("Element found at position: %d\n", result);
}

int search(int array[], int n, int x)
{
  // Going through array sequencially
  for (int i = 0; i < n; i++)
    if (array[i] == x)
      return i + 1;
  return -1;
}
