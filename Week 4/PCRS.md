## 🏗️ **Structures in C**

### 📌 **Defining and Using Structs**

- **Struct Definition**
    
    ```c
    struct contact {
        char name[30];
        int phone_number;
        char address[30];
    };
    ```
    
- **Declaring and Initializing a Struct**
    
    ```c
    struct contact best_friend;
    strcpy(best_friend.name, "Jane Doe");
    best_friend.phone_number = 377177377;
    strcpy(best_friend.address, "1337 University Avenue");
    ```
    

### 📌 **Structs and Functions**

- **Passing Structs to Functions (By Value)**
    
    ```c
    void change_number(struct contact c, int new_number) {
        c.phone_number = new_number;
    }
    ```
    
    - Changes do **not** persist outside the function.
- **Using Pointers to Modify Structs**
    
    ```c
    void update_contact(struct contact *c, char *new_name, int new_number, char *new_address) {
        strcpy(c->name, new_name);
        c->phone_number = new_number;
        strcpy(c->address, new_address);
    }
    ```
    

---

## 📦 **Dynamic Memory Allocation in C**

### 📌 **malloc() and free()**

- **Allocating Memory for an Integer Array**
    
    ```c
    int *A = malloc(sizeof(int) * 20);
    ```
    
    - Allocates `20 * sizeof(int)` bytes on the **heap**.
    - Returns a `void *` which must be cast to the appropriate pointer type.
- **Freeing Allocated Memory**
    
    ```c
    free(A);
    ```
    
    - Does **not** reset the values in the memory to `NULL`.

### 📌 **Common Mistakes and Memory Leaks**

- **Memory Leak Example**
    
    ```c
    int *ptr = malloc(sizeof(int) * 5);
    ptr = malloc(sizeof(int) * 10); // Previous allocation is lost
    ```
    
    - **Solution**: `free(ptr);` before reassigning.
- **Double Free Issue**
    
    ```c
    free(ptr);
    free(ptr); // Undefined behavior!
    ```
    

### 📌 **Handling 2D Dynamic Arrays**

```c
int **heights = malloc(sizeof(int*) * 2);
heights[0] = malloc(sizeof(int) * NUM_BOYS);
heights[1] = malloc(sizeof(int) * NUM_GIRLS);

// Freeing in reverse order of malloc
free(heights[0]);
free(heights[1]);
free(heights);
```

---

## 📜 **Strings in C**

### 📌 **String Initialization**

- **Stack-Allocated String**
    
    ```c
    char greetings[15] = "salutations";
    ```
    
- **String Literal**
    
    ```c
    char *farewell = "goodbye";
    ```
    

### 📌 **Common String Functions**

- **strlen() Example**
    
    ```c
    char alphabet[] = "abcdef";
    printf("%d\n", strlen(alphabet)); // 6
    alphabet[3] = '\0';
    printf("THEN %d\n", strlen(alphabet)); // 3
    ```
    
- **Safe String Copying**
    
    ```c
    char s1[10];
    char s2[15] = "don't do this";
    strncpy(s1, s2, sizeof(s1) - 1);
    s1[sizeof(s1) - 1] = '\0';
    ```
    

### 📌 **Concatenation**

- **Using `strcat` Safely**
    
    ```c
    char s1[22] = "Cat got your ";
    char s2[10] = "tongue?";
    strncat(s1, s2, sizeof(s1) - strlen(s1) - 1);
    ```
    

---

## 🔗 **Linked Lists**

### 📌 **Defining a Linked List Node**

```c
typedef struct node {
    int value;
    struct node *next;
} Node;
```

### 📌 **Traversing a Linked List**

```c
Node *current = front;
while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
}
```

### 📌 **Insertion into a Linked List**

- **Inserting a Node in the Middle**

```c
Node *new_node = malloc(sizeof(Node));
new_node->value = 42;
new_node->next = prev->next;
prev->next = new_node;
```

---

## ✅ **Review Questions and Key Takeaways**

- **Structs:** Use pointers to modify values within functions.
- **Dynamic Memory:** Always `free` allocated memory to avoid leaks.
- **Strings:** Be mindful of `strncpy` and null terminators.
- **Linked Lists:** Remember to update `next` pointers properly.

---

📌 **End of Week 4 Notes** 📌