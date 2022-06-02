#include<bits/stdc++.h>
using namespace std;
bool run(int y){
    return (y%4==0&&y%100!=0)||y%400==0;
}
int daysOfYear(int y){
    return run(y)?366:365;
}
int daysOfMonth(int y, int m){
    if (m==1||m==3||m==5||m==7||m==8||m==10||m==12) return 31;
    else if (m==2) return run(y)?29:28;
    else return 30;
}
int f(int y){
    int days=0;
    for(int i=1900; i<y; i++){
        days += daysOfYear(i);
    }
    for(int i=1; i<11; i++){
        days += daysOfMonth(y, i);
    }
    days += 10;
    return days%7+1>5;
}
int main(){
    int a, b, ans=0;
    cin >> a >> b;
    for(int i=a; i<=b; i++) ans+=f(i);
    cout << ans;
}