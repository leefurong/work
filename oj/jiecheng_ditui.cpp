#include<iostream>
using namespace std;

int a[11];
int main(){
    int n;
    cin >> n;
    a[1]=1; // 设置起点
    for(int i=2; i<=n; i++){
        a[i] = i*a[i-1]; // 每一步如何从上一步推出来
    }
    cout << a[n];
}