#include<iostream>
using namespace std;

int n;
int dp[100001];
int a[100001];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        int mx=0;
        for(int j=1; j<i; j++){
            if (a[j]<a[i]){
                mx = max(mx, dp[j]);
            }
        }
        dp[i] = mx+1;
        ans = max(ans, dp[i]);
    }

    cout << ans;
}