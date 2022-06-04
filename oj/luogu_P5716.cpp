#include<bits/stdc++.h>
using namespace std;
int y, m;
int main(){
    cin >> y >> m;
    if (m==2){
        if (y%4==0 && y%100!=0 || y%400==0){
            cout << 29;
        }else{
            cout << 28;
        }
    }else if (m==4||m==6||m==9||m==11){
        cout << 30;
    } else {
        cout << 31;
    }
}