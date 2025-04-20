## Shell Programming Part 1

### Variable Assignment and Substitution

- Assign a value:
    
    ```sh
    d=31
    ```
    
- Use variable in string:
    
    ```sh
    echo March has $d days
    ```
    

### Arithmetic with Variables

- Subtract 1 from a variable `x`:
    
    ```sh
    expr $x - 1
    ```
    
- Calculate area from `width` and `height`:
    
    ```sh
    area=`expr $width \* $height`
    ```
    
    > Note: `\*` is used to escape the asterisk in shell.
    

---

## Shell Programming Part 2

### Conditional Statements

- If statement to check if `temp > 0`:
    
    ```sh
    if [ $temp -gt 0 ]
    then
        echo Above freezing
    fi
    ```
    

### Boolean Operators in Test

- Boolean AND operator:
    
    ```sh
    -a
    ```
    

### Discarding Output

- Redirect output to nowhere:
    
    ```sh
    /dev/null
    ```
    
    > Usage: `command > /dev/null` or `command 2> /dev/null`
    

---

## Shell Programming Part 3

### Listing Directory Contents

- Valid commands to list contents:
    
    ```sh
    ls
    'ls'
    "ls"
    ```
    
    > Uppercase `LS` is not valid; shell is case-sensitive.
    

### Arithmetic Evaluation

- Given `week=12`, expressions that return `2`:
    
    ```sh
    expr $week - 10
    'expr $week - 10'
    ```
    
    > Quoting the entire expression works, but quoting individual elements like `'expr' '$week' - 10` is invalid.
    

### Using `seq` Command

- Output even numbers from 2 to 100:
    
    ```sh
    seq 2 2 100
    ```
    
    > `seq` works like Python’s `range(start, step, end)`
    

---

These notes are based on PCRS Week 11 content and include the key shell scripting syntax and logic introduced in the exercises and videos. Remember to test commands in a Unix environment for better understanding.