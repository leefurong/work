#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a=0;
    for(char c: s){
        if (c=='('){
            a++;
        }else{
            a--;
            if (a<0){
                cout << "(";
                a++;
            }
        }
        cout << c;
    }
    while (a-->0){
        cout << ")";
    }
}