# Introduction to Processes

## What is a Process?

A **process** is an instance of a program in execution. It consists of:

- The **program code** (text segment), which contains the actual executable instructions.
- The **program counter** (PC), which indicates the address of the next instruction to be executed.
- The **stack**, used for function parameters, return addresses, and local variables.
- The **heap**, used for dynamically allocated memory.
- The **data section**, which holds global and static variables.
- Various **CPU registers**, which store intermediate data during execution.
- **I/O information**, such as file descriptors and open files.

## Process States

A process goes through different states during its execution:

1. **New** – The process is being created but has not yet started execution.
2. **Ready** – The process is waiting to be assigned to a CPU by the scheduler.
3. **Running** – The process is actively executing on the CPU.
4. **Blocked (Waiting)** – The process is waiting for some event (e.g., I/O completion, resource availability).
5. **Terminated** – The process has finished execution and is removed from the system.

## Process Control Block (PCB)

Each process has a **Process Control Block (PCB)**, which contains essential information about the process:

- **Process ID (PID)** – A unique identifier assigned by the OS.
- **Process state** – Indicates whether the process is new, ready, running, waiting, or terminated.
- **Program counter** – Stores the address of the next instruction.
- **CPU registers** – The context of the process, stored when the process is switched out.
- **Memory management information** – Includes details such as page tables, segment tables, and memory allocation.
- **I/O status information** – List of open files, network connections, and device interactions.
- **CPU scheduling information** – Priority level, scheduling queue pointers, and other scheduling parameters.

## Process Creation

Processes are created using the **fork()** system call in UNIX-based systems.

### `fork()` System Call

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child process (PID: %d)\n", getpid());
    } else if (pid > 0) {
        printf("Parent process (PID: %d)\n", getpid());
    } else {
        perror("fork failed");
        exit(1);
    }
    return 0;
}
```

- **If `fork()` returns 0**, the process is a child.
- **If `fork()` returns a positive PID**, the process is a parent.
- **If `fork()` returns -1**, the process creation failed due to insufficient system resources.

### Process Hierarchy

- A **parent process** creates one or more **child processes**.
- Each process has a **parent process ID (PPID)**.
- Child processes are independent but inherit some properties from the parent, such as environment variables and open file descriptors.

## Process Termination

A process may terminate due to:

- **Normal exit** – Program execution completes successfully (`exit(0)`).
- **Error exit** – Program encounters an error (e.g., division by zero, `exit(1)`).
- **Killed by another process** – Using signals (e.g., `kill -9 <PID>`).
- **Parent termination** – Some child processes may terminate when their parent dies.

### `exit()` and `wait()` System Calls

- `exit(status)`: Terminates a process and returns a status to the OS.
- `wait(&status)`: Blocks the parent until a child terminates and retrieves the child's exit status.

Example:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        printf("Child process exiting\n");
        exit(42);
    } else {
        int status;
        wait(&status);
        printf("Parent received exit status: %d\n", WEXITSTATUS(status));
    }
    return 0;
}
```

## Orphan and Zombie Processes

### Orphan Process

- A **child process** whose parent terminates before it does.
- The **init** process (PID 1) adopts the orphaned process.

### Zombie Process

- A **terminated child process** that has not been `wait()`-ed for by the parent.
- Takes up process table space, leading to resource leakage.
- To prevent zombies, always use `wait()` or `waitpid()`.

## `exec` System Calls

The `exec` family of system calls replaces the current process image with a new program. Unlike `fork()`, `exec` does not create a new process; it replaces the calling process.

### Variants of `exec`

6. **`execl`**: Takes a list of arguments.
    
    ```c
    execl("/bin/ls", "ls", "-l", NULL);
    ```
    
7. **`execv`**: Takes an array of arguments.
    
    ```c
    char *args[] = {"ls", "-l", NULL};
    execv("/bin/ls", args);
    ```
    
8. **`execlp`**: Searches for the executable in the `PATH`.
    
    ```c
    execlp("ls", "ls", "-l", NULL);
    ```
    
9. **`execvp`**: Like `execv`, but searches in `PATH`.
    
    ```c
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);
    ```
    

### Behavior of `exec`

- If `exec` succeeds, the new program replaces the calling process.
- If `exec` fails, execution continues from the next statement after `exec`.

## Pipes and Process Communication

Processes communicate using **pipes**, **sockets**, and **shared memory**.

- A **pipe** allows one process to send data to another.
- **Anonymous pipes** (`pipe()`) exist between related processes.
- **Named pipes (FIFOs)** allow unrelated processes to communicate.

Example using `pipe()`:

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], "Hello, Parent!", 14);
        close(fd[1]);
    } else {
        char buffer[20];
        close(fd[1]);
        read(fd[0], buffer, 14);
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
```

## Summary

- A **process** is a running instance of a program.
- Each process has a **PCB**, containing essential information.
- **`fork()`** creates a new process.
- **`exec()`** replaces the current process image with a new one.
- **`wait()`** makes a parent process wait for its child to terminate.
- **Pipes** enable inter-process communication.

These concepts are crucial for understanding operating systems and concurrent programming.