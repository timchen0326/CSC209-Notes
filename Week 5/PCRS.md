## 🗂 Files & I/O

### 📌 Writing to Files

- **Functions:**
    - `fprintf(FILE *stream, const char *format, ...)`
    - Risks of `fprintf` & `printf`:
        - Statements are **undefined** in the event of a crash.
        - **Power loss** may prevent data from writing to disk.
        - Not reliable for **debugging**.

### 📌 Putting it All Together

- **File operations:**
    
    c
    
    CopyEdit
    
    `FILE *numbers_file, *output_file; int total; char name[21]; numbers_file = fopen("phone_numbers.txt", "r"); output_file = fopen("names.txt", "w"); while (fscanf(numbers_file, "%20s %d", name, &total) == 2) {     fprintf(output_file, "%s\n", name); } fclose(numbers_file); fclose(output_file);`
    
- **Valid sequence of operations**:
    1. `fopen("phone_numbers.txt", "r");`
    2. `fopen("names.txt", "w");`
    3. Read and write using `fscanf` & `fprintf`.
    4. `fclose()` calls.

---

## 🔍 Low-Level I/O

### 📌 Binary Files

- **Opening a binary file:**
    
    c
    
    CopyEdit
    
    `FILE *test_file = fopen("important.dat", "wb");`
    
- `rb` - Read binary, `wb` - Write binary, `ab+` - Append binary.

### 📌 Writing Binary Files

- `fwrite()` parameters:
    
    c
    
    CopyEdit
    
    `fwrite(pointer_to_data, size_of_each_element, number_of_elements, file_pointer);`
    
- **Example:**
    
    c
    
    CopyEdit
    
    `int numbers[] = {1, 2, 3, 4}; FILE *file = fopen("data.bin", "wb"); fwrite(numbers, sizeof(int), 4, file); fclose(file);`
    

### 📌 Reading Binary Files

- `fread()` returns `0` if:
    - No items were read.
    - End of file reached.
    - Error occurred.

### 📌 WAV File Handling

- **Using `od` to inspect headers:**
    
    sh
    
    CopyEdit
    
    `od -A d -j 44 -t d4 song.wav`
    
    - `-j 44`: Skip 44 bytes (header).
    - `-t d4`: Interpret as 4-byte decimal values.

### 📌 Structs in Binary Files

- **Why use `sizeof()`?**
    - C **inserts padding** between struct members.
    - Ensures proper memory allocation.
    - Example:
        
        c
        
        CopyEdit
        
        `struct Student {     int id;     char name[50];     float gpa; }; fwrite(&student, sizeof(struct Student), 1, file);`
        

### 📌 Moving Around in Files

- `fseek(FILE *stream, long offset, int whence)`
    
    - `SEEK_SET`: Move from **start**.
    - `SEEK_CUR`: Move **relative** to current.
    - `SEEK_END`: Move from **end**.
    
    c
    
    CopyEdit
    
    `fseek(wav_file, 44, SEEK_SET); // Move past WAV header`
    

---

## ⚙️ Compiling & Makefiles

### 📌 Compiler Toolchain

- **Key Compilation Steps:**
    1. **Preprocessing**: `gcc -E`
    2. **Compilation**: `gcc -S` → Produces `my_prog.s`
    3. **Assembling**: `gcc -c` → Produces `my_prog.o`
    4. **Linking**: `gcc my_prog.o` → Produces `a.out`

### 📌 Header Files

- **Purpose**:
    - Defines function prototypes.
    - Shares common **structs** & **constants**.
    - Included using `#include "file.h"`.

### 📌 Header File Variables

- `static`: Keeps a variable **local** to a file.
- `extern`: Declares a **global** variable defined elsewhere.

### 📌 Makefiles

- **Key parts of a `Makefile`:**
    
    make
    
    CopyEdit
    
    `FLAGS = -Wall -Werror -std=c99 DEPENDENCIES = ptree.h  all: print_ptree  print_ptree: print_ptree.o ptree.o     gcc ${FLAGS} -o $@ $^  %.o: %.c ${DEPENDENCIES}     gcc ${FLAGS} -c $<  clean:      rm -f *.o print_ptree`
    
- `.PHONY` - Declares a **target that is not a file**.
- `FLAGS` - A **variable** storing compiler flags.
- `print_ptree` - A **target** that depends on object files.