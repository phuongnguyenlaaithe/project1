#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    unordered_set<int> seen;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (seen.find(A[i]) != seen.end()) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
        seen.insert(A[i]);
    }

    return 0;
}
