#include<iostream>
using namespace std;
int dp[40001];
int n, W;
int main(){
    cin >>n >>W;
    while(n--){
        int vi, wi, mi;
        cin >>vi>>wi>>mi;

        for(int x=1; mi>0; x<<=1){
            x=min(x, mi);
            for(int i=W; i>=wi*x; i--){
                dp[i]=max(dp[i], dp[i-wi*x]+vi*x);
            }
            mi-=x;
        }
    }
    cout <<dp[W];
}