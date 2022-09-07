#include<bits/stdc++.h>
using namespace std;

long long a[30];
int n;
long long sum;

int main(){
    int i=0;
    while(cin >> a[i++]);
    n=i-1;
    for(int i=0; i<n; i++){
        sum += a[i] * (1<<(n-1));
    }
    cout << sum;
}