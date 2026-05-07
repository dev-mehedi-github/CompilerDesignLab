#include <iostream>
using namespace std;

bool matches(string s) {
    int n = s.length();
    if (n == 0) return false;

    // exactly "ab"
    if (n == 2 && s[0] == 'a' && s[1] == 'b') {
        return true;
    }

    // (zero or more 'a' followed by one or more 'b')
    int i = 0;
    
    // Count leading 'a's
    while (i < n && s[i] == 'a') {
        i++;
    }
    
    // Must have at least one 'b' after that
    if (i == n || s[i] != 'b') {
        return false;
    }
    
    // All remaining characters must be 'b'
    while (i < n) {
        if (s[i] != 'b') {
            return false;
        }
        i++;
    }
    
    return true;
}

int main() {
    string tests[5] = {"ab", "b", "aaabbb", "aaa", "abab"};
    
    for(int i = 0; i < 5; i++) {
        string str = tests[i];
        cout << "String: \"" << str << "\"  -->  ";
        
        if(matches(str)) {
            cout << "ACCEPTED\n";
        } else {
            cout << "REJECTED\n";
        }
    }
    
    return 0;
}