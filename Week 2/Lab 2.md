# Lab 2: Pointers and Input - Study Notes

## Overview

This lab focuses on practicing C programming with **pointers, arrays, and the `scanf` function**. The exercises require implementation of functions that manipulate pointers, read input, and perform calculations.

---

## Key Concepts

### 1. **Pointers in C**

- A pointer stores the address of a variable.
- `*ptr` dereferences a pointer, accessing the value stored at that address.
- `&var` gives the address of `var`.
- `malloc` dynamically allocates memory.
- Pointer arithmetic allows traversing arrays.

### 2. **Arrays and Pointer Arithmetic**

- Arrays and pointers are closely related.
- `arr[i]` is equivalent to `*(arr + i)`.
- Arrays decay into pointers when passed to functions.

### 3. **Standard Input and Output (`scanf`, `printf`)**

- `scanf("%d", &x)` reads an integer into `x`.
- `scanf("%10s", str)` ensures `str` does not overflow.
- Always validate input when using `scanf`.

### 4. **Basic File Operations**

- Submitting files via `git add`, `git commit`, and `git push`.
- Avoid committing executables.
- Use `MarkUs` for verification.

---

## Lab Exercises

### 1. **`invest.c` - Investment Calculator**

**Goal:** Implement `invest` function that multiplies a principal amount by a given rate.

#### Function Implementation:

```c
void invest(double *principal, double rate) {
    *principal *= rate;
}
```

#### Key Takeaways:

- Uses **pass-by-pointer** to modify the principal in-place.
- `strtod` converts input arguments from strings to doubles.
- Avoids returning values by directly modifying the variable.

### 2. **`score_card.c` - Summing Pointers to Integers**

**Goal:** Implement `sum_card` function that sums integers from an array of integer pointers.

#### Function Implementation:

```c
int sum_card(int **score_card, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(score_card[i]);
    }
    return sum;
}
```

#### Key Takeaways:

- Array of pointers means `score_card[i]` is a pointer to an integer.
- Dereferencing `*(score_card[i])` accesses the integer value.
- `malloc` is used to allocate memory dynamically.

### 3. **`phone.c` - String and Integer Processing**

**Goal:** Read a **10-character string** and an **integer**, then print characters based on the integer value.

#### Function Implementation:

```c
int main() {
    char phone[11];
    int index;
    if (scanf("%10s %d", phone, &index) != 2) {
        return 1;
    }

    if (index == -1) {
        printf("%s\n", phone);
    } else if (index >= 0 && index <= 9) {
        printf("%c\n", phone[index]);
    } else {
        printf("ERROR\n");
        return 1;
    }
    return 0;
}
```

#### Key Takeaways:

- Uses `scanf("%10s %d", phone, &index)` to read input safely.
- **Edge Cases:**
    - If `index == -1`, prints the whole string.
    - If `index` is in `[0,9]`, prints the character at `index`.
    - Else, prints "ERROR" and returns `1`.
- The array `phone[11]` has an **extra space** for the null terminator `\0`.

### 4. **`digits.c` - Counting and Filtering Digits**

**Goal:** Implement `repeated_digits` and `leave_repeated_digits` to analyze digit frequency.

#### Counting Repeated Digits:

```c
int repeated_digits(int *numbers, int length) {
    if (numbers == NULL || length < 1) {
        return -1;
    }
    int count[10] = {0};
    int repeated_count = 0;
    for (int i = 0; i < length; i++) {
        count[numbers[i]]++;
        if (count[numbers[i]] == 2) {
            repeated_count++;
        }
    }
    return repeated_count;
}
```

#### Filtering Repeated Digits:

```c
void leave_repeated_digits(int *numbers, int *length) {
    int count[10] = {0};
    int new_length = 0;
    for (int i = 0; i < *length; i++) {
        count[numbers[i]]++;
        if (count[numbers[i]] == 2) {
            numbers[new_length++] = numbers[i];
        }
    }
    *length = new_length;
}
```

#### Key Takeaways:

- Uses **frequency counting** with an integer array `count[10]`.
- **`repeated_digits`**:
    - Increments count for each digit.
    - If a digit appears **twice**, increments `repeated_count`.
- **`leave_repeated_digits`**:
    - Retains only digits that appear **more than once**.
    - Updates `length` to reflect the modified array.

#### Command-Line Execution:

```sh
$ gcc -Wall -g -o digits digits.c
$ ./digits 1313
2
1 3
```

---

## Submission Guidelines

1. **Use Git Commands**
    
    ```sh
    git add invest.c phone.c score_card.c digits.c
    git commit -m "Completed Lab 2"
    git push
    ```
    
2. **Run Tests on MarkUs**
    - Ensure your code compiles without warnings.
    - Run the **Automated Tests** on MarkUs.
    - Your code must handle all edge cases, not just pass the provided tests.
3. **Avoid Committing Executables**
    - Use `git status` to check files before committing.
    - Only commit `.c` source files.

---

## Summary of Learning Outcomes

|Concept|Explanation|
|---|---|
|**Pointers**|Manipulating variables via memory addresses|
|**Arrays & Strings**|Using arrays for integer storage and character processing|
|**Input Handling**|Using `scanf` safely and handling input validation|
|**Memory Management**|Allocating and using memory dynamically with `malloc`|
|**Git Usage**|Proper submission via `git add`, `commit`, and `push`|

This lab provides essential practice with pointers, input handling, and fundamental C programming techniques critical for the **midterm test**.