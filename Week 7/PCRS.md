## Process Model

### Process Basics
- A **process** is a running instance of a program.
- The **Process Control Block (PCB)** stores information about the process, including:
  - Process ID (PID)
  - Current state (running, ready, blocked)
  - Program counter
  - Stack pointer
  - Memory limits

### Process States
1. **New** - Process is created but not yet ready to run.
2. **Ready** - Process is waiting to be assigned a processor.
3. **Running** - Process is executing on a processor.
4. **Blocked** - Process is waiting for an event (I/O, resource availability).
5. **Terminated** - Process has finished execution.

### True Statements About Processes
- A process in the **ready state** is not currently using a processor.
- The number of active processes is **less than or equal** to the number of processors.
- All processes (running, ready, or blocked) have **owners**.
- Multiple processes from the same program **can** execute simultaneously.
- The **Process Control Block (PCB)** stores important information such as the **top of the stack**.

---

## Creating Processes with `fork()`

### `fork()` System Call
- Used to create a new process (child process).
- Each process has a **unique PID**.
- The **parent process** calls `fork()`, and the newly created process is the **child**.
- The **code segments** of the parent and child are **identical**.
- Each process has its own copy of variables.

### `fork()` Return Values
- **Child process:** `fork()` returns `0`.
- **Parent process:** `fork()` returns the **PID of the child process**.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am the child process\n");
    } else {
        printf("I am the parent process, my child's PID is %d\n", pid);
    }
    return 0;
}
```

---

## Process Relationships and Termination

### Parent-Child Relationship
- A **parent process** can create multiple **child processes**.
- A **parent process does not finish** running until all of its child processes terminate.
- The **operating system decides** which process runs when one is blocked.

### `wait()` and `waitpid()`
- `wait()` suspends the parent process until one of its children terminates.
- `waitpid(pid, status, options)` waits for a specific child process.
- `WIFSIGNALED(status)` checks if a child was terminated by a signal.

### Orphans and Zombies
- **Orphan Process:** Parent terminates before the child, so the child is adopted by `init` (PID 1).
- **Zombie Process:** A process that has finished execution but still has an entry in the process table (waiting for `wait()` from the parent).

---

## Running Different Programs with `exec()`
- `exec()` replaces the current process image with a new program.
- The `execl` system call format:
  ```c
  execl("./hello", "hello", NULL);
  ```
  - The first argument is the program to execute.
  - The second argument is the name of the program (convention).
  - `NULL` marks the end of arguments.

### `exec()` Behavior
- If `exec()` is successful, it **never returns**.
- If `exec()` fails, the next statement executes.

Example:
```c
#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec\n");
    execl("/bin/ls", "ls", NULL);
    printf("This will not execute if exec is successful\n");
    return 0;
}
```

---

## Function Pointers in C

### Basics of Function Pointers
- A **function pointer** is a pointer that stores the address of a function.
- Declaration:
  ```c
  int (*func_ptr)(int, int);
  ```
- Assigning a function to a function pointer:
  ```c
  int add(int a, int b) { return a + b; }
  func_ptr = add;
  ```
- Calling the function via pointer:
  ```c
  int result = func_ptr(2, 3);
  ```

### Function Pointer Syntax
- Correct ways to define and use function pointers:
  ```c
  char * (*x) (char *) = my_func;
  ```
  - `x` is a pointer to a function that takes a `char *` and returns a `char *`.

- Incorrect usage:
  ```c
  char x[10] = my_func("blah.txt");  // ❌ Invalid
  ```

### Function Pointer in Function Return
- A function can return a pointer to another function:
  ```c
  void (*parse_command_line(int argc, char *argv[]))(int *, int);
  ```
  - `parse_command_line` returns a **function pointer**.

---

## Summary
- Processes have states (New, Ready, Running, Blocked, Terminated).
- `fork()` creates new processes; child and parent run independently.
- `wait()` and `waitpid()` help synchronize parent-child process termination.
- `exec()` replaces the process image with a new program.
- Function pointers enable dynamic function calls in C.

