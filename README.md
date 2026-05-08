# Compiler Design Lab - Spring 25-26 Semester

## Assignment: File Handling & Lexical Analysis

This laboratory exercise focuses on two core concepts in C++ programming:

### Problem 1: File Handling
Write a program to read the content of an external text file (`content.txt`) and print out the text content to the console.

### Problem 2: Lexical Analysis
From the `content.txt` provided in the file, identify the tokens (keywords, identifiers, operators, etc.) and print them out line by line with their type (e.g., `int = keyword`, `x = identifier`).

---

## Task Structure

```
.
├── main.cpp            # Main C++ source code containing the solution
├── content.txt         # Input file containing the text content
└── README.md           # This documentation file
```

---

## Expected Output

### File Content Section
```
--- File Content ---
int main(){
int x;
x=10;
cout<<"Hello World";
return 0;
}
--------------------
```

### Token Analysis Section
```
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

---

## Learning Objectives

1. **File Handling**: Understand how to read and process external files in C++
2. **Lexical Analysis**: Learn to tokenize source code and classify tokens by type
3. **Pattern Recognition**: Develop skills to identify different token categories
4. **String Processing**: Work with string manipulation and character analysis

---

## Token Types Reference

| Token Type | Examples |
|-----------|----------|
| Keyword | `int`, `return`, `if`, `while`, `for`, `main` |
| Identifier | Variable names, function names (e.g., `x`, `main`, `cout`) |
| Operator | `=`, `+`, `-`, `*`, `/`, `<<`, `>>` |
| Punctuator | `{`, `}`, `(`, `)`, `;`, `,` |
| Number | Integer or floating-point literals (e.g., `10`, `3.14`) |
| String Literal | Text enclosed in quotes (e.g., `"Hello World"`) |

---

## Implementation Requirements

- Read the contents of `content.txt` and display it to console
- Parse each line and identify individual tokens
- Classify each token according to its type
- Output should match the expected format shown above
- Handle proper spacing and formatting in the output

---

## Notes

- Ensure the `content.txt` file is in the same directory as the executable
- Pay attention to operator precedence and multi-character operators (e.g., `<<`)
- String literals should be recognized as complete tokens including the quotes
- All keywords must be recognized (common C++ keywords)

