#include<bits/stdc++.h>
using namespace std;

double f(int n){
    return (pow((1 + sqrt(5)) / 2, n) - pow((1 - sqrt(5)) / 2, n)) / sqrt(5);
}
int main(){
    int n;
    cin >> n;
    cout << fixed << setprecision(2) << f(n);
}