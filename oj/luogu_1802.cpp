#include<iostream>
using namespace std;

int n, x;
long long dp[1001];

int main(){
    cin >>n >>x;
    while(n--){
        int lose,win,use;
        cin >> lose >>win >> use;
        for(int i=x; i>=0; i--){
            if (i>=use){
                dp[i] = max(dp[i]+lose, dp[i-use]+win);
            }else{ // 即便包装不下这个药， 不吃这个药，也要加分哦。
                dp[i] = dp[i]+lose;
            }

        }
    }
    cout <<dp[x]*5;
}