# 📑 Table of Contents

1. [⏳ Time Complexity](#time-complexity)
   - Big-O, Big-Omega, and Big-Theta Notation
   - Common Time Complexities
2. [🔍 Searching Algorithms](#searching-algorithms)
   - Linear Search
   - Binary Search
3. [📊 Sorting Algorithms](#sorting-algorithms)
   - Selection Sort
   - Bubble Sort
   - Merge Sort
4. [Data Structures](#data-structures)
   - Structs in C
5. [Recursion](#recursion)
   - What is Recursion?
   - Example: Factorial using Recursion
   - Recursion vs Iteration
6. [Additional Notes](#additional-notes)
   - Asymptotic Analysis
   - Divide and Conquer Strategies
   - Sorting impacts Searching


# Time Complexity

Time complexity measures the efficiency of an algorithm based on input size (n). It describes how the runtime grows as the input size increases.

- **Big-O Notation (O)**: Upper bound on the running time (worst case scenario).
- **Big-Omega Notation (Ω)**: Lower bound on the running time (best case scenario).
- **Big-Theta Notation (Θ)**: Tight bound when best and worst case runtimes are the same.

### Common Time Complexities:
- **O(n²)** – Slowest (e.g., selection sort, bubble sort)
- **O(n log n)** – Faster than O(n²) (e.g., merge sort, quicksort)
- **O(n)** – Linear time (e.g., linear search)
- **O(log n)** – Logarithmic time (e.g., binary search)
- **O(1)** – Fastest, constant time (e.g., accessing an array index)

---

# Algorithms

## Searching Algorithms

### **Linear Search**
A simple searching algorithm that checks each element one by one until the desired value is found.

```pseudo
For each element in the list
    If element matches the target
        Return true
Return false
```
- **Time Complexity**: O(n) (worst case), Ω(1) (best case)

[Example 1](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%203%20-%20Algorithms/Practices/01.linear.c) |
[Example 2](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%203%20-%20Algorithms/Practices/02.linear-v2.c)

### **Binary Search**
Efficient searching algorithm that works on sorted arrays by repeatedly dividing the search range in half.

```pseudo
If list is empty
    Return false
If middle element is target
    Return true
If target is smaller than middle element
    Search left half
Else
    Search right half
```
- **Time Complexity**: O(log n) (worst case), Ω(1) (best case)
- **Requirement**: List must be sorted

---

## Sorting Algorithms

### **Selection Sort**
Finds the smallest element and swaps it with the first unsorted position.

```pseudo
For i from 0 to n–1
    Find the smallest element in remaining array
    Swap with element at index i
```
- **Time Complexity**: O(n²) (worst, best, and average case)

### **Bubble Sort**
Repeatedly swaps adjacent elements if they are in the wrong order.

```pseudo
Repeat n-1 times
    For i from 0 to n–2
        If numbers[i] > numbers[i+1]
            Swap them
    If no swaps in a full pass
        Quit
```
- **Time Complexity**: O(n²) (worst case), Ω(n) (best case if already sorted)

### **Merge Sort**
A divide-and-conquer algorithm that recursively splits an array into halves, sorts them, and merges them back.

```pseudo
If array has only one element
    Return
Sort left half
Sort right half
Merge sorted halves
```
- **Time Complexity**: O(n log n) (worst, best, and average case)

---

## Data Structures

### **Structs in C**
A `struct` allows grouping multiple variables under a single data type.

```c
typedef struct {
    string name;
    string number;
    string email;
} person;
```
**Usage:**
```c
person people[] = {
    {"John", "39-3486925084", "john@email.com"},
    {"David", "39-3486925085", "david@email.com"},
    {"Muller", "39-3486925086", "muller@email.com"}
};
```
[Example](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%203%20-%20Algorithms/Practices/03.phonebook.c)

---

## Recursion

### **What is Recursion?**
Recursion is a technique where a function calls itself until a base condition is met.

### **Example: Factorial using Recursion**
```pseudo
Function factorial(n)
    If n == 0
        Return 1
    Else
        Return n * factorial(n-1)
```

### **Recursion vs Iteration**
- **Recursion** is often more elegant but can be inefficient due to function call overhead.
- **Iteration** is usually more efficient in terms of memory and execution speed.

[Example](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%203%20-%20Algorithms/Practices/04.iteration.c)

---

## Additional Notes
- **Asymptotic Analysis** helps compare algorithm efficiency independently of hardware and programming language.
- **Divide and Conquer** strategies (like Merge Sort) break problems into smaller subproblems, solve them recursively, and combine the results efficiently.
- **Sorting impacts Searching**: A sorted array allows more efficient searching (e.g., Binary Search vs. Linear Search).

