#include <bits/stdc++.h>
using namespace std;

int f(int a, int x){
    int f1=1;
    int f2=a;
    
    int n=2;
    int now=f2;
    while(now<x){
        f2=now+f1;
        f1=now;
        now=f2;
        n++;
    }
    if (now==x){
        return n;
    }else{
        return -1;
    }

}
int main(){
    int T;
    cin >> T;
    while(T--){
        int x;
        cin >> x;
        for(int a=x; a>=1; a--){
            int n = f(a, x);
            if (n>0){
                cout << n << " "<< a<<endl;
            }
        }
    }
}