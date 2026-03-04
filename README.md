C++ Lab Work: File Handling and Lexical Analysis

## Question: 
This laboratory exercise focuses on two core concepts in C++ programming:
1. Problem 1 (File Handling):
    Write a program to read the content of an external text file (`content.txt`) and print out the text content to the console.
2. Problem 2 (Lexical Analysis): 
   From the content.txt provided in the file, identify the tokens (keywords, identifiers, operators, etc.) and print them out line by line with their type (e.g., `int = keyword`, `x = identifier`).

## Task Structure
```text
├── main.cpp            # Main C++ source code containing the solution
├── content.txt         # Input file containing the text content
└── README.md           # This documentation file
```

---
## Expected Output:
```
--- File Content ---
int main(){
int x;
x=10;
cout<<"Hello World";
return 0;
}

--- Token Analysis ---
line 1: 
int = keyword, main = identifier, () = punctuator, { = punctuator
line 2:
int = keyword, x = identifier, ; = punctuator
line 3:
x = identifier, = = operator, 10 = number, ; = punctuator
line 4: 
cout = identifier, << = operator, "Hello World" = string literal, ; = punctuator
line 5:
return = keyword, 0 = number, ; = punctuator
```
