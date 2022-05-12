#include<iostream>
#include<math.h>
using namespace std;
int a[1001];
int m, n;
int my_pow(int a, int b){
    int ans=1;
    while(b--)
        ans = (ans * a) % 10000007;
    return ans;
}
int main(){
    cin >> n >> m;
    a[1] = m;
    a[2] = m * (m - 1) % 10000007;
    for (int i = 3; i <= n; i++)
    {
        a[i] = (m * my_pow(m - 1, i - 1) - a[i - 1]) % 10000007;
    }
    cout << a[n];
}