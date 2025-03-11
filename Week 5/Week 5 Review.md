## Introduction to Streams in C

### What Are Streams?

- **Streams** are a way for programs to read and write data in a sequential manner.
- In C, streams are represented as `FILE *` (a pointer to a file structure).
- Every C program has three standard streams:
    - `stdin` - Standard input (keyboard input by default)
    - `stdout` - Standard output (screen output by default)
    - `stderr` - Standard error (error messages printed to the screen)
- Streams keep track of the file position, meaning they remember where the next read/write operation should take place.

### Opening Files in C

To work with files, we need to **open** them first. This is done using the `fopen` function:

```c
FILE *fopen(const char *pathname, const char *mode);
```

- `pathname`: The name of the file to be opened.
- `mode`: Specifies how the file should be opened (read, write, append, etc.).

### File Opening Modes Explained

|Mode|If File Exists|If File Doesn't Exist|Can Read?|Can Write?|
|---|---|---|---|---|
|`r`|Opens from the beginning|Error|Yes|No|
|`w`|Erases contents|Creates new file|No|Yes|
|`a`|Opens at end|Creates new file|No|Yes|
|`r+`|Opens from the beginning|Error|Yes|Yes|
|`w+`|Erases contents|Creates new file|Yes|Yes|
|`a+`|Opens at end|Creates new file|Yes|Yes|

**Note:** On Windows, `rb`, `wb`, `ab` modes help with line-ending differences but are unnecessary on Unix/Linux.

### Reading from Files

There are multiple ways to read data from files in C:

1. **Formatted Read (for structured input)**:
    
    ```c
    int fscanf(FILE *stream, const char *format, ...);
    ```
    
    Reads formatted data just like `scanf`, but from a file.
    
2. **Read a Line of Text**:
    
    ```c
    char *fgets(char *s, int size, FILE *stream);
    ```
    
    Reads a full line (up to `size` characters) into `s`.
    
3. **Read Binary Data**:
    
    ```c
    size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    ```
    
    Reads `nmemb` items of `size` bytes each into `ptr`.
    

### Writing to Files

Similar to reading, we have multiple functions for writing:

4. **Formatted Write**:
    
    ```c
    int fprintf(FILE *stream, const char *format, ...);
    ```
    
    Writes formatted text to a file.
    
5. **Write a Line of Text**:
    
    ```c
    int fputs(const char *s, FILE *stream);
    ```
    
    Writes a string to a file.
    
6. **Write Binary Data**:
    
    ```c
    size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
    ```
    
    Writes `nmemb` items of `size` bytes each from `ptr` to the file.
    

### Moving Around in a File

- **Seek to a specific location**:
    
    ```c
    int fseek(FILE *stream, long offset, int whence);
    ```
    
    Moves the cursor by `offset` bytes:
    
    - `SEEK_SET`: Start of file
    - `SEEK_CUR`: Current position
    - `SEEK_END`: End of file
- **Rewind to the beginning**:
    
    ```c
    void rewind(FILE *stream);
    ```
    
- **Close a file**:
    
    ```c
    int fclose(FILE *stream);
    ```
    
    Always close a file after use to free system resources.
    

### Viewing Binary Files

- `od` (octal dump) shows the content of a file in different formats:
    
    ```sh
    od -A d -t x1 file.bin
    ```
    
- `xxd` is another tool for viewing binary data:
    
    ```sh
    xxd -b file.bin
    ```
    

### Buffering

- **What is buffering?**
    - When writing data, it may be temporarily stored in memory before being written to disk.
    - This improves performance but can cause data loss in a crash.
- **Types of buffering:**
    - `stdin`: Line buffered
    - `stdout`: Line buffered (block buffered if redirected to a file)
    - `stderr`: Unbuffered (ensures error messages are printed immediately)

## File I/O and Structs (Lab 5)

### What is a Bitmap File?

- A **24-bit bitmap file** consists of:
    1. **File metadata**: Information about the image, including width, height, and where pixel data starts.
    2. **Pixel array**: Stores pixel color values in Blue-Green-Red (BGR) format.

### Important Byte Offsets

|Offset|Meaning|
|---|---|
|10-13|Pixel array start|
|18-21|Image width (pixels)|
|22-25|Image height (pixels)|

### How to Read Bitmap Metadata

7. Use `fseek` to navigate to the required byte offsets.
8. Read the values using `fread`.

### How to Read Pixels

- Each pixel = **3 bytes** (BGR format).
- Store pixels as `unsigned char` since they are between 0-255.

### Cleaning Up

- Close files with `fclose()`.
- Free dynamically allocated memory.

## Low-Level I/O

### Binary File Handling

- Open a file in binary mode:
    
    ```c
    FILE *file = fopen("data.bin", "wb");
    ```
    
- Writing binary data:
    
    ```c
    fwrite(pointer, size, count, file);
    ```
    
- Reading binary data:
    
    ```c
    fread(pointer, size, count, file);
    ```
    
- `fread` returns `0` if EOF is reached or an error occurs.

### Structs in Binary Files

- C **may insert padding** between struct members, so always use `sizeof()` when writing structs.
- Example:
    
    ```c
    struct Student {
        int id;
        char name[50];
        float gpa;
    };
    fwrite(&student, sizeof(struct Student), 1, file);
    ```
    

## Makefiles

### What is a Makefile?

- Automates the compilation process for multi-file programs.
- Example:
    
    ```make
    FLAGS = -Wall -Werror -std=c99
    all: program
    program: main.o utils.o
        gcc $(FLAGS) -o $@ $^
    %.o: %.c
        gcc $(FLAGS) -c $<
    clean:
        rm -f *.o program
    ```
    
- `$@`: Target name
- `$^`: Dependencies
- `$<`: First dependency
- `clean`: Removes compiled files

## Summary

- **Streams simplify file handling in C.**
- **Binary files use `fread` and `fwrite` for efficient storage.**
- **Makefiles automate compilation of large programs.**
- **Always close files and free memory to avoid resource leaks.**