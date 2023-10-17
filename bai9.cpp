#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // Check if the string has the correct format (hh:mm:ss)
    if (s.length() != 8 || s[2] != ':' || s[5] != ':' ||
        !isdigit(s[0]) || !isdigit(s[1]) || !isdigit(s[3]) ||
        !isdigit(s[4]) || !isdigit(s[6]) || !isdigit(s[7])) {
        cout << "INCORRECT" << endl;
        return 1;
    }

    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));

    if (hh < 0 || hh > 23 || mm < 0 || mm > 59 || ss < 0 || ss > 59) {
        cout << "INCORRECT" << endl;
        return 1;
    }

    int result = hh * 3600 + mm * 60 + ss;
    cout << result << endl;

    return 0;
}
