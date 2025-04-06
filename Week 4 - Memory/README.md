### RGB
- Hexadecimal - 0 1 2 3 4 5 6 7 8 9 a b c d e f

## Pointer
- `*` :Instructs the compiler to go to a location in memory
  - Use 1: dereference
  - use 2: declaring
- & :Provides the address of something stored in memory
- %p :allows us to view the address of a location in memory

```c
int n = 50;
int *p = &n;
printf("%p\n", p); //print the memory location of variable n
````

```c
int n = 50;
int *p = &n; //declaring the pointer
printf("%i\n", *p); //print the variable n. here * is dereferencing the p variable
````

## String

String is just a data type created by cs50 library using struct ``` typedef char * string```. String data type doesnt exist in C.
```
HI! => {'H','I','!','/0'}
```

```c
string n = "HI!";
char *n ="HI!";

```

## Pointer Arithmetic
Pointer arithmetic is the ability to do math on locations of memory.

use can write 
```c
char *s = "HI!";
printf("%c\n", *s);
printf("%c\n", *(s + 1));
printf("%c\n", *(s + 2));
```
or
```c
char *s = "HI!";
printf("%s\n", s);
printf("%s\n", s + 1);
printf("%s\n", s + 2);
```
instead of 
```c
char *s = "HI!";
printf("%c\n", s[0]);
printf("%c\n", s[1]);
printf("%c\n", s[2]);
```

## Malloc & Free
- `malloc` allows to allocate a block of a specific size of memory.
- `free` allows you to tell the compiler to free up that block of memory you previously allocated.

```c
char *s = get_string("s: ");
char *t = malloc(strlen(s) + 1);
```
- tells computer to allocate free spaces equal to the length of s and 1 more space for "/0"
- NULL & NUL

```c
free(t);
```
- tells the computer to free up the allocated memory and use it for something else

## Valgrind
- Valgrind is a tool that can check to see if there are memory-related issues with your programs wherein you utilized malloc. Specifically, it checks to see if you free all the memory you allocated.

```sh
valgrind ./filename
```



