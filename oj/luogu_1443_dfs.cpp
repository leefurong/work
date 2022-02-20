#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

int n, m, x, y;
int ans[401][401];
int d[8][2]={
    {-1, -2},
    {-2, -1},
    {-1, 2},
    {-2, 1},
    {1, -2},
    {2, -1},
    {1,2},
    {2,1}
};

void dfs(int x, int y, int steps){
    // it's out of range.
    if (x<1 || y<1 || x>n||y>m) return;

    // already got a better idea.
    if (ans[x][y]!=-1 && ans[x][y]<steps) return;

    ans[x][y] = steps;
    for(int i=0; i<8; i++){
        dfs(x+d[i][0], y+d[i][1], steps+1);
    }
}
void print(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << left<<setw(5)<<ans[i][j];
        }
        cout << endl;
    }
}
int main(){
    cin >> n>>m >> x>>y;
    memset(ans, -1, sizeof(ans));
    dfs(x, y, 0);
    print();
}