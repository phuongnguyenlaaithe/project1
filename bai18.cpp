#include <bits/stdc++.h> 
using namespace std;

void solution(int n, int x[]){
    for(int i = 1; i<= n; i++)
        cout << x[i];
    cout << endl;
}

void Try(int i, int n, int x[], int m[]){
    for(int v =1; v<=n; v++){
        if(!m[v]){
            x[i] = v;
            m[v] = true;
            if(i==n) solution(n,x);
            else Try(i+1,n,x,m);
            m[v] = false;
        }
    }
}

void main(){
    int n;
    cin >> n;
    int x[n+1], m[n+1];
    for(int v=1; v<=n; v++)
        m[v] = false;
    Try(1,n,x,m);
}