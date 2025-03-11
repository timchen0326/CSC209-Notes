# Processes and Pipes in C

## Processes in C

### What is a Process?

A **process** is an instance of a program in execution. When a program runs, the operating system (OS) allocates resources such as memory, file descriptors, and CPU time to it.

Each process in an OS has the following attributes:

- **Process ID (PID):** A unique identifier assigned by the OS.
- **Parent Process ID (PPID):** The ID of the process that created it.
- **Memory layout:** Includes stack, heap, text, and data segments.
- **File descriptors:** Opened files and other resources.

### Creating Processes in C

Processes in C are created using the `fork()` system call. This function creates a new process (child) that is a copy of the calling process (parent).

#### Fork System Call

The `fork()` function is used to create a new child process. The child process runs the same code as the parent but gets its own memory space.

```c
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        printf("This is the child process, PID: %d\n", getpid());
        printf("Child's parent PID: %d\n", getppid());
    } else {
        printf("This is the parent process, PID: %d\n", getpid());
        printf("Parent's child PID: %d\n", pid);
    }
    return 0;
}
```

- `fork()` returns:
    - `0` in the child process
    - The child's PID in the parent process
    - `-1` on failure (no new process is created)

### Process Execution

Once a child process is created, it can replace its current program with another program using the `exec` family of functions.

#### The `exec` System Calls

The `exec` system calls replace the current process with a new one. Variants include:

- `execl()`: Takes arguments individually.
- `execv()`: Takes arguments as an array.
- `execle()`: Allows environment variables to be specified.
- `execve()`: The system-level function.
- `execlp()` and `execvp()`: Search for the executable in `PATH`.

Example using `execvp()`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *args[] = {"ls", "-l", NULL};
    execvp("ls", args);
    perror("execvp"); // Only executed if exec fails
    return 1;
}
```

- `execvp()` replaces the calling process with `ls -l`.
- If execution is successful, the original process image is overwritten.
- `perror("execvp")` runs only if `execvp` fails.

### Waiting for Child Processes

A parent process can wait for a child process to terminate using `wait()` or `waitpid()`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process executing\n");
        exit(42);
    } else {
        int status;
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
    }
    return 0;
}
```

- `wait(&status)` suspends execution until the child process terminates.
- `WIFEXITED(status)` checks if the child exited normally.
- `WEXITSTATUS(status)` extracts the exit status of the child.

## Process Communication via Pipes

A **pipe** is an inter-process communication (IPC) mechanism that allows processes to send data in a unidirectional manner.

### Creating Pipes

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {
        close(fd[0]); // Close unused read end
        write(fd[1], "Hello, parent!", 14);
        close(fd[1]);
    } else {
        close(fd[1]); // Close unused write end
        char buffer[100];
        read(fd[0], buffer, 100);
        printf("Received from child: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
```

- `pipe(fd)` creates a pipe with `fd[0]` for reading and `fd[1]` for writing.
- The child writes data into `fd[1]`, and the parent reads from `fd[0]`.

### Using `dup2()` for Redirection

The `dup2()` system call duplicates a file descriptor, useful for redirecting standard input/output.

#### Example: Redirecting `stdin`

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    execlp("cat", "cat", NULL);
    perror("execlp");
    return 1;
}
```

- `dup2(fd, STDIN_FILENO)` redirects `stdin` to read from `input.txt`.
- `execlp("cat", "cat", NULL);` runs `cat`, reading from `stdin`.

## Best Practices

- Always check return values of `fork()`, `exec()`, `wait()`, and `pipe()`.
- Close unused pipe ends to avoid resource leaks.
- Use `WEXITSTATUS(status)` to retrieve the actual exit code of a child process.
- Redirect standard input/output using `dup2()` before calling `exec()`.

## Summary

- **Processes** are created using `fork()`.
- **`exec()`** replaces a process with a new one.
- **Parent processes wait** for children using `wait()`.
- **Pipes** allow inter-process communication.
- **`dup2()`** is used for redirection of file descriptors.