# CS50 Week 4 Notes

## Table of Contents
1. [RGB & Hexadecimal](#rgb--hexadecimal)
2. [Pointers](#pointers)
3. [Strings](#strings)
4. [Pointer Arithmetic](#pointer-arithmetic)
5. [Dynamic Memory Allocation (malloc & free)](#dynamic-memory-allocation-malloc--free)
6. [Valgrind](#valgrind)
7. [Memory Overflow](#memory-overflow)
8. [scanf](#scanf)
9. [File I/O](#file-io)
10. [Extra](#extra)

---

## RGB & Hexadecimal
- **Hexadecimal**: Base-16 numbering system: `0 1 2 3 4 5 6 7 8 9 a b c d e f`
  - Commonly used in colors (e.g. `#FF0000` for red).

---

## Pointers
- `*` (Asterisk):
  - **Dereferencing**: Access the value at a memory address
  - **Declaration**: Declare a pointer variable
- `&` (Ampersand): Gets the **address** of a variable
- `%p`: Format specifier in `printf` to print memory addresses

```c
int n = 50;
int *p = &n; // p stores the address of n
printf("%p\n", p); // prints address
printf("%i\n", *p); // prints 50 (value at that address)
```

---

## Strings
- **String** is not a native C data type. In CS50, it is defined as:
```c
typedef char *string;
```
- Strings are arrays of characters ending in a null terminator (`\0`)
```c
string s = "HI!";
// Same as:
char *s = "HI!";
// Stored as: {'H','I','!','\0'}
```

---

## Pointer Arithmetic
Pointer arithmetic allows traversal through memory using pointers.

```c
char *s = "HI!";
printf("%c\n", *s);       // H
printf("%c\n", *(s + 1));  // I
printf("%c\n", *(s + 2));  // !
```
Equivalent to:
```c
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
```

You can also print the remaining string:
```c
printf("%s\n", s);      // HI!
printf("%s\n", s + 1);   // I!
```

---

## Dynamic Memory Allocation (malloc & free)
- `malloc(size)` allocates memory of a given size and returns a pointer to the first byte
- `free(pointer)` releases the allocated memory

```c
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1); // +1 for null terminator
if (t != NULL)
{
    strcpy(t, s);
    // Use t...
    free(t); // Always free dynamically allocated memory
}
```
- **NULL** is returned by `malloc` if it fails
- **NUL** (`\0`) is the null terminator character

---

## Valgrind
A tool to check memory leaks and access errors in programs using dynamic memory.

```bash
valgrind ./filename
```

It shows errors like memory leaks, uninitialized memory reads, and improper `free`s.

---

## Memory Overflow
Types of overflow vulnerabilities:
- **Buffer Overflow**: Writing outside allocated memory (e.g., writing past an array)
- **Heap Overflow**: Overflows in dynamically allocated memory
- **Stack Overflow**: Occurs when too much memory is used on the stack (e.g., infinite recursion)

---

## scanf
`scanf()` reads formatted input from the user.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(4);
    if (s == NULL)
    {
        return 1;
    }
    printf("s: ");
    scanf("%s", s); // risk of buffer overflow!
    printf("s: %s\n", s);
    free(s);
    return 0;
}
```
> ⚠️ Be careful: `scanf("%s", ...)` does **not** prevent buffer overflows. Prefer `fgets()` or validate length manually.

---

## File I/O
File I/O lets you read/write files using file pointers and standard functions:

### File Functions
- `fopen()` - Opens a file
- `fclose()` - Closes an open file
- `fprintf()` - Writes formatted data to a file
- `fscanf()` - Reads formatted data from a file
- `fread()` - Reads binary data from a file
- `fwrite()` - Writes binary data to a file
- `fseek()` - Moves the file pointer to a given position

### FILE Type
- `FILE *file;` is a pointer to a file stream

---

## Extra

### fread
```c
fread(buffer, 1, 4, input);
```
- `buffer`: where to store the read data
- `1`: size of each chunk (in bytes)
- `4`: how many chunks
- `input`: file pointer (source)

### fwrite
```c
fwrite(buffer, 1, 4, output);
```
- `buffer`: from where to write
- `1`: size of each chunk (in bytes)
- `4`: how many chunks
- `output`: file pointer (destination)

### File Signature / Magic Numbers
Used to identify file types from their first few bytes:
- PDF: `{0x25, 0x50, 0x44, 0x46}` → `%PDF`

### Fixed-width Integer Types (from `<stdint.h>`)
- `uint8_t`: unsigned 8-bit integer (0–255)
- `int16_t`: signed 16-bit integer (−32,768 to 32,767)

These types are useful for precise memory management and binary file I/O.
