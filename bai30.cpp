#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, M;
    cin >> n >> M;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    unordered_set<int> seen;

    int numPairs = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int y = M - x;

        // Kiểm tra x và y có trong set chưa
        if (seen.find(y) != seen.end()) {
            numPairs++;
        }

        // Thêm x vào set để kiểm tra với các phần tử tiếp theo
        seen.insert(x);
    }

    cout << numPairs << endl;

    return 0;
}
