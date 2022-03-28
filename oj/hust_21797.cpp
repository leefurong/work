#include<iostream>
using namespace std;

long long  dp[6001];
int n, m;

int main(){
    cin >> m >> n;
    while(n--){
        int w,c,p;
        cin >>w>>c>>p;
        if(p==0||p*w>=m){ // 相当于无限量供应，转换为完全背包问题
            for(int i=w; i<=m; i++){
                dp[i]=max(dp[i], dp[i-w]+c);
            }
        }else{
            // 二进制拆分。把p个商品，拆分成1,2,4,...remain个包。变成01背包问题
            for(int k=1; p>0; k<<=1){
                int x=min(k, p);
                for(int i=m; i>=x*w; i--){
                    dp[i] = max(dp[i], dp[i-x*w]+x*c);
                }
                p-=x;
            }
        }
    }
    cout << dp[m];
}