#include<iostream>
using namespace std;
int cache[19];
int n;
int f(int x){
    if (cache[x])return cache[x]; // 记忆化搜索
    if (x==0) return cache[0] = 1;
    int ans=0;
    // 把x分为三部分：
    //              1    [2, k)     [k, x+1)
    // 1 进去后， 等待[2, k)都出来， 1再出来， 然后是剩下的[k, x+1)
    // [2, k)共有f(k-2)种方法； [k, x+1)共有f(x+1-k)种方法.
    // 根据乘法原理： 总共有f(k-2)*f(x+1-k)种方法.
    // 再根据加法原理： 把不同的k情况都累加起来， 就ok了。
    for(int k=2; k<=x+1; k++){ // k最大是x+1, 即右边区间为空的情况。
        ans+=f(k-2)*f(x+1-k);
    }
    return cache[x] = ans;
}

int main(){
    cin >> n;
    cout << f(n);
}