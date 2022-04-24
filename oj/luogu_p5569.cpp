#include<iostream>
#define MAX 40001

using namespace std;

int n;
int w[MAX];
int qz[MAX];
long long dp[MAX][MAX];
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w[i];
        qz[i] = (i==0? 0: qz[i-1])+w[i];
    }

    for(int len = 1; len<=n; len++){ // 枚举长度
        // cout << "len:"<<len<<endl;
        for(int i=0; i+len-1<n; i++){ // 枚举范围
            int j=i+len-1;
            int tw = qz[j] - qz[i] + w[i]; // 总重量， 和k无关， 因此在某一次枚举范围时，算一次就好了
            
            for (int k = i; k < j; k++)
            { // 枚举分割点
                if (k==i){
                    dp[i][j] =  dp[i][k] + dp[k + 1][j] + tw;
                }else{
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+tw);
                }
            }
        }
    }

    cout << dp[0][n-1];
}