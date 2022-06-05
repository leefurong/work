#include<bits/stdc++.h>
using namespace std;

int f(string s){
    int d=0;
    stack<int> nums;
    for(char c: s){
        if (isdigit(c)){
            d *= 10;
            d += c-'0';
        }else if (c=='.'){
            nums.push(d);
            d = 0;
        } else if (c=='@') {
            return nums.top();
        } else {
            int n1 = nums.top(); nums.pop();
            int n2 = nums.top(); nums.pop();
            int n3;
            if (c=='+'){
                n3 = n2+n1;
            } else if (c=='-'){
                n3 = n2-n1;
            }else if (c=='*'){
                n3=n2*n1;
            }else if (c=='/'){
                n3 =n2/n1;
            }
            nums.push(n3);
        }
    }
    return 0;
}
int main(){
    string s;
    cin >> s;
    cout << f(s);
}