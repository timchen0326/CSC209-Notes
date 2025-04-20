### 🐚 Shell Programming Notes

#### 1. **Shell Variable Behavior**

```bash
foo=bar
bar=baz
read foo  # input: bip
```

- `foo`: "bip"
    
- `bar`: "baz"
    

```bash
foo=bar
bar=baz
read $foo  # input: bip
```

- `foo`: "bar"
    
- `bar`: "bip"
    

Note: `read foo` reads into the variable `foo`. But `read $foo` evaluates `$foo` first (which is "bar"), so input goes into `bar`.

#### 2. **Script: `whatday.sh`**

```bash
echo 'What day is it?'
read day
echo I love $day.
```

Example Run:

```bash
$ sh whatday.sh
What day is it?
Wednesday
I love Wednesday.
```

#### 3. **Adding an "s" Problem**

- Challenge: Modifying output to say "I love Wednesdays".
    
- Fix: Add the "s" manually, or use pattern matching to pluralize.

```bash
echo 'What day is it?'
read day
echo I love ${day}s.
```

#### 4. **Command Output Table**

|Expression|Error?|stdout/Error message|Return Value|
|---|---|---|---|
|`test 3 = 4`|No|(no output)|1|
|`tree=maple`|No||0|
|`test $tree`|Yes|test: =: unary operator expected|1|
|`test $undefined = something`|Yes|test: =: unary operator expected|1|
|`echo yes > file1`|No||0|
|`echo no > file2`|No||0|
|`diff file1 file2`|No|1c1||
|< yes||||

---

> no | 1 | | `cp file1 file3` | No | | 0 | | `diff file1 file3` | No | (no output) | 0 | | `grep es file3` | No | yes | 0 | | `value=3` | No | | 0 | | `expr value + 4` | Yes | expr: non-integer argument | 2 | | `expr $value * 4` | No | 12 | 0 |

#### 5. **Script: `weekday.sh`**

```bash
if test -z $day
then
    echo I don\'t know what day it is
elif test $day = "Sunday" || [ $day = "Saturday" ]
then
    echo "The weekend! Yipee!"
else
    echo "Back to work :("
fi
```

#### 6. **Detecting Empty Input**

- Solution: Use `test -z $day` to check for empty string.
    

#### 7. **Sherlock Files Comparison**

```bash
diff chapter1 chapter-one
```

- Use `diff` to find which file is corrected.
    

#### 8. **Finding the Odd File Among 0-9**

- Brute-force:
    

```bash
for i in `seq 0 9`
do
  next=`expr $i + 1`
  if diff $i $next
  then
    echo $i and $next are different
  fi
done
```

- Scalable solution: checksum comparison.
    

---

### 🔐 Embedded Ethics: The Ethics of Data Protection (Module 2)

#### 1. **Arguments by Analogy**

- Definition: Infer similarity in one respect due to similarity in another.
    
- Example: Peter Singer’s "Drowning Child" vs. Global Poverty.
    
    - If it's unethical to ignore a drowning child, it's unethical to ignore preventable deaths due to poverty.
        

#### 2. **Analogies for Hacking**

- Informal Poll:
    
    - Most analogous to hacking? **Breaking and entering**
        

#### 3. **Breaking & Entering vs. Hacking**

- Similarities:
    
    - Unauthorized access
        
    - Privacy violation
        
    - Property theft
        
- Conclusion:
    
    - If burglary is unethical, so is hacking.
        

#### 4. **The Morris Worm Case Study**

- Created by Robert Tappan Morris
    
- Exploited:
    
    - Weak passwords
        
    - Remote shell
        
    - Buffer overflow (fingerd)
        
    - sendmail flaws
        
- Did no damage but caused massive disruption due to reinstallation bug → DDoS
    
- Result: Probation, community service, fine.
    

#### 5. **Curious Burglar Analogy**

- Scenario: Burglar explores homes using hidden keys, takes nothing.
    
- Question: Is that still unethical?
    
- Goal: Evaluate ethics of non-malicious but unauthorized exploration.
    

#### 6. **Limitations of Analogies**

- Argument by analogy fails if compared cases are too dissimilar.
    

#### 7. **Software Vulnerabilities & Exploits**

- Vulnerability = Weakness in code
    
- Exploit = Using that weakness to breach security
    

##### Morris Worm Exploits:

1. Password guessing
    
2. Remote shell access
    
3. Buffer overflow
    
4. sendmail debug bypass
    

#### 8. **Buffer Overflow Explained**

- Overflows stack buffer
    
- Overwrites return address to redirect execution
    
- Example code:
    
    ```c
    char username[16];
    char password[16];
    scanf("%s", username);
    scanf("%s", password);
    ```
    
- Modern protections:
    
    - Stack guard
        
    - ASLR
        
    - Safer languages
        

#### 9. **Exploit Demo Overview**

- Disable protection: compile with `-fno-stack-protector`
    
- Use crafted input to overwrite return address → jump to `adminMenu()`
    
- Craft input with Python to create correct memory layout
    

```python
import sys
sys.stdout.buffer.write(b"bbbb")
mystring = "\n"+ "a"*40
sys.stdout.buffer.write(bytes(mystring, "utf8"))
sys.stdout.buffer.write(b"\x14\x1c\x40\x00\x00\x00\x00\x00")
```

#### 10. **Takeaways**

- Buffer overflows are dangerous but preventable.
    
- Safer languages or secure coding practices mitigate risk.
    

---

This concludes Week 11 materials. Make sure to review the C buffer overflow example thoroughly and understand the ethical frameworks applied to software vulnerabilities.