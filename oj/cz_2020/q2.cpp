#include<iostream>
using namespace std;

int n;
int a[10001];
int l1,l2,l3;
int which;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    cin >> l3 >> l2>>l1;
    cin >> which;
    int l;
    if (which==1) l=l1;
    if (which==2) l=l2;
    if (which==3) l=l3;

    int ans=0;
    for(int i=1; i<=n; i++){
        if (a[i]>=l) ans++;
    }
    cout << ans;
}