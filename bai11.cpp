#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> prefixSum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    int count = 0;

    for (int i = 0; i <= n - k; i++) {
        int sum = prefixSum[i + k] - prefixSum[i];
        if (sum % 2 == 0) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
