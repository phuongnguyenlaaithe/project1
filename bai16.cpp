#include <bits/stdc++.h> 
using namespace std;

void solution(int n, int x[]){
    for(int i = 1; i<= n; i++)
        cout << x[i];
    cout << endl;
}

int check(int v, int k){
    return 1;
}

void Try(int k, int n, int x[]){
    for(int v=0; v<=1; v++){
        if(check(v,k)){
            x[k] = v;
            if(k==n) solution(n,x);
            else Try(k+1,n,x);
        }
    }
}

int main(){
    int n;
    cin >> n;
    int x[n+1];
    Try(1,n,x);
}