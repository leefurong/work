#include<iostream>
#define go(a, b) char ans=move(a, b); if(ans) return ans;
using namespace std;
int n, k;
string s;
int i;
int vi;
// move i by di, with vi by repeatVi*di
// During this movement, if k==vi, return s[i] and stop movement.
// Otherwise, returns '\0'
// If reach end of string, returns '*'
char move(int di, int repeatVi){
    if (i>=n){
        return '*';
    }
    if (repeatVi>0 && vi==k){
        return s[i];
    }
    int vi2 = vi + di*repeatVi;
    int i2 = i+di;
    if (k<vi2){
        int distance = k-vi;
        return s[i+distance%di];
    }

    vi=vi2;
    i=i2;
    return 0;
}
char solve(char c){
    vi=0; // 虚拟位置
    i=0; // 待检查的位置
    while(i<n){
        while(i<n&&s[i]!=c){
            go(1,1);
        }
        int x=0;
        while(i<n && s[i]==c){
            x++;
            go(1,0);
        }
      
        int len=min(x, n-i);
        go(len, x);
    }
    return '*';
}

int main(){
    cin >> n >> k;
    k--; // 以0位基。
    cin >> s;
    for(char c='a'; c<='z'; c++){
        cout << solve(c);
    }
}