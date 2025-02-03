# CSC209 - Lab 3 Study Notes

## **Dynamic Memory Allocation in C**

### **Introduction**

The primary objective of Lab 3 is to practice using pointers and dynamic memory allocation in C while also learning to use Valgrind for memory leak detection.

---

## **Key Concepts Covered**

1. **Dynamic Memory Allocation**
2. **Pointers and Arrays**
3. **Memory Management with `malloc` and `free`**
4. **Valgrind for Memory Leak Detection**
5. **Working with Command-Line Arguments**

---

## **1. Dynamic Memory Allocation in C**

Dynamic memory allocation allows memory to be allocated at runtime instead of compile time. In C, the primary functions for dynamic memory management are:

- `malloc(size_t size)`: Allocates memory of the specified size and returns a pointer to it.
- `free(void *ptr)`: Deallocates the memory that was previously allocated using `malloc`.
- `sizeof(type)`: Returns the size (in bytes) of a given data type or variable.

### **Example:**

```c
int *ptr = (int *)malloc(10 * sizeof(int));
if (ptr == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
}
// Use allocated memory
free(ptr);
```

---

## **2. Fibonacci Sequence with Dynamic Arrays**

The `fibonacci.c` program generates the first `n` Fibonacci numbers using dynamic memory allocation.

### **Key Implementation Details:**

- The function `fib(int **fib_sequence, int n)` dynamically allocates an array of size `n` and computes Fibonacci numbers.
- The function stores results in an integer array that is dynamically allocated.
- Memory is freed at the end to prevent leaks.

### **Code Implementation:**

```c
void fib(int **fib_sequence, int n) {
    *fib_sequence = (int *)malloc(n * sizeof(int));
    if (*fib_sequence == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    if (n > 0) (*fib_sequence)[0] = 0;
    if (n > 1) (*fib_sequence)[1] = 1;
    for (int i = 2; i < n; i++) {
        (*fib_sequence)[i] = (*fib_sequence)[i - 1] + (*fib_sequence)[i - 2];
    }
}
```

### **Memory Management:**

- Memory is allocated using `malloc()`.
- If allocation fails, the program prints an error and exits.
- Memory is deallocated using `free()`.

---

## **3. Splitting an Array into Even and Odd Indices**

The `split_array.c` program splits an input array into two dynamically allocated arrays: one containing values at even indices and the other at odd indices.

### **Key Implementation Details:**

- The function `split_array` creates two separate arrays.
- The function `build_array` converts command-line arguments into an integer array.
- The program dynamically allocates memory only as needed, ensuring efficient use of memory.

### **Code Implementation:**

```c
int **split_array(const int *s, int length) {
    int even_count = (length + 1) / 2;
    int odd_count = length / 2;

    int **result = (int **)malloc(2 * sizeof(int *));
    result[0] = (int *)malloc(even_count * sizeof(int));
    result[1] = (int *)malloc(odd_count * sizeof(int));

    int even_index = 0, odd_index = 0;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            result[0][even_index++] = s[i];
        } else {
            result[1][odd_index++] = s[i];
        }
    }

    return result;
}
```

### **Memory Management:**

- Memory is allocated for two arrays.
- Proper deallocation is performed using `free()` to prevent leaks.

---

## **4. Using Valgrind for Memory Leak Detection**

### **What is Valgrind?**

Valgrind is a tool used to detect memory management issues such as:

- Memory leaks (forgetting to `free` allocated memory).
- Use of uninitialized memory.
- Invalid memory access.

### **Running Valgrind:**

```sh
valgrind ./split_array 1 2 3
```

### **Expected Output (No Memory Leaks):**

```
== Memcheck, a memory error detector ==
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
    total heap usage: 5 allocs, 5 frees, 1,064 bytes allocated
All heap blocks were freed -- no leaks are possible
ERROR SUMMARY: 0 errors from 0 contexts
```

If there is a memory leak, Valgrind will display an error message indicating where memory was not freed.

---

## **5. Handling Command-Line Arguments in C**

Command-line arguments allow programs to take user input via terminal commands. The `main` function receives arguments via `argc` (argument count) and `argv` (argument vector).

### **Example:**

```c
int main(int argc, char **argv) {
    int count = strtol(argv[1], NULL, 10);
    int *fib_sequence;
    fib(&fib_sequence, count);
    for (int i = 0; i < count; i++) {
        printf("%d ", fib_sequence[i]);
    }
    free(fib_sequence);
    return 0;
}
```

### **Key Points:**

- `argv[0]` contains the program name.
- `argv[1]` and beyond contain user-provided values.
- Use `strtol` to convert string arguments into integers.

---

## **Conclusion**

Lab 3 focuses on:

- Mastering **dynamic memory allocation** in C.
- Using **pointers and arrays** effectively.
- Understanding **proper memory management** to prevent leaks.
- Practicing **command-line argument handling**.
- Running **Valgrind** to detect memory issues.

Mastering these concepts is essential for efficient memory use and avoiding segmentation faults or memory leaks in real-world applications.