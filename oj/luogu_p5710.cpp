#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool xz1 = n % 2 == 0;
    bool xz2 = 4 < n && n <= 12;
    cout << (xz1 && xz2);
    cout << " ";
    cout << (xz1 || xz2);
    cout << " ";
    cout << (xz1 ^xz2);
    cout << " ";
    cout <<  !(xz1 || xz2);
}