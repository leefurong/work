#include<iostream>
using namespace std;
int dp[40001];
int n, W;
int main(){
    cin >>n >>W;
    while(n--){
        int vi, wi, mi;
        cin >>vi>>wi>>mi;
        while(mi--){
            for(int i=W; i>=wi; i--){
                dp[i]=max(dp[i], dp[i-wi]+vi);
            }
        }
    }
    cout <<dp[W];
}