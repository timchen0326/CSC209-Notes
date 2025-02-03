## Streams in C

### Introduction to Streams

- **Streams** are an abstraction for input and output operations in C.
    
- There are three standard streams:
    
    - `stdin` (standard input) - typically the keyboard.
        
    - `stdout` (standard output) - typically the screen.
        
    - `stderr` (standard error) - also typically the screen but used for errors.
        
- Functions that interact with streams:
    
    - `printf()` writes to `stdout`.
        
    - `scanf()` reads from `stdin`.
        
    - `fprintf(FILE *stream, const char *format, ...)` writes to a specified output stream.
        

### Redirection

- **Redirection** allows changing where input is read from and where output is written to.
    
- Example:
    
    ```
    $ sort < names.cat > students.txt
    ```
    
    - `sort` is the program being executed.
        
    - `names.cat` is the input file redirected into `sort`.
        
    - `students.txt` is the output file where sorted data is written.
        
- Redirection symbols:
    
    - `<` redirects standard input.
        
    - `>` redirects standard output.
        
    - `2>` redirects standard error.
        
    - `>>` appends output to a file.
        

## File Handling in C

### Opening Files

- Use `fopen()` to open a file.
    
- Syntax:
    
    ```
    FILE *file_ptr = fopen("filename.txt", "mode");
    ```
    
- Common modes:
    
    - `"r"` - read (file must exist)
        
    - `"w"` - write (creates new file or overwrites existing one)
        
    - `"a"` - append
        
    - `"r+"`, `"w+"`, `"a+"` allow reading and writing
        
- Always check if file was opened successfully:
    
    ```
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    ```
    

### Closing Files

- Use `fclose(FILE *file_ptr)` to close a file.
    
- Always check for errors when closing a file:
    
    ```
    int error = fclose(file_ptr);
    if (error != 0) {
        fprintf(stderr, "fclose failed\n");
        return 1;
    }
    ```
    

### Reading from Files

- **Using** `**fgets()**`
    
    ```
    char buffer[100];
    fgets(buffer, sizeof(buffer), file_ptr);
    ```
    
    - Reads up to `sizeof(buffer) - 1` characters.
        
    - Ensures null-termination.
        
- **Using** `**fscanf()**`
    
    ```
    fscanf(file_ptr, "%s", buffer);
    ```
    
    - Reads formatted data.
        
    - Can be dangerous if input exceeds buffer size.
        

### fgets vs fscanf

- `fgets()` reads a full line and ensures null termination.
    
- `fscanf()` is useful for structured data but does not prevent buffer overflow.
    
- Always prefer `fgets()` over `gets()` because `gets()` is unsafe.
    

## Summary

- Streams allow input/output redirection in C.
    
- Use `fopen()` to open files and `fclose()` to close them.
    
- `fgets()` is preferred over `fscanf()` for safer input handling.
    
- Redirection in the shell allows working with files easily.