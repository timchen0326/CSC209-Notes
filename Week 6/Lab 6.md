# Debugging & String Manipulation: 

## **Part 1: Implementing `copy.c`**

### **Objective:**

- Implement a custom `copy` function similar to `strncpy` but ensuring `dest` is always null-terminated.
- **Restrictions:** Cannot use string functions except `memset`.

### **Implementation Details:**

```c
char *copy(char *dest, const char *src, int capacity) {
    if (capacity <= 0) return dest;

    int i;
    for (i = 0; i < capacity - 1 && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; // Ensure null termination
    return dest;
}
```

### **Testing `copy.c`**

#### **Compilation:**

```sh
gcc -Wall -Wextra -o copy copy.c
chmod +x copy
```

#### **Run Tests:**

```sh
./copy 10 hello   # Expected: hello
./copy 6 "hello world"  # Expected: hello
./copy 1 "hello"  # Expected: (empty string)
```

---

## **Part 2: Using `gdb` to Solve the Maze**

### **Objective:**

- Use `gdb` to traverse a 4x4 maze, collecting three treasures (`SPELLBOOK`, `POTION`, `WAND`).
- Find a correct path and store it in `maze.txt`.

### **Steps to Solve the Maze:**

#### **1. Connect to teach.cs:**

```sh
ssh yourUTORid@teach.cs.toronto.edu
```

#### **2. Run `gdb` on Labyrinth:**

```sh
gdb --args /u/csc209h/fall/pub/lab6/labyrinth yourUTORid
```

#### **3. Set a Breakpoint:**

```gdb
break 30
run
```

#### **4. Print the Starting Cell:**

```gdb
print *start_location
```

#### **5. Navigate the Maze:**

- **Check available directions:**

```gdb
print *start_location->south
print *start_location->east
print *start_location->west
print *start_location->north
```

- Follow paths to collect `SPELLBOOK`, `POTION`, `WAND`.

#### **6. Record Movement Path:**

Example path:

```
SESESWNWWWS
```

#### **7. Test Path in Labyrinth:**

```sh
/u/csc209h/fall/pub/lab6/labyrinth yourUTORid SESESWNWWWS
```

Expected Output:

```
Congratulations! You have escaped the labyrinth.
```

#### **8. Save and Submit `maze.txt`:**

```sh
echo "SESESWNWWWS" > maze.txt
cat maze.txt

git add maze.txt
git commit -m "Completed Lab 6: Maze solution"
git push
```

---

## **Part 3: Debugging with `gdb` (Optional Practice)**

### **Objective:**

- Learn `gdb` debugging for memory issues and segmentation faults.

### **Key `gdb` Commands:**

```gdb
gdb ./overflow
break main
run
display variable
next
print variable
continue
backtrace full
quit
```

### **Testing for Buffer Overflows:**

```sh
gcc -Wall -g -o overflow overflow.c
./overflow
```

- Modify `OVERFLOW` size to check for segmentation faults.

---

## **Key Takeaways:**

- **String Manipulation:** Implementing `copy.c` with manual null-termination.
- **Debugging in `gdb`:** Traversing memory structures using pointer dereferencing.
- **Maze Solving:** Using `gdb` to explore a struct-based grid system.
- **Git Workflow:** Committing and pushing `maze.txt` correctly.

**Study these steps for your test!** 🚀