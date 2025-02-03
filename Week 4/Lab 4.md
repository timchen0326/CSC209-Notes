# CSC209 Lab 4 Study Notes

## **Introduction**

Lab 4 focuses on string manipulation in C, reinforcing fundamental concepts such as:

- String comparison
- String truncation
- String modification
- Proper memory management with string operations

This lab provides a hands-on approach to understanding how C handles strings, character arrays, and memory boundaries.

---

## **1. String Comparison (compare.c)**

### **Concepts Covered:**

- Using `strcmp()` to compare two strings
- Handling command-line arguments
- Validating input arguments

### **Code Summary:**

The `compare.c` program takes two arguments and prints:

- `"Same\n"` if the strings are identical.
- `"Different\n"` if they differ.
- `"Invalid\n"` if the number of arguments is incorrect.

#### **Key Implementation:**

```c
if (argc != 3) {
    printf("Invalid\n");
} else if (strcmp(argv[1], argv[2]) == 0) {
    printf("Same\n");
} else {
    printf("Different\n");
}
```

**Key Takeaway:** Always validate input before performing operations.

---

## **2. String Truncation (truncate.c)**

### **Concepts Covered:**

- Using `strlen()` to determine string length
- Modifying strings in-place
- Handling truncation safely

### **Code Summary:**

The `truncate.c` program takes a string and an integer `n`. If the string is longer than `n`, it truncates it and returns the number of characters removed.

#### **Key Implementation:**

```c
int truncate(char *s, int n) {
    int len = strlen(s);
    if (len > n) {
        s[n] = '\0';
        return len - n;
    }
    return 0;
}
```

**Key Takeaway:** Ensure null termination (`'\0'`) when modifying strings.

---

## **3. Removing Trailing Question Marks (strip.c)**

### **Concepts Covered:**

- String traversal
- Modifying strings in-place
- Counting removed characters

### **Code Summary:**

The `strip.c` program removes trailing question marks (`?`) from a string and returns the number removed.

#### **Key Implementation:**

```c
int strip_q_marks(char *s) {
    int count = 0;
    int len = strlen(s);
    while (len > 0 && s[len - 1] == '?') {
        s[--len] = '\0';
        count++;
    }
    return count;
}
```

**Key Takeaway:** When modifying a string in-place, update its length accordingly.

---

## **4. Constructing a Personalized Greeting (greeting.c)**

### **Concepts Covered:**

- Copying strings safely with `strncpy()`
- Concatenating strings safely with `strncat()`
- Managing buffer size constraints

### **Code Summary:**

The `greeting.c` program takes a greeting message and a name, then creates a personalized greeting. If space is insufficient, truncation ensures a valid string.

#### **Key Implementation:**

```c
strncpy(greeting, argv[1], sizeof(greeting) - 1);
greeting[sizeof(greeting) - 1] = '\0';
strncat(greeting, " ", sizeof(greeting) - strlen(greeting) - 1);
strncat(greeting, name, sizeof(greeting) - strlen(greeting) - 1);
```

**Key Takeaway:** Always ensure proper null termination when copying or concatenating strings.

---

## **General Takeaways**

1. **Memory Safety:** Strings in C do not have automatic bounds checking, so use functions like `strncpy()` and `strncat()` to avoid buffer overflows.
2. **Command-line Arguments:** Validate user input before processing to prevent segmentation faults.
3. **String Modification:** Always ensure strings remain properly null-terminated (`'\0'`).
4. **Debugging Tip:** Use `printf()` to print intermediate string states when debugging.

---

### **Preparation Tips for the Exam:**

- **Understand the purpose of each function** in `string.h` (e.g., `strcmp`, `strlen`, `strncpy`, `strncat`).
- **Write small test cases** to verify expected behaviors (especially for edge cases like empty strings or maximum-length inputs).
- **Practice modifying strings in-place** to reinforce memory management concepts.
- **Review lab exercises** and **reimplement functions from scratch** to ensure mastery.

---

### **Useful References:**

- [C String Library](https://en.cppreference.com/w/c/string)
- [Memory Management in C](https://www.cprogramming.com/tutorial/c/lesson6.html)

---

This concludes the study notes for Lab 4. Happy studying and good luck on your term test! 🎯