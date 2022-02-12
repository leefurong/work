#include<iostream>
using namespace std;
// http://www.chaojidocs.com/#/book/615afeb16b17f442622f5c75/doc/6163f44e6b17f422bcda308f

int f(int n){
    if (n==1) return 1;
    return f(n-1)*n;
}

int main(){
    int n;
    cin >> n;
    cout << f(n);
}