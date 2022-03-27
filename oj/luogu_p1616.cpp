#include<iostream>
using namespace std;
int t, m;
long long dp[10000001]; // 采药总时间为j时， dp[j]表示能采到的最大价值。

int main(){
    cin >> t >> m;
    while(m--){
        int ti, vi;
        cin >> ti >> vi;
        for(int j=ti; j<=t; j++){
                dp[j] = max(dp[j], vi+dp[j-ti]);

        }
    }
    cout << dp[t]<<endl;
}