#include<iostream>
using namespace std;

int n;
int q[1001][1001];
int row[1001], col[1001]; // 整行/列被控制， 则为1
bool inrange(int i){
    return i>=1 && i<=n;
}
void xie(int i, int j, int di, int dj){
    while(inrange(i+di) && inrange(j+dj)){
        i+=di;
        j+=dj;
        if (q[i][j]==0) q[i][j]=3;
        if (q[i][j]==1 || q[i][j]==2) break;
    }
}
void xie(int i, int j){
    xie(i, j, 1, 1);
    xie(i, j, 1, -1);
    xie(i, j, -1, 1);
    xie(i, j, -1, -1);
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> q[i][j];
            if (q[i][j]!=0)
            {
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if (q[i][j]==2){
                // 把后斜着能吃的， 为0的地方都设为3
                xie(i, j);
            }
        }
    }

    // 数一数
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        if (row[i]) continue;
        for (int j = 1; j <= n; j++)
        {
            if (col[j]) continue;
            if (q[i][j]==0) ans++;
        }
    }
    cout << ans;
}