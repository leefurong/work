#include<iostream>
using namespace std;
int n;
int cache[1001];

int f(int x){
    if (cache[x])return cache[x];

    int ans=1; // x自身有一种情况。 即第一种处理方法：“不作任何处理”
    // x左边有邻居？ 有这么多种情况：
    for(int i=1; i<=(x/2); i++){
        ans += f(i);
    }
    return cache[x] = ans;
}

int main(){
    cin >> n;
    cout << f(n);
}