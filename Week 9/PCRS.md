### 🔔 Introduction to Signals

- A **signal** is a limited form of inter-process communication (IPC) used to notify a process that a specific event has occurred.
    
- Can be sent by:
    
    - The **Operating System** (e.g., `SIGSEGV`, `SIGKILL`)
        
    - A **user process** (e.g., `kill` command)
        

#### Key Properties

- Signals are **asynchronous**.
    
- A signal can be sent to a process **regardless** of parent/child relationship.
    
- The `kill` command **sends** signals (it doesn't just terminate a process).
    
- The arrival of a signal is generally **unpredictable**.
    

#### False Statements

- A signal can **not** only be sent to child/parent processes.
    
- A signal can be sent to **any process** (with permission).
    
- A signal can **not** only be sent to processes writing to stdout.
    

---

### 🛠 Handling Signals in C

#### Using `sigaction`

```c
struct sigaction act;
act.sa_handler = handler;     // Function to handle the signal
act.sa_flags = 0;
sigemptyset(&act.sa_mask);   // No signals blocked during handler execution
sigaction(SIGINT, &act, NULL); // Bind SIGINT (Ctrl+C) to handler
```

#### Handler Function Signature

```c
void handler(int sig) {
    // Code to handle signal
}
```

- Must always have the signature: `void function(int)`
    

#### Immutable Behavior

- The default action of **SIGKILL** **cannot** be overridden.
    
- Installing a signal handler involves:
    
    - Writing a function with the correct signature
        
    - Calling `sigaction()` and passing the function via `act.sa_handler`
        

#### Timing Matters

- If a signal arrives **before** calling `sigaction()`, the **default** action is taken.
    

---

### 💻 Program Behavior with Signals

#### Base Program:

```c
int x = 5;

void handler(int sig) {
    x += 3;
    fprintf(stderr, "inside %d ", x);
}

int main() {
    fprintf(stderr, "start ");            // POSITION A

    struct sigaction act;
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGINT, &act, NULL);

    x += 2;                                // POSITION B

    fprintf(stderr, "outside %d", x);     // POSITION C
    return 0;
}
```

#### Output Scenarios:

- **No Interruption**:
    
    - Output: `start outside 7`
        
- **Ctrl+C at POSITION A**:
    
    - Output: `start`
        
    - No handler is set yet
        
- **Ctrl+C at POSITION B**:
    
    - Output: `start inside 8 outside 10`
        
    - `x = 5 → +3 = 8 (in handler) → +2 = 10`
        
- **Ctrl+C at POSITION C**:
    
    - Output: `start inside 10 outside 10`
        
    - `x = 5 + 2 = 7`, then Ctrl+C → `x += 3 → 10`
        

---

### ✅ Summary

- Signals are a mechanism for process-level notifications.
    
- Use `sigaction` to define custom handlers.
    
- Always define your handler with `void handler(int sig)`.
    
- Default actions (like for SIGKILL) can't be changed.
    
- Signal timing matters — handler must be installed **before** signal arrives for it to be used.
    

---