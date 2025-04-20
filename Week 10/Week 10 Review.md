## 🕸️ Intro to Networking (from `IntroNetworking.pdf`)

### 🌐 The Web and HTTP Requests

- **HTTP Request/Response Structure**:
    
    - Request: `GET / HTTP/1.1\nHost: markusproject.org`
        
    - Response: `HTTP/1.1 200 OK\n...`
        
- **Finding Servers**:
    
    - Every computer has an IP address (e.g. 69.164.221.145).
        
    - Domain Name System (DNS) translates domain names to IPs via:
        
        - Local Name Server ➝ Root Server ➝ "org" Server ➝ Delegate Server.
            
    - Can take ~8 messages for DNS resolution.
        

### 🧱 TCP/IP Model & Communication

- **TCP (Transmission Control Protocol)**:
    
    - Reliable, connection-oriented protocol.
        
    - Uses 3-way handshake: `SYN` ➝ `SYN-ACK` ➝ `ACK`.
        
    - Provides sequence numbers and acknowledgements.
        
- **Sockets**:
    
    - A communication endpoint = IP Address + Port.
        
    - Example: 128.100.31.200:80.
        
- **Port Types**:
    
    - 0–1023: Well-known (80=HTTP, 22=SSH).
        
    - 1024–49151: Registered.
        
    - 49152–65535: Dynamic/private.
        

### 📨 Data Transmission & Routing

- Data is split into TCP packets ➝ encapsulated in IP packets.
    
- Each packet includes headers (e.g., sequence number, checksum).
    
- Routing involves hops across networks (e.g., routers, ISPs).
    
- Network path may span cities, countries, and layers of providers.
    

### 🔐 HTTPS (TLS)

- Protocol above TCP providing encryption.
    
- Negotiates encryption protocol & keys.
    
- Encrypts all TCP data.
    

### 🧠 Key Takeaways

- Web = complex stack of layers.
    
- Each layer (HTTP, TCP, IP) serves a role.
    
- Understanding each layer helps in designing new systems.
    

---

## 🧪 Week 10: Select & I/O Models (from `Week10-Select.pdf`)

### 🧨 The Problem

- Blocking I/O with `read()` or `accept()` can cause issues:
    
    - If one source blocks, server stalls ➝ denial of service.
        
    - Common naive solution: one process per client (fork).
        

### 🧵 I/O Models

1. **Blocking I/O**:
    
    - Process blocks on `read()` until data is ready.
        
2. **Non-blocking I/O**:
    
    - `read()` returns immediately with EWOULDBLOCK if no data.
        
    - Requires polling repeatedly.
        
3. **I/O Multiplexing**:
    
    - Use `select()` to wait on multiple fds.
        
    - Process blocks until any fd is ready.
        

### 🔧 `select()` System Call

```c
int select(int maxfdp1,fd_set *readset, fd_set *writeset,
           fd_set *exceptset, const struct timeval *timeout);
```

- `maxfdp1` = max fd + 1.
    
- `timeout`:
    
    - NULL ➝ wait forever.
        
    - 0 ➝ check immediately.
        
    - (x, y) ➝ wait up to x sec + y usec.
        
- Returns when:
    
    - A descriptor is ready.
        
    - Timeout is reached.
        

### 📥 Readiness Conditions

- **Readable**: data in receive buffer, end-of-file state on file descriptor, socket is a listening socket and there is a pending connection, socket error is pending
    
- **Writable**: space in write buffer, a socket error is pending
    
- **Exceptions**: TCP out-of-band data.
    

### 🧰 Macros for FD manipulation

```c
FD_ZERO(&set);
FD_SET(fd, &set);
FD_CLR(fd, &set);
FD_ISSET(fd, &set);
```

- `fd_set` is typically a bit array.
    
- `FD_SETSIZE` determines max fds you can track.
    

### 🧪 select() Example

```c
fd_set rfds;
struct timeval tv;
FD_ZERO(&rfds);
FD_SET(STDIN_FILENO, &rfds);
tv.tv_sec = 5; tv.tv_usec = 0;
retval = select(1, &rfds, NULL, NULL, &tv);
```

- Monitors stdin for 5 seconds.
    
- Return values:
    
    - -1: error.
        
    - 0: timeout.
        
    - > 0: input available.
        

### 🔄 select Loop Pattern

```c
for (;;) {
  rset = allset;
  nready = select(maxfd + 1, &rset, NULL, NULL, NULL);
  if (FD_ISSET(listenfd, &rset)) {
    connfd = accept(...);
    FD_SET(connfd, &allset);
    if (connfd > maxfd) maxfd = connfd;
  }
  for (i = 0; i <= maxi; i++) {
    if ((sockfd = client[i]) < 0) continue;
    if (FD_ISSET(sockfd, &rset)) read(sockfd, ...);
  }
}
```

### 📏 End of Line Conventions

- `\r` (CR), `\n` (LF), or both:
    
    - Unix: `\n`
        
    - Windows: `\r\n`
        
    - Mac Classic: `\r`
        
- **Standard line ending for network:** `\r\n`
    

### 🔢 Byte Order

- **Big-endian vs. Little-endian**:
    
    - Intel = little-endian.
        
    - Network byte order = big-endian.
        
- Convert using:
    

```c
unsigned short htons(), ntohs();
unsigned long htonl(), ntohl();
```

### 🧮 Bitstring FD Sets

- Abstract structure:
    

```c
typedef struct {
  unsigned int field[N];
} Bitstring;
```

- Bit manipulation:
    

```c
set(), unset(), ifset(), setzero()
```

- Useful for handling descriptor sets efficiently.
    

---

These notes follow the order of `IntroNetworking.pdf` then `Week10-Select.pdf`, and should be perfect for Obsidian Markdown. Let me know if you'd like code examples from the `.c` files integrated into the explanations.