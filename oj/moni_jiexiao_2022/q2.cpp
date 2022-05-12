#include<iostream>
using namespace std;

int m, n;
int a[1001];
int main(){
    cin >> n >> m;
    for(int i=1; i<=m; i++){
        int x;
        cin >> x;
        a[x]=1;
    }
    int ans_lou=0, ans_diu=0;
    for(int i=1; i<=n; i+=2){
        if (a[i] && a[i+1]){
            continue;
        } else if(a[i] || a[i+1]){
            ans_lou++;
        }else{
            ans_diu++;
        }
    }
    cout << ans_diu << endl<<ans_lou;
}