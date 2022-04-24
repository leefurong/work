#include<iostream>
using namespace std;
int n, k;
string s;

// 当特殊字符为c时， s破译后的第k位是什么？
char solve(char c){
    int cbeg, cend;
    int i=0;
    while(s[i]!=c && i<n){
        i++;
        if (i == k + 1){ // k在特殊符号之前
            return s[k];
        }
    }
    cbeg = i;
    while(s[i]==c && i<n){
        i++;
    } 
    cend = i;
    
    int clen=cend-cbeg;
    printf("%d...%d: %d", cbeg, cend, clen);
    if (clen==0){
        return k<n?s[k]: '*'; // 木有特殊符号
    } else {
        string replacement = s.substr(cend, clen);
        int sz = replacement.size();
        // 如果k在replacement重复clen次之中...
        // 这种情况下， sz不可能为0. 否则k会在replacement重复之后。
        if (k<cbeg+clen*sz){ 
            int targ_pos = (k-cbeg)%sz;
            return replacement[targ_pos];
        }else
        { // 否则，k在replacement重复clen之后...
        // k前面的字符串， 破解后增加了多少？
            int diff = -clen-sz+sz*clen;
            // 查找破解后的k位，想象一下， 从破解后还原成老字符串， 就把diff减去
            int pos = k-diff;
            return pos<n?s[pos]: '*';
        }
    }


}

int main(){
    cin >> n >> k;
    k--; // 以0位基。
    cin >> s;
    for(char c='a'; c<='z'; c++){
        cout << solve(c);
    }
}