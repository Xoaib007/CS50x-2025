### RGB
- Hexadecimal - 0 1 2 3 4 5 6 7 8 9 a b c d e f

## Pointer
- `*`
  - Use 1: dereference
  - use 2: declaring
- &
- %p

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
