#include<iostream>
using namespace std;
int ans[1001][1001];
int a, b;

int main(){
    cin >> a >> b;
    ans[a][a] = 1;
    ans[a][a+1] = 1;
    for(int i=a+2; i<=b; i++){
        ans[a][i] = ans[a][i-1]+ans[a][i-2];
    }
    cout << ans[a][b];
}