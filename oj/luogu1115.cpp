#include<iostream>
using namespace std;
int dp;
int n;

int main(){
    cin >> n;
    int maxx;
    for(int i=1; i<=n; i++){
        int a;
        cin >> a;
        dp = max(dp, 0)+a;
        if (i==1) maxx=dp;
        else maxx = max(dp, maxx);
    }
    cout << maxx;
}