#include<iostream>
using namespace std;
int n, k;
string s;

char solve(char c){
    int vi=-1; // 虚拟位置
    int i=0; // 待检查的位置
    while(i<n){
        while(i<n&&s[i]!=c){
            vi++;
            if(vi==k){
                return s[i];
            }
            i++;
        }
        int x=0;
        while(i<n && s[i]==c){
            x++;
            i++;
        }
        int len=min(x, n-i);
        // 过了复制区域后， 位置是什么？
        int nexti=i+len;
        int nextvi=vi+len*x;
        if (len>0) vi++;
        if (nextvi>=k){
            return s[i + (k - vi) % len];
        }
        i=nexti;
        vi=nextvi;
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