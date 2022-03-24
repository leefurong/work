#include<iostream>
using namespace std;
int t, m;
long long dp[10000001]; // 采药总时间为j时， dp[j]表示能采到的最大价值。

int main(){
    cin >> t >> m;
    while(m--){
        int ti, vi;
        cin >> ti >> vi;
        for(int j=1; j<=t; j++){
            long long use = j>=ti? vi + dp[j-ti]: dp[j];
            long long ignore = dp[j];
            dp[j] = max(use, ignore);
        }
    }
    cout << dp[t]<<endl;
}