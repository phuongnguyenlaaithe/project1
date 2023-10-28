#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        long long hash = 0;
        int k = s.length();

        for (int j = 0; j < k; j++) {
            hash = (hash * 256 + s[j]) % m;
        }

        cout << hash << endl;
    }

    return 0;
}
