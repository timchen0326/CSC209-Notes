## Header Files in C

### What Are Header Files?

- Header files (`.h` files) store function **declarations**, macro definitions, and structure definitions.
- They allow multiple C files to share the same declarations, avoiding redundancy and promoting modularity.

### Why Use Header Files?

1. **Code Organization**: Separate interface (header file) from implementation.
2. **Reusability**: Functions can be shared across multiple source files.
3. **Encapsulation**: Users only see function declarations, not their internal workings.

### Creating and Using a Header File

4. Create a header file `myheader.h`:
    
    ```c
    #ifndef MYHEADER_H
    #define MYHEADER_H
    
    void greet();
    
    #endif // MYHEADER_H
    ```
    
5. Create `myheader.c` (Implementation File):
    
    ```c
    #include <stdio.h>
    #include "myheader.h"
    
    void greet() {
        printf("Hello, CSC209!\n");
    }
    ```
    
6. Create `main.c` to use the header file:
    
    ```c
    #include "myheader.h"
    
    int main() {
        greet();
        return 0;
    }
    ```
    
7. Compile:
    
    ```sh
    gcc -c myheader.c
    gcc -c main.c
    gcc -o myprogram myheader.o main.o
    ```
    

### `#ifndef`, `#define`, and `#endif`

- These are **include guards** that prevent multiple inclusions of the same header file.

---

## Make and Makefiles

### What is `make`?

- `make` automates the process of **compiling and linking C programs**.
- It **tracks dependencies** and only recompiles necessary files.

### Writing a Simple Makefile

#### Example `Makefile`:

```makefile
CC = gcc
CFLAGS = -Wall -g

all: myprogram

myprogram: main.o myheader.o
	$(CC) $(CFLAGS) -o myprogram main.o myheader.o

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o myprogram
```

### Makefile Syntax

|Symbol|Meaning|
|---|---|
|`$@`|Target name|
|`$<`|First prerequisite|
|`$^`|All prerequisites|
|`%.o: %.c`|Pattern rule to compile `.c` files to `.o` files|

### Running `make`

```sh
make    # Builds the target specified under `all:`
make clean    # Removes compiled files
```

---

## System Calls

### What Are System Calls?

- **System calls** are functions provided by the **OS kernel** that allow user-space programs to request services.
- Examples: `open()`, `read()`, `write()`, `close()`, `fork()`, `exec()`, `wait()`.

### Example: File I/O System Calls

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        return 1;
    }
    
    write(STDOUT_FILENO, buffer, bytesRead);
    close(fd);
    return 0;
}
```

### Error Handling with `errno`

- System calls return `-1` on failure and set `errno`.
- Use `perror()` or `strerror(errno)` to print the error message.

---

## Function Pointers

### What Are Function Pointers?

- Function pointers store addresses of functions.
- Useful for **callback functions** and **dynamic function execution**.

### Declaring a Function Pointer

```c
int (*func_ptr)(int, int);
```

### Assigning a Function to a Pointer

```c
int add(int a, int b) {
    return a + b;
}

int main() {
    int (*func_ptr)(int, int) = add;
    printf("Sum: %d\n", func_ptr(3, 4));
    return 0;
}
```

### Function Pointers as Arguments

```c
#include <stdio.h>

int multiply(int a, int b) {
    return a * b;
}

void compute(int (*operation)(int, int), int x, int y) {
    printf("Result: %d\n", operation(x, y));
}

int main() {
    compute(multiply, 5, 6);
    return 0;
}
```

### Function Pointers and `qsort`

- `qsort()` uses function pointers for sorting custom types.

```c
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    qsort(arr, 5, sizeof(int), compare);
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
```

---

## Summary

|Topic|Key Points|
|---|---|
|**Header Files**|Store function declarations, prevent redundancy|
|**Make & Makefiles**|Automate compilation, track dependencies|
|**System Calls**|Low-level OS functions like `read()`, `write()`, `fork()`|
|**Function Pointers**|Enable dynamic function execution, used in `qsort()`|

---

These notes cover everything you need for **Week 6**. Happy studying! 🚀