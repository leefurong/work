#include<bits/stdc++.h>
using namespace std;

int n;
int a[7];
int f(int missing){
    int ans=0;
    for(int i=1; i<=6; i++){
        if (a[i]) ans+=i;
        else ans+=missing;
    }
    return ans;
}
int main(){
    cin >> n;
    while(n--){
        int x, y, z;
        cin >> x >> y >> z;
        a[x]=1;
        a[y]=1;
        a[z]=1;
    }
    cout << f(1) << " " << f(6);
}