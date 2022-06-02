#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int stars;
    if (n%2){
        stars = n*(1+n)/2;
    }else{
        stars = n*((1+n)/2)+n/2;
    }
    int ans=(stars-n)*2+(n-1);
    cout << ans;
}