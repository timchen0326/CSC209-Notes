## Arrays

### Introduction to Arrays

- Arrays are collections of elements of the same type stored in contiguous memory locations.
- Declaring an array:
    
    ```c
    int high_score[20]; // Stores 20 integer scores
    ```
    
- Initializing specific elements:
    
    ```c
    int ages[8];
    ages[0] = 4;
    ages[1] = 44;
    ages[2] = 18;
    ```
    
- Accessing elements via index:
    
    ```c
    float cost[4] = {0, 10.75, 20.50, 30.0};
    float total_cost;
    int group_size = 2;
    total_cost = cost[group_size]; // total_cost = 20.50
    ```
    

### Accessing Array Elements

- The address of an element `A[i]` is equivalent to:
    
    - `A + i` (incorrect if `i` isn't multiplied by the size of each element)
    - `A + (i * sizeof(A[0]))` (correct)
    - `A[0] + (i * sizeof(A[0]))` (correct)
    - `A + (i * 4)` (only valid if `sizeof(int) == 4`)
- Out-of-bounds access consequences:
    
    - No guaranteed error, may overwrite another variable.
    - Sometimes causes segmentation faults.
    - Some compilers may issue warnings, but not errors.

### Iterating Over Arrays

- Finding the second oldest age:
    
    ```c
    int oldest = ages[0];
    int second_oldest = ages[0];
    for (int i = 1; i < count; i++) {
        if (ages[i] > oldest) {
            second_oldest = oldest;
            oldest = ages[i];
        } else if (ages[i] > second_oldest) {
            second_oldest = ages[i];
        }
    }
    printf("%d\n", second_oldest);
    ```
    

## Pointers

### Introduction to Pointers

- A pointer stores the memory address of a variable.
- `*` is used to dereference a pointer, accessing the value at the stored address.
- Example:
    
    ```c
    char c = 'b';
    char *c_ptr = &c; // Assign address of c to c_ptr
    printf("%c", *c_ptr); // Prints 'b'
    ```
    

### Assigning to Dereferenced Pointers

- Correct pointer assignments:
    
    ```c
    int *p = foo;
    int* p = foo;
    int *p; p = foo;
    ```
    
- Modifying a variable using a pointer:
    
    ```c
    int secret;
    int *another_secret;
    int *secret_pt = &secret;
    *secret_pt = *secret_pt + *another_secret;
    ```
    

### Pointers as Function Parameters

- Swapping two integer values:
    
    ```c
    void swap(int *num1, int *num2) {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    ```
    
- Example usage:
    
    ```c
    int x = 5, y = 8;
    swap(&x, &y);
    printf("%d, %d\n", x, y); // Output: 8, 5
    ```
    

### Passing Arrays as Parameters

- Arrays are passed by reference (only the address is passed).
- Example function call:
    
    ```c
    int year[5] = {1992, 2015, 1965, 1990, 1984};
    some_function(year); // Passes the address of year[0]
    ```
    
- The function can modify `year`, but not its address.

### Pointer Arithmetic

- Given:
    
    ```c
    int age[5] = {4, 70, 52, 18, 16};
    int *p = age;
    ```
    
    - `*p = 4`
    - `p[2] = 52`
    - `*(p+1) = 70`

### Pointers to Pointers

- Using double pointers:
    
    ```c
    int x = 4;
    int *y = &x;
    int **z = &y;
    int q;
    q = **z; // q = 4
    ```
    
- Printing using a pointer to a pointer:
    
    ```c
    int i = 42;
    int *p = &i;
    int **p_ptr = &p;
    printf("%d", **p_ptr); // Prints 42
    ```