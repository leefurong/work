#include<iostream>
using namespace std;
int a, b;

int f(int a, int b){
    if (b==a||b==a+1) return 1;
    return f(a, b-1)+f(a, b-2);
}
int main(){
    cin >> a >> b;
    cout << f(a, b);
}