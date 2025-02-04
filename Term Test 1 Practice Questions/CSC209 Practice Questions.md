## **Section 1: Command Line & Unix Tools**

### 1. Compiling & Running a Program

Suppose you have a C file named `calc.c`. Write the **command** to:

- Compile it into an executable called `calc` with **all warnings enabled**.
- Run `calc` and redirect both **stdout** and **stderr** to a file named `results.txt`.

**Answer:** 

```bash
gcc -Wall -g -o calc calc.c
./calc > results.txt 2>&1

```


---

### 2. File Permissions

Consider the following output from `ls -l`:

```
-rw-r--r--  1 user group  1234 Feb  3 10:30 report.txt
```

- Who **can modify** this file?
- Write a **command** to make it readable and writable **only by the owner**.

**Answer:**

The **owner** can modify the file.

```bash
chmod 600 report.txt

```




---

### 3. I/O Redirection & Pipes

Explain what the following Unix command does:

```bash
cat words.txt | grep "hello" | sort | uniq > filtered.txt
```

**Answer:**

The command extracts lines from `words.txt` containing "hello", sorts them, removes duplicates, and writes the output to `filtered.txt`.


---

## **Section 2: C Programming & Memory Management**

### 4. Command-Line Arguments

Consider the following program:

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    printf("First arg: %s\n", argv[1]);
    return 0;
}
```

- What will happen if this program is executed as `./a.out` **without** any arguments?
- Modify the code to handle this situation gracefully.

**Answer:**

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./a.out <arg>\n");
        return 1;
    }
    printf("First arg: %s\n", argv[1]);
    return 0;
}

```

---

### 5. Pointers & Arrays

Given the following array:

```c
int arr[] = {10, 20, 30, 40, 50};
int *ptr = arr;
```

- What is the value of `*(ptr + 2)`?
- Rewrite the following **without using array notation**:
    
    ```c
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
    ```
    

**Answer:**

30

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", *(arr + i));
}

```

---

### 6. Memory Management

Identify the issue in this code and suggest a fix:

```c
int *create_array(int size) {
    int arr[size];
    return arr;
}
```

**Answer:**

Issue is returning a **local variable** (stack memory).

```c
char *copy_string(const char *input) {
    char *new_str = malloc(strlen(input) + 1);
    strcpy(new_str, input);
    return new_str;
}

```

---

### 7. Memory Leak Prevention

Modify the following code to **prevent a memory leak**:

```c
char *copy_string(const char *input) {
    char *new_str = malloc(strlen(input) + 1);
    strcpy(new_str, input);
    return new_str;
}
```

**Answer:**

```c
char *copy_string(const char *input) {
    char *new_str = malloc(strlen(input) + 1);
    strcpy(new_str, input);
    free(new_str)
    return new_str;
}
```

The caller is responsible for calling `free()`.


---

## **Section 3: File Handling in C**

### 8. File I/O Basics

Complete the following program so it:

- Opens `data.txt` in read mode.
- Reads and prints its content line by line.
- Ensures the file is **properly closed** after reading.

```c
#include <stdio.h>
int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char buffer[100];
    while (__________) {  // Fill in the correct condition
        ____________;  // Fill in the correct function call
    }
    fclose(file);
    return 0;
}
```

**Answer:**

```c
#include <stdio.h>
int main() {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    char buffer[100];
	while (fgets(buffer, sizeof(buffer), file) != NULL) {
	    printf("%s", buffer);
	}

    fclose(file);
    return 0;
}
```

---

### 9. File Output Handling

Write a function in C that:

- Takes a **filename** and an **integer array**.
- Writes the array contents to the file, one number per line.
- Ensures safe **file closing**.

**Answer:**

```c
void write_array_to_file(const char *filename, int *arr, int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    fclose(file);
}

```

---

## **Section 4: Structs & Dynamic Memory**

### 10. Working with Structs

Given the struct:

```c
 struct Person {
    char name[50];
    int age;
}
```

- Write a function `void update_person(Person *p, const char *new_name, int new_age);` that updates a person's information.
- Why must `new_name` be **copied** instead of assigned?

**Answer:**

```c
void update_person(struct Person *p, const char *new_name, int new_age) {
	strcpy(p-> name, new_name);
	p->age = new_age;

}

```

---

### 11. Linked List Operations

Given the following linked list structure:

```c
typedef struct node {
    int value;
    struct node *next;
}
```

- Write a function to **traverse and print** all elements.
- Write a function to **free all nodes** in the linked list.

**Answer:**

```c
void print_list(Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

```

---

## **Section 5: Ethics & Security**

### 12. Ethical File Access

Suppose a student accidentally sets their home directory to **rwxrwxrwx** (`chmod 777 ~`).

- What security risks does this pose?
- What would you do if you noticed this issue in a shared computing environment?

**Answer:**

Security risks include unauthorized access, data theft, and accidental modifications. 
If I notice this issue, I should inform the user and guide them to change permissions using:
chmod 700 ~

---

### 13. Data Privacy & Security

Consider a scenario where you are working on a system that **logs user activity**:

- What are some **ethical concerns** about storing and using this data?
- What best practices should be followed to ensure **user privacy**?

**Answer:**

Ethical concerns: potential misuse, privacy violations, unauthorized tracking.
Best practices: anonymize data, secure storage, obtain user consent.


---

### **Bonus Challenge Questions**

#### 1. Valgrind Debugging

- What does `valgrind` detect?
- What command would you use to **run valgrind** on an executable `memory_test`?

**Answer:**
valgrind detects memory leaks 

```bash
valgrind ./memory_test
```
#### 2. Advanced Pointer Manipulation

Given:

```c
int x = 5, y = 10;
int *p1 = &x, *p2 = &y;
```

- Swap the values of `x` and `y` using only **pointer arithmetic** (without a third variable).

**Answer:**

```c
*p1 = *p1 + *p2;
*p2 = *p1 - *p2;
*p1 = *p1 - *p2;

```