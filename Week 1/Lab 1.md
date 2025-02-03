# 📌 CSC209 Lab 1 Midterm Study Guide

This guide covers **everything** you need for Lab 1, including **Unix shell commands, file permissions, I/O redirection, pipes, compiling programs, C programming concepts, dynamic memory allocation, and ethics**.

---

## 🖥️ Introduction to Unix Shell and Git
Lab 1 focuses on **navigating the Unix shell, using Git, compiling and executing C programs, and writing shell scripts**.

### 📌 Git Basics
Git is used for **version control**. You must **clone, commit, and push** changes correctly.

#### 📝 Essential Git Commands
```bash
# Clone the repository from MarkUs
git clone <repo_url>

# View repository content
ls

# Check status of your changes
git status

# Add a file to be committed
git add <filename>

# Commit changes with a message
git commit -m "Your commit message"

# Push changes to MarkUs
git push

# Remove unwanted files from the repo
git rm <filename>
```
⚠ **Do NOT commit compiled executables (\`a.out\` or other binaries), as they break tests.**

---

## 📌 Unix Shell Commands and Navigation

### 🔍 Navigating the File System
```bash
# Print working directory
pwd

# List files in a directory
ls

# List detailed information about files
ls -l

# List hidden files
ls -a

# Change directory
cd <directory_name>

# Move up one level
cd ..

# Create a directory
mkdir <directory_name>

# Remove a file
rm <filename>

# Remove a directory recursively
rm -r <dir>
```

---

## 📌 File Permissions in Unix

### 🔍 Viewing File Permissions
```bash
# View file permissions
ls -l
```
Example output:
```
-rw-r--r-- 1 user user 1234 Feb 2 12:34 myfile.txt
```
- \`rw-\` → Owner can read & write.
- \`r--\` → Group can read.
- \`r--\` → Others can read.

### 🔐 Changing File Permissions
```bash
# Make a script executable
chmod +x myscript.sh

# Change file permissions for all users
chmod a+rwx myfile.txt
```
⚠ **Ethical concern:** If a classmate sets \`drwxr-xr-x\` permissions on their home directory, **you should not access their files without permission**.

---

## 📌 Compiling and Running C Programs

### 🔨 Compiling with \`gcc\`
```bash
# Compile a C program
gcc -Wall -g -o program_name source_code.c
```
- \`-Wall\` → Enables warnings.
- \`-g\` → Includes debugging info.
- \`-o <output>\` → Names the executable.

### 🎯 Running a C Program
```bash
# Compile a C program
gcc -Wall -g -o program_name source_code.c
```
```bash
./program_name
```
If no output file is specified:
```bash
gcc program.c   # Creates a.out
./a.out
```

⚠ **Issue with overwriting executables:**  
If multiple files are compiled without \`-o\`, they overwrite \`a.out\`. Use \`-o\` to name each executable.

---

## 📌 Shell Scripts (\`compile_all.sh\` and \`my_commands.sh\`)

### 📝 Writing \`compile_all.sh\`
A script that compiles multiple C files:

```bash
#!/usr/bin/env bash

gcc -Wall -g -o count count.c
gcc -Wall -g -o echo_arg echo_arg.c
gcc -Wall -g -o echo_stdin echo_stdin.c
gcc -Wall -g -o hello hello.c
```

**Make it executable:**
```bash
chmod +x compile_all.sh
```

**Run the script:**
```bash
./compile_all.sh
```

---

### 📝 Writing \`my_commands.sh\`
This script demonstrates **I/O redirection and pipes**:
```bash
#!/usr/bin/env bash

./echo_arg csc209 > echo_out.txt   # Redirect output to a file
./echo_stdin < echo_stdin.c        # Read input from a file
./count 210 | wc -m                # Pipe output of count into wc -m
ls -S | head -n 1 | ./echo_stdin   # Find the largest file and print its first line
```

---

## 📌 Standard Input, Output, and Error

### 📤 Redirecting Output
```bash
# Redirect standard output (stdout) to a file
command > output.txt

# Redirect standard error (stderr) to a file
command 2> error.txt

# Redirect both output and error
command > output.txt 2>&1

# Read input from a file (stdin)
command < input.txt
```

---

## 📌 Pipes (\`|\`)
Pipes allow output of one command to be used as input for another.

### 📝 Example Commands
```bash
# Count number of lines in a file
cat file.txt | wc -l

# Sort files by size and get the largest file
ls -S | head -n 1

# Find and print the first line of the largest file
ls -S | head -n 1 | ./echo_stdin
```

---

## 📌 Ethics and Privacy Concerns

### 🤔 Ethical Dilemma: Viewing a Classmate’s Files
If a classmate **incorrectly sets file permissions** to allow public access, should you look at their files?
- **No, it is unethical.**
- Even if they mistakenly allowed access, they did **not give explicit permission.**
- Violates **privacy** and can cause harm (e.g., exposing personal/academic data).

### 📝 Ethical Theories Applied
- **Harmless Wrong:** Even if no harm occurs, accessing files **violates trust**.
- **Psychological Harm:** The owner may feel **violated** upon discovery.
- **Economic & Academic Harm:** Could lead to **cheating accusations** or **misuse of information.**

⚠ **Conclusion:** **DO NOT access others’ files without explicit permission.**