# CS50 Week 4 Notes – Memory and More

## Table of Contents
- [RGB and Hexadecimal](#rgb-and-hexadecimal)
- [Pointers](#pointers)
- [Strings](#strings)
- [Pointer Arithmetic](#pointer-arithmetic)
- [Memory Allocation: malloc & free](#memory-allocation-malloc--free)
- [Valgrind and Memory Leaks](#valgrind-and-memory-leaks)
- [Overflow](#overflow)
- [scanf](#scanf)
- [File I/O](#file-io)
- [Extra](#extra)

---

## RGB and Hexadecimal
- RGB colors in computing are often represented using hexadecimal notation.
- Hexadecimal is base-16 and uses digits 0–9 and letters a–f:
  ```
  0 1 2 3 4 5 6 7 8 9 a b c d e f
  ```
- Example: `#ff0000` represents red.

---

## Pointers
- A **pointer** is a variable that stores the memory address of another variable.

### Key Symbols:
- `*` (asterisk):
  - **Use 1 – Dereferencing**: Access the value at the pointer's address.
  - **Use 2 – Declaration**: Declares a pointer.
- `&` (ampersand): Retrieves the **address** of a variable.
- `%p`: Format specifier to **print addresses**.

### Example – Print address:
```c
int n = 50;
int *p = &n;
printf("%p\n", p); // memory location of n
```

### Example – Dereferencing:
```c
int n = 50;
int *p = &n;
printf("%i\n", *p); // value of n
```

---

## Strings
- Strings are just arrays of characters ending in a null byte (`\0`).
- CS50 defines `string` as:
  ```c
  typedef char *string;
  ```
- Example:
  ```c
  string n = "HI!";
  char *n = "HI!";  // equivalent
  ```
- Internally:
  ```
  HI! => {'H', 'I', '!', '\0'}
  ```

---

## Pointer Arithmetic
- You can move through arrays with pointer arithmetic:

```c
char *s = "HI!";
printf("%c\n", *s);         // H
printf("%c\n", *(s + 1));   // I
printf("%c\n", *(s + 2));   // !
```

Or print substrings:
```c
printf("%s\n", s);       // HI!
printf("%s\n", s + 1);   // I!
printf("%s\n", s + 2);   // !
```

Alternative syntax:
```c
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
```

---

## Memory Allocation: malloc & free
- `malloc(size)`: Dynamically allocates `size` bytes of memory.
- `free(ptr)`: Frees memory previously allocated with `malloc`.

### Example:
```c
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1); // +1 for '\0'
```
- Always check if `malloc` returns `NULL`.
- Don't forget to free memory:
```c
free(t);
```

### Special terms:
- `NUL` (with one L): The null character `\0`
- `NULL`: A null pointer, indicating no address

---

## Valgrind and Memory Leaks
- **Valgrind** detects memory leaks, improper frees, and invalid reads/writes.

```sh
valgrind ./filename
```

---

## Overflow
- **Buffer Overflow**: Writing beyond array bounds in memory.
- **Stack Overflow**: Too much function recursion.
- **Heap Overflow**: Writing past the end of dynamically allocated memory.
- These can lead to bugs and security vulnerabilities.

---

## scanf
- `scanf` is a standard C function to take input.

### Example:
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
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
    return 0;
}
```
> ⚠️ **Warning**: `scanf("%s", ...)` is dangerous if buffer size is unknown or small. Prefer `fgets()` for safety.

---

## File I/O
- File operations in C use the `FILE` data type and related functions.

### Functions:
- `fopen(filename, mode)`: Opens a file for reading/writing.
- `fclose(file)`: Closes a file.
- `fprintf(file, ...)`: Prints to a file.
- `fscanf(file, ...)`: Reads from a file.
- `fread(ptr, size, count, file)`: Reads `count` items of `size` bytes each into `ptr` from `file`.
- `fwrite(ptr, size, count, file)`: Writes `count` items of `size` bytes each from `ptr` to `file`.
- `fseek(file, offset, origin)`: Moves the file pointer.

### `FILE` Data Type
- Represents an open file stream.

---

## Extra

### `fread` Example:
```c
fread(buffer, 1, 4, input);
```
- `buffer`: Where to store data
- `1`: Size of each element in bytes
- `4`: Number of elements to read
- `input`: The file stream to read from

### `fwrite` Example:
```c
fwrite(buffer, 1, 4, output);
```
- `buffer`: Where to read data from
- `1`: Size of each element
- `4`: Number of elements to write
- `output`: File stream to write to

### Identifying File Type by Signature (Magic Numbers)
- Some files can be identified by the first few bytes:
  ```c
  // PDF Signature:
  {0x25, 0x50, 0x44, 0x46}; // %PDF
  ```

### `uint8_t`
- Defined in `<stdint.h>`
- An unsigned 8-bit integer type (values from 0 to 255)
- Commonly used when dealing with binary file data (e.g., byte buffers)

---

## Visual Diagrams

### Pointers and Memory Addresses
```
int n = 50;
int *p = &n;

   n      p
+-----+ +-----+
|  50 | | addr of n |
+-----+ +-----+
   ^        |
   |________|
```

### String in Memory
```
string s = "HI!";

Memory Representation:
+-----+-----+-----+-----+
| 'H' | 'I' | '!' | '
