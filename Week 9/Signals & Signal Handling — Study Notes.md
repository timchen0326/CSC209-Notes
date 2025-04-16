### 🧠 Concept Overview

Signals are a form of limited inter-process communication (IPC) used to notify a process that a particular event occurred.

---

### ⚙️ Signal Basics

- **Signal:** A small message sent to a process to notify it of an event (e.g., `SIGINT`, `SIGUSR1`).
    
- **Common commands:**
    
    - `kill -SIGNAL pid`: Sends a signal to the process.
        
    - `ps aux | grep <username>`: Find your process' PID.
        
    - `fg`: Bring a background job to the foreground.
        
    - `./program &`: Run in background.
        

---

### 🧪 Exercise Breakdown

#### 1. Write an Infinite Loop

```c
int main() {
    while (1) {}
    return 0;
}
```

#### 2. Foreground/Background

- Run: `./greeting` → Ctrl+C to kill.
    
- Background: `./greeting &` → check with `ps`.
    
- Bring back: `fg`.
    

#### 3. Kill from Another Terminal

- Find PID using `ps aux | grep <username>`.
    
- Kill with: `kill <pid>` or `kill -SIGUSR1 <pid>`.
    

#### 4. Signal Handler Signature

```c
void handler(int sig);
```

Must accept exactly one `int` parameter.

#### 5. Write `sing` Function

```c
void sing(int sig) {
    printf("Happy birthday to you,\n");
    printf("Happy birthday to you,\n");
    printf("Happy birthday dear <name>,\n");
    printf("Happy birthday to you!\n");
}
```

#### 6. Use `argv[1]` for Name

- Can't change `sing`'s signature → use global variable:
    

```c
char *name; // global
```

#### 7. Install Signal Handler (SIGUSR1)

```c
struct sigaction sa;
sa.sa_handler = sing;
sa.sa_flags = 0;
sigemptyset(&sa.sa_mask);
sigaddset(&sa.sa_mask, SIGINT);
if (sigaction(SIGUSR1, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
}
```

#### 8. Trigger the Signal

- Run greeting program.
    
- In another window: `kill -SIGUSR1 <pid>`.
    
- It should sing.
    

#### 9. Add Delay (simulate long execution)

```c
sleep(5); // inside sing
```

Send `SIGINT` during song — may interrupt mid-way.

#### 10. Block `SIGINT` During `sing`

```c
sigaddset(&sa.sa_mask, SIGINT);
```

- Prevents `SIGINT` from being delivered during `sing` execution.
    

#### 11. Behavior of Ctrl+C during `sing`

- If SIGINT is blocked, Ctrl+C will be deferred until after `sing` finishes.
    
- Otherwise, it may interrupt the song.
    

---

### 🛠 Useful C Functions

```c
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
int sigemptyset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
```

---

### 🎵 Final Code Summary

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

char *name;

void sing(int sig) {
    printf("Happy birthday to you,\n");
    printf("Happy birthday to you,\n");
    sleep(5);
    printf("Happy birthday dear %s,\n", name);
    printf("Happy birthday to you!\n\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s name\n", argv[0]);
        exit(1);
    }

    name = argv[1];

    struct sigaction sa;
    sa.sa_handler = sing;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    sigaddset(&sa.sa_mask, SIGINT);

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    for (;;) {
        printf("Go away, I'm studying\n");
        sleep(6);
    }
    return 0;
}
```