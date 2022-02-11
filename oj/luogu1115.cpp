#include<iostream>
using namespace std;
int dp[200001];
int n;

int main(){
    cin >> n;
    int maxx;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        dp[i] = max(dp[i-1], 0)+a;
        if (i==1) maxx=dp[i];
        maxx = max(dp[i], maxx);
    }
    cout << maxx;
}