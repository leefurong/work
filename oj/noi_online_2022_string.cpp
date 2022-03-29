// https://www.luogu.com.cn/problem/P8256
#include<iostream>
using namespace std;
int n;
int lens, lent;
string s, t;

int count(string s, char c){
    int ans=0;
    for(char sc: s) if (c==sc)ans++;
    return ans;
}
string convert(string s, int rule){
    string ans="";
    int j=0;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if (c=='-'){
            bool remove_tail = rule&(1<<j);
            j++;
            int new_len = ans.size()-1;
            ans = ans.substr(remove_tail?0:1, new_len);
        }else{
            ans+=c;
        }
    }
    return ans;
}
int solve(string s, string t){
    int rule = 0;
    int ans=0;
    int max_rule = (1<<count(s, '-'))-1;
    while(rule<=max_rule){
        if (convert(s, rule)==t) ans=(ans+1)% 10000000071;
        rule++;
    }
    return ans;
}


int main(){
    cin >> n;
    while(n--){
        cin >> lens>>lent;
        cin >> s >> t;
        cout <<solve(s, t)<<endl;
    }
}