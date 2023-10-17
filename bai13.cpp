#include <bits/stdc++.h> 
using namespace std;

int main() {
    string text;
    string line;
    
    while (getline(cin, line)) {
        text += line; 
        text += ' '; 
    }

    int wordCount = 0;
    bool inWord = false;

    for (char c : text) {
        if (c != ' ' && c != '\t' && c != '\n') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }

    cout << wordCount << endl;

    return 0;
}