#include <bits/stdc++.h> 
using namespace std;

const int MOD = 1e9 + 7;

int C(int k, int n) {
    int a[n + 1][k + 1];

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= min(i, k); ++j) {
            if (j == 0 || j == i) {
                a[i][j] = 1;
            } else {
                a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % MOD;
            }
        }
    }

    return a[n][k];
}

int main() {
    int k, n;
    cin >> k >> n;

    int result = C(k, n);

    cout << result << endl;

    return 0;
}
