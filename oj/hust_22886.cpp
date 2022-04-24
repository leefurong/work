#include<iostream>
using namespace std;

int n;
int w[101];
int cache[101][101];
int qz[101];

int total(int left, int right){
    return qz[right]-qz[left]+w[left];
}
int solve(int left, int right){
    if (cache[left][right]) return cache[left][right];
    if (left==right){
        return 0;
    }
    int mn = 999999999;
    for(int mid=left; mid<right; mid++){
        mn = min(mn, solve(left, mid)+solve(mid+1, right)+total(left, right));
    }
    return cache[left][right]=mn;
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> w[i];
        qz[i]=qz[i-1]+w[i];
    }

    cout << solve(1, n);
}