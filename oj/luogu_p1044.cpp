#include<iostream>
using namespace std;
int f[19]={1};
int n;

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        // 求当问题规模为i时， 即， 输入序列为1~i时， 有多少种输出方法？
        // 由于1总是第一个进入栈底。 问题转化为： 1这个元素啥时候出来？
        // 1出来的时候， 前面有多少元素，后面还有多少元素？
        // 因此， 用1划分一下其他的元素， 出栈序列就可以表达为：[2, k) 1 [k, i+1)
        // 其中， 1的左边共有k-2个元素。 这些元素的出栈方法一共有f[k-2]种。
        // 1的右边共有i+1-k个元素。 这些元素的出栈方法一共有f[i+1-k]种。
        // 由乘法原理， 可以得到， 给定一个k（亦即1的出栈时机明确， 或划分方法明确）， 一共的出栈方法有
        // f[k-2]*f[i+1-k]种。
        // 把所有的k情况枚举一下， 都加起来， 就知道f[i]了。
        for(int k=2; k<=i+1; k++){
            // 共有f[k-1]*f[i-k]种方法
            f[i] += f[k-2]*f[i+1-k];
        }
    }
    cout << f[n];
}