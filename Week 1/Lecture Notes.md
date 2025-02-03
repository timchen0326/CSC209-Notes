### **CSC209: Software Tools and Systems Programming - Lecture 1.1**

📌 **Introduction to CSC209**

- Course focuses on software tools and systems programming.
- Importance of using the command line, working with files, and programming in C.

📌 **Key Questions**

- What does it mean to run a program?
- What is a program, file, and running program?

📌 **The Shell**

- `$` is the shell prompt.
- The shell:
    - Accepts commands as input.
    - Finds and executes the corresponding program.
    - Passes arguments to the program.
- Some commands are built-in, others are external (e.g., `gcc -Wall -g -o hello hello.c`).

📌 **Shell Demonstration**

- Understanding standard input/output, redirection, and piping.

📌 **Course Info & Communication**

- Piazza for technical discussions.
- Email for personal matters.
- Office hours for direct help.

📌 **Assignments & Labs**

- Use **Git** to manage and submit assignments on **MarkUs**.
- Code must work on `teach.cs` to get full marks.
- Weekly labs, due Fridays at 10 PM.

📌 **Software Setup**

- Learn **SSH** for remote access.
- Use an editor like **vim, VS Code, nano, Emacs**.

📌 **Academic Integrity**

- Plagiarism is a serious offense.
- Do not share or search for assignment solutions online.
- Cite sources if reusing code.

📌 **Unix Principles & Basic Tools**

- Do one thing well, use **plain text** for simplicity.
- Standard Unix commands:
    - `cd` (change directory), `ls` (list files), `rm` (remove files).
    - `chmod` (change file permissions), `grep` (search text), `wc` (word count).

---

### **Embedded Ethics - Lecture 1.2**

📌 **Introduction to Ethics in Computer Science**

- A collaboration between **philosophy and computer science**.
- Goal: Embed ethics into technical decisions.

📌 **File Management in UNIX**

- A **file** is a sequence of bytes stored on a device.
- The **file system** organizes files and stores metadata (owner, permissions, etc.).
- Directories are **special files** that map filenames to their data.
- plan text documents are files
- executables are files
- directories are files
- "root" directory - "/"
- directory(folder) is a file that contains mapping of filenames to their **data** and **metadata**
- **metadata** is the information kept about a file
![[Screenshot 2025-02-02 at 4.36.53 PM.png]]
📌 **Shared Systems & File Permissions**

- On shared systems (e.g., `teach.cs`), permissions protect user files.
- **Permissions structure (`rwx` for user, group, others)**:
    - `chmod 755 filename` (sets permissions using octal notation).
    - `chmod u+rwx, go-x` (symbolic notation).
![[Screenshot 2025-02-02 at 4.37.32 PM.png]]
📌 **Privacy Concerns**

- Users share computational resources and storage.
- Privacy risks include exposure of chat history, grades, and login times.
- **Types of privacy harms** (Citron & Solove, 2021):
    - Physical, Economic, Reputational, Discriminatory, Relationship, Psychological.

📌 **Harmless Wrongs**

- Ethical dilemma: **Is it wrong to access someone’s public file if they never find out?**
- **Derek Parfit’s view**: Your life can be worse due to things you’re unaware of (e.g., fake friendships).

📌 **Why This Matters for Computer Scientists**

- Handling **sensitive user data** responsibly is crucial in professional settings.