# CS50 Week 1 - Command Line & Data Types

## 📌 CLI Commands (Command Line Interface)

| Command | Description |
|---------|-------------|
| **`cd [directory]`** | Change to the specified directory |
| **`cp [source] [destination]`** | Copy a file from one location to another |
| **`ls`** | List all files and directories in the current folder |
| **`mkdir [directory]`** | Create a new directory (folder) |
| **`mv [source] [destination]`** | Move or rename a file |
| **`rm [file]`** | Delete a file |
| **`rmdir [directory]`** | Remove an empty directory |
| **`clear`** | Clears the terminal screen |
| **`exit`** | Closes the terminal session |

### 🔹 Additional CLI Tips
- Use **`ls -l`** for a detailed list with permissions, size, and modification date.  
- Use **`ls -a`** to show hidden files (those starting with `.`).  
- Use **`rm -r [directory]`** to remove a directory and all its contents.  
- Use **Tab completion** to auto-complete filenames.  
- Use **`pwd`** to print the current directory.  

---

## 🖥️ Data Types in C

| Data Type | Description | Example |
|-----------|------------|---------|
| **`bool`** | Boolean value (`true` or `false`) | `bool isCS50Awesome = true;` |
| **`char`** | Single character (uses single quotes) | `char grade = 'A';` |
| **`int`** | Integer (whole number) | `int age = 24;` |
| **`float`** | Floating point number (less precision) | `float pi = 3.14;` |
| **`double`** | Floating point number (higher precision) | `double precisePi = 3.1415926535;` |
| **`long`** | Large integer values | `long population = 7800000000;` |
| **`string`** | Sequence of characters (uses double quotes) | `string name = "Shoaib";` |

### 🔹 Additional Notes on Data Types
- **`bool`** is included via `#include <stdbool.h>` in C.  
- **`string`** is not a native C type but is available in CS50 via `#include <cs50.h>`.  
- **Use `double` instead of `float`** for more precision in mathematical calculations.  
- **Integer division** in C truncates the decimal part (e.g., `5 / 2` results in `2`).  

---

## 📝 Format Codes for `printf()`

| Format Code | Description | Example |
|-------------|------------|---------|
| **`%c`** | Character | `printf("Grade: %c", grade);` |
| **`%i`** | Integer | `printf("Age: %i", age);` |
| **`%f`** | Floating point number | `printf("Value: %f", pi);` |
| **`%.2f`** | Floating point (2 decimal places) | `printf("Pi: %.2f", pi);` |
| **`%li`** | Long integer | `printf("Population: %li", population);` |
| **`%s`** | String | `printf("Name: %s", name);` |

---

## 🎭 Escape Sequences for Formatting Output

| Escape Sequence | Meaning | Example Output |
|----------------|---------|----------------|
| **`\n`** | Newline | `printf("Hello\nWorld");` → Hello *(new line)* World |
| **`\t`** | Tab (indentation) | `printf("CS50\tis\tfun!");` → CS50   is   fun! |
| **`\\`** | Backslash | `printf("Path: C:\\Users\\Shoaib");` |
| **`\"`** | Double quotes | `printf("\"Hello, World!\"");` → "Hello, World!" |

---

## 🔹 Variables and Constants
- **Declaring Variables**: `int x = 5;`  
- **Using Constants**: `#define PI 3.14159` or `const float PI = 3.14159;`  
- **Variable Scope**: Local variables are declared inside a function and are not accessible outside it.  

---

## 🔹 Operators in C

| Operator | Description | Example |
|----------|------------|---------|
| `+` | Addition | `a + b` |
| `-` | Subtraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` (integer division if both are integers) |
| `%` | Modulus (remainder) | `a % b` |
| `==` | Equal to | `a == b` |
| `!=` | Not equal to | `a != b` |
| `<` | Less than | `a < b` |
| `>` | Greater than | `a > b` |
| `<=` | Less than or equal | `a <= b` |
| `>=` | Greater than or equal | `a >= b` |
| `&&` | Logical AND | `(a > 0 && b > 0)` |
| `||` | Logical OR | `(a > 0 || b > 0)` |
| `!` | Logical NOT | `!(a > 0)` |

---

## 🔹 Control Structures

### `if` Statement
```c
if (x > 0) {
    printf("x is positive\n");
} else {
    printf("x is not positive\n");
}
```

### `for` Loop
```c
for (int i = 0; i < 5; i++) {
    printf("%i\n", i);
}
```

### `while` Loop
```c
int i = 0;
while (i < 5) {
    printf("%i\n", i);
    i++;
}
```

### `do-while` Loop
```c
int i = 0;
do {
    printf("%i\n", i);
    i++;
} while (i < 5);
```

---

This file contains essential notes for **CS50 Week 1** on the **Command Line, Data Types, Operators, and Control Structures in C**. 🚀
