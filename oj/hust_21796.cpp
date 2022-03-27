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
            //暴力拆分， 相当于s个商品，分别为 价格v， 价值w， 变为01背包问题
            while(s--){//填写s行
                for(int i=m; i>=v; i--){
                    dp[i]=max(dp[i], dp[i-v]+w);
                }
            }
        }
    }
    cout << dp[m];
}