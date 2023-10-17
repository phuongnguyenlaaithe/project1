#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int oddCount = 0;
    int evenCount = 0;

    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;

        if (ai % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    cout << oddCount << " " << evenCount << endl;

    return 0;
}
