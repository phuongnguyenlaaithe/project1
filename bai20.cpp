#include <bits/stdc++.h> 
using namespace std;

void solution(int n, int x[]){
    for(int i = 0; i< n; i++)
        cout << x[i] << " ";
    cout << endl;
}

void Try(int n, int M, int x[], int k) {
    if (k == n) {
        if (M == 0) solution(n,x);
    }

    for (int i = 1; i <= M; i++) {
        x[k] = i;
        Try(n, M - i, x, k+1);
    }
}

int main() {
    int n, M;
    cin >> n >> M;

    int x[n];
    Try(n, M, x, 0);

    return 0;
}
