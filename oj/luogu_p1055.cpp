#include<bits/stdc++.h>
using namespace std;
string s;
int ans;
int main(){
    cin >> s;

    char sbm;
    int j=1;
    // 算出识别码
    for(int i=0; i<s.size()-1; i++){
        if (isdigit(s[i])){
            // 0-3
            ans += (s[i]-'0')*j++;
        }
    }
    ans %=11;


    if (ans==10){
        sbm = 'X';
    }else{
        sbm=ans+'0';
    }





   if (sbm==s[s.size()-1]){
       cout << "Right";
   } else {
       s[s.size() - 1] = sbm;
       cout << s;
   }
}