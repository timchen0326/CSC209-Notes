## Slide 1: Course Review Overview

- Introduction to the final review session
    
- Key topics: tools, languages, system programming, IPC, networking
    

## Slide 2: Programming Skills and Best Practices

- Choose the right tools for each task
    
- Write clear, maintainable code:
    
    - Consistent formatting and naming
        
- Handle errors gracefully with informative messages
    
- Develop and run tests at unit and integration levels
    
- Collaborate effectively:
    
    - Use version control and code reviews
        
    - Keep personal ego aside
        

## Slide 3: Office Hours and Review Sessions

- Office hours available until April 17 (check announcements)
    
- In‑person review sessions (no recordings or slides provided):
    
    - Monday April 21, 10:00–12:00 or 14:00–16:00
        
    - Tuesday April 22, 10:00–12:00 or 14:00–16:00
        

## Slide 4: Final Exam Logistics

- Confirm time and location independently
    
- Bring student card or government‑issued photo ID
    
- Arrive 20 minutes early; full 3‑hour duration guaranteed
    
- Store all electronic devices and unauthorized materials in a bag
    
- Devices must be fully powered off
    

## Slide 5: Exam Format and Coverage

- Three‑hour exam similar to term tests
    
- Question types:
    
    - True/False
        
    - Multiple choice (including “select all that apply”)
        
    - Fill in the blank
        
    - Short explanations
        
    - Code output and error‑finding questions
        
    - Function or program writing
        
- Topics included:
    
    - All lecture and lab material
        
    - PCRS videos and assignments
        
    - Ethics module
        
    - Shell programming, sockets, `select`
        

## Slide 6: Unix/Linux Tools

- File system hierarchy and permissions
    
- Essential commands and utilities
    
- Makefiles for build automation
    
- Git for version control
    
- Debugging tools (e.g., gdb)
    

## Slide 7: Shell Scripting Fundamentals

- Standard streams: stdin, stdout, stderr
    
- I/O redirection: `>`, `<`, `2>`
    
- Job control: `&`, `fg`, `bg`, `jobs`
    
- Pipes: `|`
    
- Quoting rules:
    
    - Single vs. double quotes vs. backquotes
        
- Variables and positional parameters
    
- `test`, `read`, `expr` for checks, input, and arithmetic
    

## Slide 8: Programming in C

- Basic syntax, control flow, and functions
    
- Data types: arrays, structs, pointers, function pointers
    
- Memory model:
    
    - Stack vs. heap allocation
        
    - `malloc`/`free` and avoiding memory leaks
        
- Strings:
    
    - Null termination and safe library functions
        

## Slide 9: Header Files and Build Systems

- Use headers for declarations and type definitions only
    
- Avoid definitions of functions or globals in headers
    
- Separate compilation with Makefiles for efficiency
    

## Slide 10: System Calls and Error Handling

- Kernel interface for file and process management
    
- Common calls: `open`, `read`, `write`, `close`, `fork`, `exec`, `wait`
    
- Check return values and use `errno` for diagnosing errors
    

## Slide 11: Process Management

- Process states: running, ready, blocked
    
- `fork()` to create child processes
    
- `exec()` to replace process image
    
- Managing zombies and orphans:
    
    - `wait()`, `waitpid()`, and status macros
        

## Slide 12: Inter‑Process Communication (IPC)

- Files, pipes, and sockets for message passing
    
- Pipes: parent–child, unidirectional, same‑machine only
    
- Sockets: network‑transparent, bidirectional
    

## Slide 13: Streams vs. File Descriptors

- Streams (FILE*) for buffered I/O with `fopen`, `fprintf`, etc.
    
- File descriptors (int) for low‑level I/O with `open`, `read`, `write`
    
- Use descriptors for sockets and pipes
    

## Slide 14: Signals

- Software interrupts for asynchronous events
    
- Examples: Ctrl‑C, child termination, floating‑point errors
    
- Use `kill()` to send signals and `sigaction()` to install handlers
    

## Slide 15: Socket Programming

- TCP/IP model: addresses, ports, and protocols
    
- Server workflow: `socket()`, `bind()`, `listen()`, `accept()`
    
- Client workflow: `socket()`, `connect()`
    
- Handle network byte order (`htonl`, `ntohl`)
    
- Socket types: `SOCK_STREAM` (TCP), `SOCK_DGRAM` (UDP)
    

## Slide 16: Multiplexed I/O with `select`

- Monitor multiple file descriptors simultaneously
    
- Use `FD_SET`, `FD_ISSET`, `FD_ZERO` to manage descriptor sets
    
- Enables efficient single‑process handling of concurrent I/O
    

## Slide 17: File Interface

- Uniform interface (`open`, `read`, `write`, `close`) for files, pipes, sockets, and devices
    
- The Unix philosophy: treat everything as a file
    

## Slide 18: Unix Philosophy Summary

- Build small tools that do one thing well
    
- Design for composability via standard interfaces and text streams
    

---

_Best of luck on your exam!_