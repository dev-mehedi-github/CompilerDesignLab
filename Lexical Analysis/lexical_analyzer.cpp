#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

// Token structure
struct Token {
    string type;
    string value;
};

// Lexical Analyzer Class
class LexicalAnalyzer {
private:
    string source;
    int position;
    vector<Token> tokens;

public:
    LexicalAnalyzer(string code) : source(code), position(0) {}

    // Check if character is a valid identifier start
    bool isIdentifierStart(char c) {
        return isalpha(c) || c == '_';
    }

    // Check if character is valid in identifier
    bool isIdentifierChar(char c) {
        return isalnum(c) || c == '_';
    }

    // Check if character is a digit
    bool isDigit(char c) {
        return isdigit(c);
    }

    // Skip whitespace
    void skipWhitespace() {
        while (position < source.length() && isspace(source[position])) {
            position++;
        }
    }

    // Read identifier or keyword
    string readIdentifier() {
        string identifier = "";
        while (position < source.length() && isIdentifierChar(source[position])) {
            identifier += source[position];
            position++;
        }
        return identifier;
    }

    // Read number
    string readNumber() {
        string number = "";
        while (position < source.length() && isDigit(source[position])) {
            number += source[position];
            position++;
        }
        return number;
    }

    // Check if identifier is a keyword
    bool isKeyword(string word) {
        vector<string> keywords = {"int", "float", "if", "else", "while", "for", "return", "void"};
        for (const string& kw : keywords) {
            if (word == kw) return true;
        }
        return false;
    }

    // Main tokenization function
    vector<Token> tokenize() {
        while (position < source.length()) {
            skipWhitespace();

            if (position >= source.length()) break;

            char current = source[position];

            // Identifiers and Keywords
            if (isIdentifierStart(current)) {
                string identifier = readIdentifier();
                if (isKeyword(identifier)) {
                    tokens.push_back({identifier, identifier});
                } else {
                    tokens.push_back({"IDENTIFIER", identifier});
                }
            }
            // Numbers
            else if (isDigit(current)) {
                string number = readNumber();
                tokens.push_back({"NUMBER", number});
            }
            // Operators and Punctuation
            else if (current == '+') {
                tokens.push_back({"PLUS", "+"});
                position++;
            }
            else if (current == '-') {
                tokens.push_back({"MINUS", "-"});
                position++;
            }
            else if (current == '*') {
                tokens.push_back({"MULTIPLY", "*"});
                position++;
            }
            else if (current == '/') {
                tokens.push_back({"DIVIDE", "/"});
                position++;
            }
            else if (current == '=') {
                position++;
                if (position < source.length() && source[position] == '=') {
                    tokens.push_back({"EQUAL", "=="});
                    position++;
                } else {
                    tokens.push_back({"ASSIGN", "="});
                }
            }
            else if (current == '(') {
                tokens.push_back({"LPAREN", "("});
                position++;
            }
            else if (current == ')') {
                tokens.push_back({"RPAREN", ")"});
                position++;
            }
            else if (current == '{') {
                tokens.push_back({"LBRACE", "{"});
                position++;
            }
            else if (current == '}') {
                tokens.push_back({"RBRACE", "}"});
                position++;
            }
            else if (current == ';') {
                tokens.push_back({"SEMICOLON", ";"});
                position++;
            }
            else if (current == ',') {
                tokens.push_back({"COMMA", ","});
                position++;
            }
            else {
                // Unknown character
                position++;
            }
        }
        return tokens;
    }

    // Print tokens
    void printTokens() {
        cout << "\n=== TOKENS ===\n";
        for (const Token& token : tokens) {
            cout << "Type: " << token.type << " | Value: " << token.value << "\n";
        }
    }
};

// Main function
int main() {
    // Sample source code
    string code = "int main() { int x = 10; float y = 20.5; if (x == 5) { return x; } }";

    cout << "Source Code: " << code << "\n";

    // Create lexical analyzer and tokenize
    LexicalAnalyzer analyzer(code);
    analyzer.tokenize();
    analyzer.printTokens();

    return 0;
}
