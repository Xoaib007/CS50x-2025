## Time complexity

- Running time, O(n) where n represents the size of the problem.
- Best case scenerio, Ω(n) uses for calculate the time complexity of best case scenerio
- Θ(n) uses when best case scenerio and worst case scenerio are same
- asymptotic notation

## Algorithms

### Linear search

```pseudo
For each door from left to right
  If 50 is behind door
    Return true
Return false
```

- O(n)
- Ω(1)

[Example 1](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%20%203%20-%20Algorithms/Practices/01.linear.c) | 
[Example 2](https://github.com/Xoaib007/CS50x-2025/blob/main/Week%20%203%20-%20Algorithms/Practices/02.linear-v2.c)

### Binary search

```pseudo
If no door left
  Return false
If 50 is behind doors[middle]
  Return true
Else if 50 < doors[middle]
  Search doors[0] through doors[middle - 1] //left half
Else if 50 > doors[middle]
  Search doors[middle + 1] through doors[n - 1] //right half
```

- need to make sure the elements are sorted
- O(log n)
- Ω(1)

## Data type structure

- typedef struct allows to create new data type according to need
- need to define the structure before the main function
```c
typedef struct
{
    string name;
    string number;
    string email;
} person;
```
- use the name of the structure as a data type like int or string
```c
person people[] = {
        {"John", "39-3486925084", "john@email.com"},
        {"David","39-3486925085", "david@email.com" },
        {"Muller", "39-3486925086","muller@email.com" }
};
```
