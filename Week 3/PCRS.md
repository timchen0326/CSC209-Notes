## Dynamic Memory Allocation

### Introduction to Dynamic Memory

- Dynamic memory allocation allows programs to request memory from the heap during runtime.
- Key function: `malloc()`
- Example:
    
    ```c
    #include <stdlib.h>
    #include <stdio.h>
    
    int main() {
        int *ptr = (int *)malloc(sizeof(int));
        if (ptr == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }
        *ptr = 42;
        printf("Value stored: %d\n", *ptr);
        free(ptr);
        return 0;
    }
    ```
    
- `malloc` returns a `void*`, meaning it must be cast to the appropriate type.
- Always check if `malloc` returns `NULL`.
- Use `free(ptr)` to deallocate memory and avoid memory leaks.

### Allocating Memory on the Heap

- Allocating an array dynamically:
    
    ```c
    float *rainfall = (float *)malloc(10 * sizeof(float));
    ```
    
- `sizeof(float)` ensures correct memory allocation.
- Always check for successful allocation.

### Freeing Dynamically Allocated Memory

- `free(ptr)` releases allocated memory.
- Example:
    
    ```c
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr != NULL) {
        free(arr);
    }
    ```
    
- Double freeing memory can lead to undefined behavior.

### Memory Leaks

- Occur when allocated memory is not freed.
- Example of a leak:
    
    ```c
    void leak() {
        int *p = (int *)malloc(sizeof(int));
        *p = 5;  // Pointer lost after function ends
    }
    ```
    
- Solution: Always free memory before returning.

## C Memory Model

### Code and Stack Segments

- Local variables are stored in the **stack**.
- Each function call creates a **stack frame**.
- The **code segment** stores executable instructions.

### Heap and Global Segments

- Global variables are stored in the **global segment**.
- Dynamically allocated memory is stored in the **heap**.
- Example:
    
    ```c
    int globalVar;
    void func() {
        static int staticVar;
        int localVar;
        int *heapVar = (int *)malloc(sizeof(int));
    }
    ```
    
    - `globalVar` -> global segment
    - `staticVar` -> global segment
    - `localVar` -> stack
    - `heapVar` -> heap

## Command-Line Arguments

### Converting Strings to Integers

- Use `strtol()` to convert strings to integers safely.
- Example:
    
    ```c
    #include <stdlib.h>
    #include <stdio.h>
    
    int get_sum(const char *input_line) {
        char *end_ptr;
        int first = strtol(input_line, &end_ptr, 10);
        int second = strtol(end_ptr, NULL, 10);
        return first + second;
    }
    ```
    

### Handling Command-Line Arguments

- `argc` represents the number of arguments.
- `argv[]` stores argument values as strings.
- Example:
    
    ```c
    #include <stdio.h>
    int main(int argc, char *argv[]) {
        if (argc < 2) {
            printf("Usage: ./program argument\n");
            return 1;
        }
        printf("First argument: %s\n", argv[1]);
        return 0;
    }
    ```
    
- Running `./program hello` prints `First argument: hello`

## Summary

- Dynamic memory allocation: `malloc()`, `free()`, memory leaks
- Memory model: Stack, Heap, Global, Code segments
- Command-line arguments: `argc`, `argv`, `strtol()`

By mastering these topics, you’ll develop a deeper understanding of memory management and command-line interactions in C.****