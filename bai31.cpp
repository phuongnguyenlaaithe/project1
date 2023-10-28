#include <bits/stdc++.h> 
using namespace std;

int main() {
    set<string> keys;
    string line;
    string key;

    while (cin >> key) {
        if (key == "*") {
            break;
        }
        keys.insert(key);
    }

    while (true) {
        getline(cin, line);
        if (line == "***") {
            break;
        }

        stringstream ss(line);
        string cmd, k;
        ss >> cmd >> k;

        if (cmd == "find") {
            if (keys.find(k) != keys.end()) {
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        } else if (cmd == "insert") {
            if (keys.find(k) == keys.end()) {
                keys.insert(k);
                cout << "1" << endl;
            } else {
                cout << "0" << endl;
            }
        }
    }

    return 0;
}
