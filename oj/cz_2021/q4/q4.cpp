#include<iostream>
using namespace std;
int n, k;
string s;
int i;
int vi;

char solve(char c){
    int vi=0;
    for(int i=0; i<n; i++){
        if (s[i]!=c){
            if (vi==k){
                return s[i];
            }
            vi++;
        } else {
            int x=0;
            while(i<n && s[i]==c) ++x, ++i;
            string ss=s.substr(i, x);
            if(ss.size()*x+vi>k) return ss[(k-vi)%ss.size()];
            vi+=ss.size()*x;
            i+=x-1;
        }
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