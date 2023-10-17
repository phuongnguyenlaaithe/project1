#include<bits/stdc++.h>
using namespace std;

int main() {
    string line;

    while (getline(cin, line)) {
        for (char &c : line) {
            c = toupper(c); 
        }

        cout << line << endl; 
    }

    return 0;
}
