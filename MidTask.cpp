#include<iostream>
#include<fstream>
using namespace std;

int isKeyword(string input)
{
    string keywords[] = {"int","float","double","char","if","else","while","for","return","void","main","cout","cin","string"};
    for (int i = 0; i < 14; i++)
        if (keywords[i] == input)
            return 1;
    return 0;
}

int isOperator(string input)
{
    string operators[] = {"+","-","*","/","%","=","==","!=","<",">",">=","<=","&&","||","<<",">>"};
    for (int i = 0; i < 16; i++)
        if (operators[i] == input)
            return 1;
    return 0;
}

int isPunctuators(string input)
{
    char punctuators[] = {';',',','(',')','{','}','[',']','#','"'};
    for (int i = 0; i < 10; i++)
        if (punctuators[i] == input[0])
            return 1;
    return 0;
}

int isNumber(string input)
{
    for (int i = 0; i < (int)input.length(); i++)
        if (input[i] < '0' || input[i] > '9')
            return 0;
    return 1;
}

int isIdentifier(string input)
{
    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z') || input[0] == '_')
        return 1;
    return 0;
}

void printToken(string input)
{
    if (isKeyword(input))     
    cout << input << " = keyword, ";
    else if (isOperator(input))    
    cout << input << " = operator, ";
    else if (isPunctuators(input)) 
    cout << input << " = Punctuator, ";
    else if (isNumber(input))      
    cout << input << " = number, ";
    else if (isIdentifier(input))  
    cout << input << " = identifier, ";
    else                           
    cout << input << " = unknown, ";
}

void LexicalAnalyzer()
{
    ifstream file("content.txt");
    char ch;
    string input = "";
    int lineNum = 1;
    bool firstToken = true;

    while(file.get(ch))
    {
        if (ch == ' ' || ch == '\t')
        {
            if (input != "")
            {
                if (firstToken) { cout << "line " << lineNum << ":" << endl; firstToken = false; }
                printToken(input);
                input = "";
            }
        }
        else if (ch == '\n')
        {
            if (input != "")
            {
                if (firstToken) { cout << "line " << lineNum << ":" << endl; firstToken = false; }
                printToken(input);
                input = "";
            }
            if (!firstToken) cout << endl;
            lineNum++;
            firstToken = true;
        }
        else if (isOperator(string(1,ch)) || isPunctuators(string(1,ch)))
        {
            if (input != "")
            {
                if (firstToken) { cout << "line " << lineNum << ":" << endl; firstToken = false; }
                printToken(input);
                input = "";
            }
            if (firstToken) { cout << "line " << lineNum << ":" << endl; firstToken = false; }
            printToken(string(1, ch));
        }
        else
        {
            input += ch;
        }
    }

    file.close();
}

void showContent()
{
    ifstream inFile("content.txt");
    string line;
    if (inFile.is_open()) {
        while (getline(inFile, line))
            cout << line << endl;
        inFile.close();
    } else {
        cout << "Unable to open file";
    }
}

int main() {
    cout << "File Content:" << endl;
    showContent();
    cout << endl << "Lexical Analysis:" << endl;
    LexicalAnalyzer();
    return 0;
}