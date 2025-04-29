**CSC209H1S Final Examination – April 2019**

**Duration**: 3 hours  
**Aids Allowed**: No Examination Aids

**Student Number**: __________  
**Last Name**: __________  
**First Name**: __________  
**Section**: 10101 (MW10) / 10201 (MW11) / 10301 (MW2) / 10401 (TR10) / 15101 (W6)

---

## Question 1 (10 Marks)

Circle the correct answer for each statement below (True/False).

1. `strcpy(dst, src)` is a safe function because it will never copy more characters to `dst` than `dst` has been allocated to store.  
    **Answer**: ___F___
    
2. A `SIGSEGV` signal is sent when a process tries to access an invalid memory address.  
    **Answer**: ___T___
    
3. Assuming `prog` is a valid program in your current working directory and the call to `execl` is successful, the statement `"Done running prog"` will be the last message printed to stdout by this fragment of code:
    
    ```c
    printf("Start running prog\n");
    execl("./prog", "prog", NULL);
    printf("Done running prog\n");
    ```
    
    **Answer**: ___F___
    
4. A server process uses the same socket descriptor to read from and write to all of its clients.  
    **Answer**: ___F___
    
5. Given `int x = 4;` and `int y = 8;`, the expressions `(x & y)` and `(x && y)` will evaluate to different values.  
    **Answer**: ___T___
    
6. A client’s `connect()` call will only return successfully after the server has called `accept()` for this client.  
    **Answer**: ___T___
    
7. When a process calls `execl`, a new process with different process id runs the program specified by the first argument.  
    **Answer**: __F__
    
8. Attempting to read from a pipe that is closed for writing will result in a `SIGPIPE` signal being sent.  
    **Answer**: ___F___
    
9. When our server program calls `listen` with its second argument equal to 5, it is possible for more than 5 clients to eventually connect to the server.  
    **Answer**: ___T___
    
10. The current working directory contains files named `apple` and `banana`. When the following shell program is run with command line arguments `cat` and `dog`, the output will be `apple` and `banana` on separate lines:
    
    ```sh
    for i in $*; do
      echo $i
    done
    ```
    
    **Answer**: ___F___
    

---

## Question 2 (4 Marks)

Your current working directory contains only two C source files and a header file named `prog.c`, `lib.c`, and `lib.h` respectively. The `prog.c` file has a `main` function and calls functions from `lib.c`.

**(a)** Write a Makefile rule so that the object file `lib.o` is created only if at least one of the files `lib.c` and `lib.h` has been modified. Note that the program should be compiled with debugging symbols enabled.

```make
# lib.o rule
lib.o: lib.c lib.h
gcc -g -c lib.c -o lib.o
...
```

**(b)** Write a Makefile rule so that the object file `prog.o` is created only if `prog.c` has been modified. Note that the program should be compiled with the flag to display all warning messages.

```make
# prog.o rule
prog.o: prog.c
gcc -Wall -c prog.c

...
```

**(c)** Write a Makefile rule so that when you type `make prog`, the final executable `prog` is created only if at least one of `lib.o` or `prog.o` has been modified.

```make
# prog rule
prog: lib.o prog.o
gcc  -o prog lib.o prog.o

...
```

**(d)** We want the program `prog` to be compiled or updated when we type `make` with no arguments. Explain what we need to do to the Makefile, including any new rules that might need to be created so that this will work.

> **Answer**: _____________________________________________all:prog_

---

## Question 3 (7 Marks)

Some code fragments below have a problem. For each fragment, indicate whether the code works as intended or there is an error. If the code does not compile, check **COMPILE ERROR** and explain why. If the code compiles without errors, but running the program might cause an error (runtime or logical), check **ERROR** and explain why. Otherwise, check **NO ERROR** and write the result of the print statement.

**(a)**

```c
char str[] = "CSC209";
char *s = "CSC209S";
s[6] = '\0';
printf("%d\n", strcmp(str, s));
```

-  NO ERROR Result: _____
    
-  COMPILE ERROR Reason: __________________
    
-  ERROR Reason: ________writing to string literal is invalid. String literals are read-only__________
    

**(b)**

```c
int x;
int *p = &x;
printf("%d\n", *p);
```

-  NO ERROR Result: _____
    
-  COMPILE ERROR Reason: __________________
    
-  ERROR Reason: _________x not assigned yet, pointer p doesn't print anything_________
    

**(c)**

```c
int arr[5] = {1,2,3,4,5};
int *p = arr[2];
printf("%d\n", *p);
```

-  NO ERROR Result: _____
    
-  COMPILE ERROR Reason: _________Type mismatch, arr[2] is an integer, not a pointer to an integer_________
    
-  ERROR Reason: __________________
    

**(d)**

```c
char arr[11] = "Basket";
strcat(arr, "ball");
printf("%s\n", arr);
```

-  NO ERROR Result: ___Basketball__
    
-  COMPILE ERROR Reason: __________________
    
-  ERROR Reason: __________________
    

**(e)**

```c
char str[] = "Welcome to CSC209!";
char s[16] = "Hello!";
strncat(s, str, 15);
printf("%s\n", s);
```

-  NO ERROR Result: __Buffer is too small to hold "Hello!" +15 characters from str___
    
-  COMPILE ERROR Reason: _________________
    
-  ERROR Reason: __________________
    

**(f)**

```c
char *get_extension(char *str) {
  char ext[4];
  char *p;
  if ((p = strchr(str, '.')) != NULL) {
    strncpy(ext, p, 4);
    ext[3] = '\0';
    return ext;
  } else {
    return NULL;
  }
}
printf("%s\n", get_extension("run.c"));
```

-  NO ERROR Result: _____
    
-  COMPILE ERROR Reason: __________________
    
-  ERROR Reason: _________the function returns a pointer to a local variable whihc becomes invalid after the function returns_________
    

**(g)**

```c
void build_reverse(char *src, char *dest) {
  int i, j;
  for (i = strlen(src), j = 0; i > 0; i--, j++)
    dest[j] = src[i];
  dest[j] = '\0';
}
char t[6];
char *s = "World";
build_reverse(s, t);
printf("%s\n", t); // Prints dlroW
```

-  NO ERROR Result: _____
    
-  COMPILE ERROR Reason: __________________
    
-  ERROR Reason: _________The function doesn't work correctly. It should use indexes starting from strlen(src)-1_________
    

---

## Question 4 (5 Marks)

The purpose of the following function is to add a new item at the beginning of a linked list. However, the function does not work properly. First, identify two problems with the implementation. Second, correctly implement the function without modifying its return value; you may change the parameters.

```c
struct node {
  int value;
  struct node *next;
};

void list_insert_head(struct node *head, int val) {
  struct node p;
  p.value = val;
  p.next = head;
  head = &p;
}
```

- **First problem**: _______________________________The node allocated on the stack, so it disappears when the function returns_
    
- **Second problem**: ____the head parameter is passed by vlaues, so changing it doesnt affect the caller__________________________
    

**Correct implementation**:

```c
void list_insert_head(struct node **head, int val) {
  struct node *p = malloc(sizeof(struct node));
  p->value = val;
  p->next = *head;
  *head = p;
}
```

---

## Question 5 (8 Marks)

Consider the memory diagram below. Complete the code to match the diagram. As always, your program should free any heap-allocated memory.

```c
char *reverse(char *s) {
  int len = strlen(s);
  char *rev = malloc(sizeof(char) * (len+1);
  int i;
  for (i = 0; i < len; i++) { rev[len - i - 1] = s[i]; } rev[len] = '\0';
  return rev;
}

int main() {
  char *fruit = 'bananas';
  char *str = reverse(fruit);
  free(str);
  return 0;
}
```

_(Memory diagram referenced on exam page – reproduce on paper.)_

---

## Question 6 (7 Marks)

A binary file contains an array of `struct record` entries followed by name data. Implement the function `get_record_name` that returns the name for a given record id or `NULL` if not found.

```c
#define NUM_RECS 4
struct record {
  int id;
  int len;
  int offset;
};

char *get_record_name(char *filename, int rec_id) {
  // ____________________________________________
  FILE *fp = fopen(filename,"rb");
  if (fp == NULL) {
  return NULL;
  };
  struct record recs[NUM_RECS];
  if(fread(recs, sizeof(struct record), NUM_ RECS, fp) != NUM RECS) {
	  fclose(fp);
	  return NULL;
  }
  char *name = NULL;
  for (int i = 0; i < NUM_RECS; i++) { if (recs[i].id == rec_id) { name = malloc(recs[i].len + 1); if (name == NULL) { fclose(fp); return NULL; } fseek(fp, recs[i].offset, SEEK_SET); if (fread(name, 1, recs[i].len, fp) != recs[i].len) { free(name); fclose(fp); return NULL; } name[recs[i].len] = '\0'; break; } } fclose(fp); return name;
}
```

---

## Question 7 (6 Marks)

Write a function `do_fork` that forks child processes and prints elements of an array in a linear chain.

```c
void do_fork(char **data, int size) {
    // Print parent info only once at the beginning
    if (getppid() != 1) { // Check if this is the original process
        printf("parent: pid=%d\n", getpid());
    }
    
    // Base case: no more elements to process
    if (size <= 0) {
        return;
    }
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    } else if (pid == 0) { // Child process
        // Calculate which child we are (first child, second child, etc.)
        int child_num = 1;
        printf("child%d: pid=%d, ppid=%d, %s\n", 
               child_num, getpid(), getppid(), data[0]);
        
        if (size > 1) {
            do_fork(data + 1, size - 1); // Recursive call with remaining data
        }
        exit(0); // Child exits after processing
    } else {
        // Parent waits for child to complete
        wait(NULL);
        exit(0); // Parent exits after child completes
    }
}
```

Expected output order:

```
parent: pid=...,
child1: pid=..., ppid=..., guitar
child2: pid=..., ppid=..., piano
child3: pid=..., ppid=..., violin
```

---

## Question 8 (4 Marks)

Consider a program where the parent forks a single child and uses a pipe between them.

**(a)** Explain what happens when the child calls `read` before the parent has written anything to the pipe.

> **Answer**: ________The read call will block until data is available or the pipe is closed__________________________

**(b)** Suppose the child exits before reading all of the data that the parent is writing. Explain the effect on the parent.

> **Answer**: _______________when the child exits, the pipe's read end closes. The parent's write might fail with SIGPIPE if the pipe's buffer is full___________________

**(c)** Suppose the parent does not close the pipe write descriptor. Does the program terminate normally? Explain.

> **Answer**: ____________No, then then child's read will never get EOF, potentially causing it hanf indefinitely______________________

**(d)** Explain the circumstances under which the write call in the parent could block.

> **Answer**: _____________write will block if the pipe buffer is full and there's no reader_____________________

---

## Question 9 (9 Marks)

Study the program that installs two signal handlers. Show the output when signals arrive at specified points.

| Event                                 | Output                                                           |
| ------------------------------------- | ---------------------------------------------------------------- |
| SIGTERM arrives at A                  | _"First", "Second", "Signal 3 received", process terminates_____ |
| SIGTERM arrives at B                  | ___"Done", "First", "Second", "Signal 3 received"___             |
| SIGQUIT arrives at B                  | ______                                                           |
| SIGTERM arrives at B and SIGTERM at C | ______                                                           |
| SIGTERM at B and SIGQUIT at D         | ______                                                           |
| SIGTERM at B and SIGTERM at D         | ______                                                           |

---

## Question 10 (7 Marks)

Identify three significant bugs in the server code fragment below and describe them. Then fix the bugs in the code on the next page.

```c
// Initialization
for (i = 0; i < MAXCLIENTS; i++)
  client[i] = -1;

fd_set fds;
FD_ZERO(&fds);
FD_SET(listenfd, &fds);
int maxfd = listenfd;

while (1) {
  int nready = select(maxfd+1, &fds, NULL, NULL, NULL);

  if (FD_ISSET(listenfd, &fds)) {
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &clilen);
    for (i = 0; i < MAXCLIENTS; i++)
      if (client[i] < 0) {
        client[i] = connfd;
        break;
      }
    FD_SET(connfd, &fds);
  }

  for (i = 0; i < MAXCLIENTS; i++) {
    sockfd = client[i];
    if ((sockfd > 0) && FD_ISSET(sockfd, &fds)) {
      n = read(sockfd, line, MAXLINE);
      printf("String = %s\n", line);
      write(sockfd, "Enter a number", 15);
      n = read(sockfd, line, MAXLINE);
      printf("Number = %d\n", atoi(line));
    }
  }
}
```

- **First bug**: ____________________________
    
- **Second bug**: ___________________________
    
- **Third bug**: ____________________________
    

_Fix the code on the next page._

---

## Question 11 (7 Marks)

**(a)** Write a shell script that adds every subdirectory of your current working directory whose name starts with `csc` to your `PATH` variable.

```sh
#!/bin/bash
for dir in */; do
    if [[ $dir == csc* ]]; then
        export PATH=$PATH:$PWD/${dir%/}
    fi
done
...
```

**(b)** Write a shell script that takes either one or two positive integer arguments. If only one integer is provided, print that number that many times (one per line). If two are provided, use the larger of the two.

```sh
#!/bin/bash
if [ $# -eq 1 ]; then
    num=$1
elif [ $# -eq 2 ]; then
    if [ $1 -gt $2 ]; then
        num=$1
    else
        num=$2
    fi
else
    echo "Usage: $0 number [number]"
    exit 1
fi

for ((i=1; i<=$num; i++)); do
    echo $num
done
...
```

---

_End of examination. Good luck!_