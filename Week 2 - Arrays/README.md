# 🚀 CS50 Week 2 Notes

## 🛠️ **Compiling & CLI Arguments**

### 📌 **Compiling a C Program**
Instead of using `make`, you can compile your program manually using `clang`:
```sh
clang -o hello hello.c
```
✅ More efficient than `make hello` as it skips some automated steps.

To compile with an external library (e.g., CS50 Library), use:
```sh
clang -o hello hello.c -lcs50
```
🔹 *Standard C libraries (e.g., `math.h`, `stdio.h`) are included by default.*

### 🏗 **Compilation Steps**
1️⃣ **Preprocessing** - Handles `#include`, `#define`, and macros.  
2️⃣ **Compiling** - Translates C code into assembly language.  
3️⃣ **Assembling** - Converts assembly into machine code (binary).  
4️⃣ **Linking** - Combines object files and libraries into an executable.  

---

## 🐞 **Debugging Techniques**

### ✅ **Using `printf()`**
Insert print statements to track variable values and execution flow.

### 🛠 **Using `debugger50` (or `gdb` manually)**
🔍 Step through your code for debugging:
```sh
debugger50 ./hello
```
Or manually with GDB:
```sh
gdb ./hello
break main
run
```

---

## 🔢 **Command-Line Arguments**

### **C programs can accept command-line arguments:**
```c
int main(int argc, string argv[])
```
📌 `argc` (**argument count**) – Number of command-line arguments.  
📌 `argv[]` (**argument vector**) – An array of strings containing arguments.

Example:
```sh
./hello Alice
```
📝 Inside the program:
- `argc` is `2`
- `argv[0]` is `"./hello"`
- `argv[1]` is `"Alice"`

### ❗ **Checking for Arguments**
To prevent errors when expecting arguments:
```c
if (argc != 2) {
    printf("Usage: ./hello <name>\n");
    return 1;
}
printf("Hello, %s!\n", argv[1]);
```

---

## 📚 **Arrays in C**

### 📌 **Basics of Arrays**
- Arrays store multiple values of the same type.
- Declared with a fixed size:
  ```c
  int scores[5] = {90, 85, 78, 92, 88};
  ```
- Access elements using indices (`scores[0]`, `scores[1]`, etc.).

### 🔄 **Looping through an Array**
```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", scores[i]);
}
```

---

## 🔤 **Strings in C**

📌 Strings are **arrays of characters** ending with a null character (`\0`).  
📌 `string` in CS50 is an alias for `char*` (pointer to a character array).  

Example:
```c
string name = "Alice";  // Equivalent to char name[] = { 'A', 'l', 'i', 'c', 'e', '\0' };
printf("%s", name);
```

### 🔄 **Looping through a String**
```c
for (int i = 0; name[i] != '\0'; i++) {
    printf("%c\n", name[i]);
}
```

### 🛠 **Common Functions for Strings (`string.h`)**
```c
strlen(s)       // Get string length
strcmp(s1, s2)  // Compare two strings
strcpy(dest, src)  // Copy one string into another
strcat(dest, src)  // Concatenate two strings
```

### ❗ **Using `strcmp()` to Compare Strings**
Use `strcmp()` instead of `==` to compare strings:
```c
if (strcmp(argv[1], "hello") == 0) {
    printf("You said hello!\n");
}
```

---

## 🧠 **Memory & Pointers (Intro)**

📌 Variables are stored in memory with specific addresses.  
📌 The **`&` operator** gets the memory address of a variable.  
📌 The **`*` operator** (dereference) accesses the value stored at a pointer.

Example:
```c
int n = 5;
int *p = &n;  // Pointer to n
printf("%d\n", *p);  // Prints 5
```

---

## 🎯 **Best Practices for C Programming**

✔ Always initialize variables before using them.  
✔ Use comments to explain complex logic.  
✔ Check for null pointers before accessing memory.  
✔ Free dynamically allocated memory (`free()`) to prevent memory leaks.  
✔ Use `valgrind` to detect memory errors:
```sh
valgrind ./hello
```

---

📌 **This concludes the key concepts from Week 2 of CS50.**  
📚 Mastering these will set a strong foundation for deeper topics like memory management and data structures in later weeks! 🚀

