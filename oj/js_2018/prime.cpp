#include<bits/stdc++.h>
using namespace std;
// 求n以内(含)的所有质数。
// n<10^5
int n;
bool isPrime[100001];
vector<int> primes;
int main(){
    for(int i=2; i<=100000; i++)isPrime[i]=true;
    cin >> n;
    for(long long i=2; i<=n; i++){
        if (isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i; j<=n; j+=i){
                isPrime[j]=false;
            }
        }
    }
    for(int x: primes) cout << x << " ";
}