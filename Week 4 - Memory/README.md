# CS50 Week 4 Notes: Memory

## 📁 Contents
- [RGB & Hexadecimal](#rgb--hexadecimal)
- [Pointers](#pointers)
- [Strings in C](#strings-in-c)
- [Pointer Arithmetic](#pointer-arithmetic)
- [Dynamic Memory: malloc & free](#dynamic-memory-malloc--free)
- [Memory Errors & Valgrind](#memory-errors--valgrind)
- [Buffer Overflows](#buffer-overflows)
- [Using scanf for Input](#using-scanf-for-input)

---

## RGB & Hexadecimal
- **RGB colors** in programming are often represented using hexadecimal notation.
- Hexadecimal uses **base 16**: `0 1 2 3 4 5 6 7 8 9 A B C D E F`
- Each color channel (Red, Green, Blue) ranges from `00` to `FF` in hex, corresponding to `0` to `255` in decimal.
- Example: `#FF5733` means:
  - Red: FF (255)
  - Green: 57 (87)
  - Blue: 33 (51)

---

## Pointers
- A **pointer** is a variable that stores a memory address, usually the address of another variable.
- Syntax:
  - `int *p;` declares a pointer to an integer.
  - `p = &n;` assigns the address of `n` to pointer `p`.
- `*` : Used for two purposes:
  - **Dereferencing**: `*p` gives the value at the address `p` points to.
  - **Declaring**: `int *p;` declares `p` as a pointer to an int.
- `&` : Address-of operator; `&n` gives the address of variable `n`.
- `%p` : Format specifier to print a pointer (memory address).

Example:
```c
int n = 50;
int *p = &n;
printf("%p\n", p); // prints the memory address of n
```

Dereferencing:
```c
printf("%i\n", *p); // prints 50, the value of n
```

---

## Strings in C
- In C, strings are arrays of characters terminated by a null byte `\0`.
- The CS50 library uses a `typedef` to define `string` as:
  ```c
  typedef char *string;
  ```
- Strings are stored as contiguous characters in memory.
- Example:
  ```c
  string s = "HI!"; // equivalent to char *s = "HI!";
  // Stored in memory as: {'H','I','!','\0'}
  ```
- Strings are **mutable** if created with `malloc` or an array, but **immutable** if defined as a string literal.

---

## Pointer Arithmetic
- Pointer arithmetic allows traversing through memory using pointer variables.
- Commonly used with arrays or strings.

Example:
```c
char *s = "HI!";
printf("%c\n", *s);         // H
printf("%c\n", *(s + 1));   // I
printf("%c\n", *(s + 2));   // !
```

Printing substrings:
```c
printf("%s\n", s);       // HI!
printf("%s\n", s + 1);   // I!
printf("%s\n", s + 2);   // !
```

Same as:
```c
printf("%c\n", s[0]); // H
printf("%c\n", s[1]); // I
printf("%c\n", s[2]); // !
```

> ⚠️ Pointer arithmetic must be done cautiously to avoid accessing invalid memory.

---

## Dynamic Memory: malloc & free
- C does not automatically manage memory, so dynamic allocation is necessary for flexible data structures.

### malloc
- `malloc(size)` allocates `size` bytes in memory and returns a pointer to the beginning.
- Use `sizeof(type)` to make allocations more robust:
  ```c
  int *arr = malloc(10 * sizeof(int));
  ```

### Copying Strings
```c
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1); // +1 for null terminator
strcpy(t, s);
```

### Checking for NULL
- Always verify `malloc` didn't fail:
  ```c
  if (t == NULL) {
      return 1;
  }
  ```

### free
- Releases previously allocated memory so it can be reused.
  ```c
  free(t);
  ```

> ⚠️ Never use `free()` on memory not allocated with `malloc()` or after it's already freed.

---

## Memory Errors & Valgrind
- **Valgrind** is a debugging tool to catch memory issues:
  - Memory leaks
  - Use-after-free errors
  - Uninitialized memory usage

Command:
```sh
valgrind ./program_name
```

Sample output:
```
==12345== LEAK SUMMARY:
==12345==    definitely lost: 10 bytes in 1 blocks
==12345==    possibly lost: 0 bytes in 0 blocks
```

Fix issues by ensuring every `malloc` has a corresponding `free`.

---

## Buffer Overflows
- A **buffer overflow** occurs when a program writes more data to a block of memory (buffer) than it's allocated to hold.

### Types:
- **Stack Overflow**:
  - Caused by infinite recursion or too-large stack allocations.
- **Heap Overflow**:
  - Writing past the end of memory allocated by `malloc`.

### Dangers:
- Crashes
- Unpredictable behavior
- Security vulnerabilities

---

## Using scanf for Input

- scanf is a built in function to get input from users.
```c
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
```

> ⚠️ `scanf("%s", ...)` does not prevent buffer overflow unless you limit input size or use safer functions like `fgets()`.
>
> 

Alternative using `fgets()`:
```c
fgets(s, 100, stdin);
```

## File I/O

fopen (Opens a file)
fclose 
fprintf 
fscanf 
fread 
fwrite 
fseek 
