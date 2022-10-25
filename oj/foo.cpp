#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> a;
    
    auto it = a.upper_bound(2);
    cout << (it==a.end());
}