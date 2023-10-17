#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sequence(n);

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    string query;
    cin >> query;

    while (query != "***") {
        if (query == "find-max") {
            cout << *max_element(sequence.begin(), sequence.end()) << endl;
        } else if (query == "find-min") {
            cout << *min_element(sequence.begin(), sequence.end()) << endl;
        } else if (query == "find-max-segment") {
            int i, j;
            cin >> i >> j;
            cout << *max_element(sequence.begin() + i - 1, sequence.begin() + j) << endl;
        } else if (query == "sum") {
            cout << accumulate(sequence.begin(), sequence.end(), 0) << endl;
        }

        cin >> query;
    }

    return 0;
}
