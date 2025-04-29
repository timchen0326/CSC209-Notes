# Error Checking

- buffer overflow
	- lets say have char arr[8] = "Foot" and then i use strncat (arr, "ball", 4); which would require 5 bytes but there are only 3 bytes remain in arr, so the write overruns the buffer
	- this is a runtime error, since it compiles properly
- yes
- regular error, just doesnt work as intended
	- have a char name[6] = "cheng", when strncpy(name, "Xu, 2) printf("%s\n", name;) prints Xueng instead of the intended cheng
- runtime error
	- *s = "Hello"; points to a string literal in read-only meory, no spance for appnded text, so strcat will cause undefined behaviour.
- logic error
	- ![[Pasted image 20250422210753.png]]
- calling ptr[0] on *ptr is viable.   
- Struct course { char code[7];} can be called and replaced using c.code[3] when used
- runtime error
	- int **data;
	- data = malloc(sizeof(int*) *3)
	- data[0][0] is uninitialized since it only references data[0], data[1], and data[2] and others are consider garbage pointer
	- causes runtime error since dereferencing uninitialized pointer
- runtime error
	- cannot just write *p = 100 since its declaring pointer p to an int, but p isnt valid anywhere else. p wasn't initialized so it holds garbage address, so it causes runtime error.

Pointer
- if str points at a literal, writing '\0' at end+1 is undefined behaviour
- didnt call free for the returned pointer, but we didnt allocate new storage so might lead to error
- stack-frame string: would return a pointer into a local array that is freed on return
- string literal: although static, cannot be modified or freed by the coller- calling free() it would crash

SEEK_SET treats offsett as an absolute position, measured in bytes from the start of the file
SEEK_CURR treats offset from the current fie position.

parent would know a particular child is finished sending length when the parent perform a read() on the pipe connected to that child. Once that child closes its write end, further read() calls on the parent's read end will return 0. zero-byte return signals that the child is done sending.

infinite loop because read is never returning
- forgot to close the write end of the pipe after forking, as long as any process holds taht descriptor open, the parents read() will block waiting for EOF. closing the unused write end and the write end in the child once its done sending ensure read() return 0 to signal End of file.
pipe
```c
close(fd[j][0]) // closing read end

close(fd[j][1]);        // close write ends not belonging to this child
```

%.o: %.c lib.h means that any .c files is relied on lib.h to compile to .o files, so modifying lib.h, needs to be recompiled

### Three blocking system calls [3 MARKS]

1. **`accept(int sock, struct sockaddr *addr, int *addrlen)`**  
    Blocks when no incoming connection is pending on the listening socket; unblocks when a new TCP connection arrives on `sock`. ​
    
2. **`ssize_t read(int d, void *buf, size_t nbytes)`**  
    Blocks when reading from a blocking descriptor (e.g. a pipe or socket) if no data is available; unblocks when data arrives (or returns 0 on EOF). ​
    
3. **`int wait(int *status)`**  
    Blocks the calling process until one of its child processes terminates; unblocks when a child exits (at which point `status` is set). ​

if struct node *head, then creating a new struct in side the function is the same struct node *next

```bash
grep '^LEC02' grades.txt \
  | cut -d' ' -f4,3 \
  | sort -nr \
  | head -3 \
  | cut -d' ' -f2

```

The `-k2,2nr` flag to `sort` actually bundles three pieces of information:

1. **`-k2,2`**  
    This tells `sort` to use **field 2 only** as the sort key. The syntax is `-k<start>,<end>`, so `2,2` means “start at field 2 and end at field 2” (fields are delimited by whitespace by default) ​csc209h-d18.
    
2. **`-n`**  
    After extracting the key (field 2), `-n` makes `sort` interpret that field **numerically** rather than lexicographically, so `100` ranks above `9` ​csc209h-d18.
    
3. **`-r`**  
    The `r` flag reverses the sort order, giving you **descending** rather than ascending order ​csc209h-d18.
    

Putting it all together, `sort -k2,2nr` says:

> “Sort the lines by field 2 only, comparing that field as numbers, and output the largest values first.”

stdio.h
signal.h
unistd.h
stdlib.h

```c
struct sigaction sa;
sa.sa_handler = sing;    // use our handler function
sa.sa_flags   = 0;       // no special flags

// Initialize the signal‐mask set to empty
if (sigemptyset(&sa.sa_mask) == -1) {
    perror("sigemptyset");
    exit(1);
}

// Add SIGINT to the mask so it’s blocked during handler execution
if (sigaddset(&sa.sa_mask, SIGINT) == -1) {
    perror("sigaddset");
    exit(1);
}

// Install for SIGUSR1
if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
}

```

kill sends signal to another process group
sockets select


int FD ISSET(int fd, fd set *fds);  test wither fd is a member of *fds
void FD SET(int fd, fd set *fds);  set fd in *fds
void FD CLR(int fd, fd set *fds);  remove fd from *fds
void FD ZERO(fd set *fds); clears *fds
