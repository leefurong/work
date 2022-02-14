#include <iostream>
using namespace std;

int n;
int a[51][51];
int main(){
    cin >> n;
    int r=1, c=1;
    int i=1;
    a[r][c] = i++;
    while(true){
        int mi=i;
        // 顺时针
        while(c+1<=n && !a[r][c+1]) a[r][++c] = i++;
        while(r+1<=n && !a[r+1][c]) a[++r][c] = i++;
        while(c-1>=1 && !a[r][c-1]) a[r][--c] = i++;
        while(r-1>=1 && !a[r-1][c]) a[--r][c] = i++;
        // 额外向右一格
        if(c+1<=n && !a[r][c+1]) a[r][++c] = i++;
        // 逆时针
        while(r+1<=n && !a[r+1][c]) a[++r][c] = i++;
        while(c+1<=n && !a[r][c+1]) a[r][++c] = i++;
        while(r-1>=1 && !a[r-1][c]) a[--r][c] = i++;
        while(c-1>=1 && !a[r][c-1]) a[r][--c] = i++;
        // 额外向下一格
        if(r+1<=n && !a[r+1][c]) a[++r][c] = i++;
        // 费那么大周折，如果一个字都没有填， 那就说明到头了。
        if (mi==i) break;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout << a[i][j] << (j==n?"":" ");
        }
        cout << endl;
    }
}