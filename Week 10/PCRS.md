## Bit Manipulation and Flags

### Bitwise Operators (Video 1)

- Bitwise AND (`&`) and logical AND (`&&`) differ:
    
    - `8 && 7` evaluates to `true` because both are non-zero.
        
    - `8 & 7` performs a bitwise AND: `0b1000 & 0b0111 = 0b0000` → `0` (false)
        
    - However, `8 & 7 = 0` is incorrect. Actual: `0b1000 & 0b0111 = 0b0000` = `0` (false)
        
- In C:
    
    ```c
    int x, y;
    int a = 2, b = 8;
    x = a | b; // 2 | 8 = 10 (bitwise OR)
    y = a || b; // 2 || 8 = 1 (logical OR)
    ```
    

### The Shift Operator (Video 2)

- Binary position: In `0000 1000`, **bit 3** is set to 1.
    
- Left shift `<<` example:
    
    - `x = 77` → binary: `0100 1101`
        
    - `x << 2` → `0001 1010 0` → 308 in decimal (but only lower bits kept in `char`)
        

### Bit Flags (Video 3)

- `S_IRGRP` is a constant from `<sys/stat.h>`.
    
- File flags (e.g., `O_RDONLY`, `O_WRONLY`) are bit flags combined using `|`, **not** `||`.
    
- Reasons to use bit flags:
    
    - Space efficiency
        
    - Fast operations
        
    - Defined in system libraries
        
    - Used in `chmod` with octal (base-8) representation
        

### Bit Vectors (Video 4)

- Expression:
    
    ```c
    int index = value / INTSIZE;
    return ( (1 << (value % INTSIZE)) & b->field[index]);
    ```
    
    - Checks if a bit is set in a bit array.
        

---

## Multiplexing I/O

### The Problem with Blocking Reads (Video 1)

- A file descriptor can refer to either end of a pipe.
    
- If a process is blocked on `read()`, it **cannot** execute other instructions.
    
- `read()` returns when data is available or writing end is closed.
    
- If no writers on the pipe, `read()` **does not block**, it returns `0`.
    
- Blocked on one pipe = can't read from another pipe.
    

### `select()` System Call (Video 2)

- Used to monitor multiple file descriptors.
    
- Return value: how many descriptors are ready.
    
- Can monitor read/write/error via arguments.
    
- Macros used to manipulate fd sets:
    
    - `FD_ZERO`, `FD_SET`, `FD_CLR`, `FD_ISSET`
        
- `select()` modifies the fd sets passed.
    
- Set write and error fd sets to `NULL` if only interested in read.
    

---

## Sockets

### Intro to Sockets (Video 1)

- Web servers typically use **port 80**.
    
- To support datagrams (UDP), pass `SOCK_DGRAM` to `socket()`.
    

### Socket Configuration (Video 2)

- `bind()` works for: **both AF_INET and AF_INET6**.
    
- `127.0.0.1` is the localhost IP address.
    
- `htons` is used to convert host to network byte order (short).
    

### Setting Up a Connection (Video 3)

- `accept()`:
    
    - Returns -1 on failure
        
    - Blocking call (waits for connection)
        
- Both server and client use `socket()`.
    
- Only server uses `accept()`.
    
- To resolve hostnames to IP: `getaddrinfo`
    

### Socket Communication (Video 4)

- Server-side system calls:
    
    - `socket`, `bind`, `listen`, `accept`
        
- Client-side system calls:
    
    - `socket`, `connect`
        

---

**End of Week 10 Notes**