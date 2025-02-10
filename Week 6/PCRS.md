## Table of Contents

- [The C Preprocessor](https://chatgpt.com/g/g-6730fa9e0158819093dfb99251b8c53b-csc209-week-3/c/67aa29d8-987c-800a-9c94-f1b369c6b69f#the-c-preprocessor)
- [System Calls](https://chatgpt.com/g/g-6730fa9e0158819093dfb99251b8c53b-csc209-week-3/c/67aa29d8-987c-800a-9c94-f1b369c6b69f#system-calls)
- [Errors and Errno](https://chatgpt.com/g/g-6730fa9e0158819093dfb99251b8c53b-csc209-week-3/c/67aa29d8-987c-800a-9c94-f1b369c6b69f#errors-and-errno)
- [Useful C Features](https://chatgpt.com/g/g-6730fa9e0158819093dfb99251b8c53b-csc209-week-3/c/67aa29d8-987c-800a-9c94-f1b369c6b69f#useful-c-features)

---

## The C Preprocessor

### Simple Macros and Header Files

- The **C Preprocessor** modifies source code before compilation.
- Macros are defined using `#define`.
    - Example:
        
        ```c
        #define PI 3.14159
        ```
        
- Header files (`.h` files) store function declarations and macro definitions.

### Compilation with Macros

- The `-D` option defines macros at compile-time.
    - Example:
        
        ```sh
        gcc -DMACRO=5 question1.c -o a.out
        ```
        
- This ensures the `#ifdef` directive can check if a macro is defined.

### Function-like Macros

- Macros can take parameters:
    
    ```c
    #define SUPERVISOR(regular) (regular + 5)
    ```
    
- Be cautious with operator precedence:
    
    ```c
    int pay = hours_worked * SUPERVISOR(regular_pay);
    ```
    
    - Expected output: `pay is 205`
    - Corrected macro: `#define SUPERVISOR(regular) ((regular) + 5)`

---

## System Calls

### What is a System Call?

- System calls allow programs to request services from the OS.
- Examples of system calls:
    - `read()`, `write()`, `exit()`
- Library functions (not system calls):
    - `fgets()`, `fopen()`, `printf()`, `scanf()`
- Library calls wrap system calls to provide easier interfaces.

---

## Errors and Errno

### When System Calls Fail

- System calls may fail due to external factors (e.g., missing files, permissions).
- **Error Handling:**
    - System calls return error values (`NULL`, `-1`, or `0`).
    - `errno` is set globally on failure.
    - Use `perror()` to print error messages.
- Example of checking `fopen()`:
    
    ```c
    FILE *fp = fopen("file.txt", "r");
    if (!fp) {
        perror("Error opening file");
    }
    ```
    

### Checking for Errors

- Always validate return values from system calls.
- Example: Checking `malloc()` return value:
    
    ```c
    int *ptr = malloc(sizeof(int) * 10);
    if (!ptr) {
        perror("malloc failed");
    }
    ```
    

---

## Useful C Features

### `typedef`

- Creates aliases for existing types.
- Example:
    
    ```c
    typedef unsigned int uint;
    uint x = 10;
    ```
    
- **Common Use:** Structs
    
    ```c
    typedef struct {
        int id;
        char name[50];
    } Student;
    ```
    

### Macros

- Used to define constants and simple functions.
- Correct macro format:
    
    ```c
    #define CLASS_SIZE 80
    #define WITH_TAX(x) ((x) * 1.08)
    ```
    
- Avoid incorrect macros like:
    
    ```c
    #define CLASS_SIZE = 80;
    #define WITH_TAX(x) (x) * 1.08
    ```
    
    - Parentheses prevent precedence issues.

---

## Summary

1. **Preprocessor Directives**: Use `#define` for macros and `#include` for headers.
2. **System Calls**: Understand the difference between system calls and library functions.
3. **Error Handling**: Check return values, use `errno`, and call `perror()`.
4. **Typedef and Macros**: Simplify code readability and ensure correct syntax.

---

This structured document provides a comprehensive review of the key topics needed for your term test. Happy studying! 🎯