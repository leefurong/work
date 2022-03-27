#include<iostream>
using namespace std;

long long  dp[6001];
int n, m;

int main(){
    cin >> n >> m;
    while(n--){
        int v,w,s;
        cin >>v>>w>>s;
        if(s*v>=m){ // 相当于无限量供应，转换为完全背包问题
            for(int i=v; i<=m; i++){
                dp[i]=max(dp[i], dp[i-v]+w);
            }
        }else{
            // 二进制拆分。把s个商品，拆分成1,2,4,...remain个包。变成01背包问题
            for(int k=1; s>0; k<<=1){
                int x=min(k, s);
                for(int i=m; i>=x*v; i--){
                    dp[i] = max(dp[i], dp[i-x*v]+x*w);
                }
                s-=x;
            }
        }
    }
    cout << dp[m];
}