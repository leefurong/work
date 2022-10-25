#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, L, R;
    cin >> n >> L >> R;
    if (R/n > L/n) cout << n-1;
    else cout << R%n;
}