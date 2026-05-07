# Lexical Analysis - Compiler Design Lab

## Overview
This directory contains implementations and assignments for **Lexical Analysis** phase of compiler design.

The lexical analyzer (also called scanner or tokenizer) is the first phase of a compiler that breaks down source code into meaningful tokens.

## Contents

### 1. `lexical_analyzer.cpp`
A complete implementation of a lexical analyzer that:
- **Tokenizes** source code into meaningful tokens
- **Recognizes** keywords, identifiers, numbers, and operators
- **Handles** operators like `+`, `-`, `*`, `/`, `=`, `==`
- **Identifies** punctuation like parentheses, braces, semicolons

#### Features:
- Keyword recognition (int, float, if, else, while, for, return, void)
- Identifier and variable name extraction
- Number parsing (integers)
- Operator and punctuation tokenization
- Whitespace handling

#### How to Run:
```bash
g++ -o lexical_analyzer lexical_analyzer.cpp
./lexical_analyzer
```

#### Sample Input:
```
int main() { int x = 10; float y = 20.5; if (x == 5) { return x; } }
```

#### Sample Output:
```
Type: int | Value: int
Type: IDENTIFIER | Value: main
Type: LPAREN | Value: (
Type: RPAREN | Value: )
Type: LBRACE | Value: {
... (and so on)
```

## Learning Objectives
- Understand the role of lexical analysis in compilation
- Learn token classification and recognition
- Implement finite automata for token identification
- Handle various character sets and special symbols

## Topics Covered
- Token definition and classification
- Lexeme vs Token
- Whitespace and comment handling
- Keyword vs Identifier distinction
- Operator precedence
- Error handling in lexical analysis

## Assignments
1. **Basic Tokenizer**: Implement a simple lexical analyzer
2. **Extended Operators**: Add support for compound operators (==, !=, <=, >=)
3. **Comments**: Handle single-line and multi-line comments
4. **Strings**: Add string literal recognition
5. **Error Reporting**: Implement error messages for invalid tokens

## References
- Lexical Analysis in Compiler Design
- Finite Automata and Regular Expressions
- Dragon Book: Compilers - Principles, Techniques, and Tools
