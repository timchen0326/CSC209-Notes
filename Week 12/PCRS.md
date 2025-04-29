## Follow‑up Question 4a

- **Script (`shifter.sh`):**
    
    ```sh
    echo I live at $1 $2 $3.
    shift
    echo Now, I live at $0 $1 $2.
    ```
    
- **Invocation:** `sh shifter.sh 100 University Ave`
    
- **Positional parameters before `shift`:**
    
    - `$1` = `100`
        
    - `$2` = `University`
        
    - `$3` = `Ave`
        
- **Output before `shift`:**
    
    1. `I live at 100 University Ave.`
        
- **Effect of `shift`:**
    
    - Discards the first argument (`$1`) and shifts all parameters left.
        
    - `$0` remains the script name (`shifter.sh`).
        
    - New values:
        
        - `$1` = original `$2` = `University`
            
        - `$2` = original `$3` = `Ave`
            
- **Output after `shift`:** 2. `Now, I live at shifter.sh University Ave.`
    

## Follow‑up Question 4b

- **Given:** `subject=CSC`
    
- **Goal:** Print “Last week of CSC209” by concatenating `209` to the variable.
    
- **Solution:**
    
    ```sh
    echo Last week of ${subject}209
    ```
    
    - The braces (`{}`) ensure the shell treats `subject` as a complete variable name before appending `209`.
        

## Follow‑up Question 4c

- **Question:** In a shell script, which variable holds the number of supplied arguments?
    
- **Answer:** `$#`  
    Expands to the count of command‑line arguments passed to the script.