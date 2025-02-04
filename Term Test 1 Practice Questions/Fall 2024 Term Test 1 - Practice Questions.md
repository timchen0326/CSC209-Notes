## **Question 1: Missing Types (3 marks)**

Fill in the missing types so that the program compiles and runs correctly.

```c
int temps[4];

__________ hilo[2];

int *p = malloc(sizeof(____________ * 2);

hilo[0] = &temps[0];

hilo[1] = p;

___________ q = hilo;

___________ r = q[0];

___________ s = *(hilo[1]);

___________ t = temps[0];
```

**Answer:**

```c
int temps[4];

____int *______ hilo[2];

int *p = malloc(sizeof(_____int)_______ * 2);

hilo[0] = &temps[0];

hilo[1] = p;

__int_____**____ q = hilo;

__int __*_______ r = q[0];

_____int ______ s = *(hilo[1]);

_____int______ t = temps[0];
```

---

## **Question 2: Command Line Tokens (2 marks)**

A user types the following at the command line. For each token, select the letter corresponding to the correct description.

```
orange apple < grape | cherry
```

| Token  | Answer |
| ------ | ------ |
| orange | A      |
| apple  | B      |
| grape  | D      |
| cherry | A      |

**Options:**

- A. Program that is executed
- B. Command line argument
- C. File to which output is redirected
- D. File from which input is redirected
- E. Directory that contains the files

**Answer:**

---

## **Question 3: Memory Management (9 marks)**

### Part (a) [8 marks]

Fill in the memory diagram to show the state of the program **before** the return statement on line 7 executes.

```c
1 char * code(int *off, int len, char *str) {
2 char *msg = malloc(len * sizeof(char) + 1);
3 for(int i = 0; i < len; i++) {
4     msg[i] = str[off[i]];
5 }
6 msg[length] = '\0';
7 return msg;
8 }
9
10 int main() {
11 int loc[3] = {1, 4, 0};
12 char *text = "dragon";
13 char *result = code(loc, 3, text);
14 printf("%s\n", result);
15 return 0;
16 }
```

**Memory Diagram:**


| Section   | Address | Value | Label  |
| --------- | ------- | ----- | ------ |
| Read-only | 0x104   | drag  |        |
|           | 0x108   | on\0  |        |
|           | 0x10C   |       |        |
| Heap      | 0x240   | rod\0 |        |
|           | 0x244   |       |        |
|           | 0x248   |       |        |
|           | 0x24C   |       |        |
| Stack     | 0x448   | 1     | loc    |
| main      | 0x44C   | 4     |        |
|           | 0x450   | 0     |        |
|           | 0x454   | 0x104 | text   |
|           | 0x458   |       |        |
|           | 0x45C   | 0x240 | result |
|           | 0x460   |       |        |
| Stack     | 0x464   | 0x448 | off    |
| code      | 0x468   |       |        |
|           | 0x46C   | 3     | int    |
|           | 0x470   | 0x104 | str    |
|           | 0x474   |       |        |
|           | 0x478   | 0x240 | msg    |
|           | 0x47C   |       |        |
|           | 0x480   | 3     | i      |



### Part (b) [1 mark]

Which line should be added after line 14 to prevent memory leaks?

- [ ]  free(loc);
- [ ]  free(text);
- [x]  free(result);
- [ ]  free(msg);

**Answer:**

---

## **Question 4: File Handling (10 marks)**

### Part (a) [6 marks]

Complete the function that reads the first `num` lines from `fptr` and stores them in an array of strings.

```c
#define MAXLINE 256

char **first_lines(int num, FILE *fptr) {

```

**Answer:**

```c
#define MAXLINE 256

char **first_lines(int num, FILE *fptr) {
	char **arr = malloc(num*sizeof(char *));
	for (int = 0; i < num; i++) {
	arr[i] = malloc(MAXLINE);
	char *ptr = fgets(arr[i], MAXLINE, fptr);
	if(ptr == NULL) {
	arr[i] = NULL;
			}
		}
	return arr
	}

```

### Part (b) [4 marks]

Complete the program that reads a filename and a number from standard input, then calls `first_lines()` and prints the result.

```c
int main() {
    char filename[MAXLINE];
    int num;


    char **lines = first_lines(num, fptr);

```

**Answer:**


```c
int main() {
    char filename[MAXLINE];
    int num;
    scanf("%s%d", filename, &num);
	File * fptr  = fopen(filename, "r");
    char **lines = first_lines(num, fptr);
        for (int = 0,  int < num , i++) {
        if (lines[i] == NULL) {
        printf("&s", lines[i]);
	        }
	    return 0;
        }

```
