#include<iostream>
using namespace std;

bool lucky(int x, int base){
    while(x!=0){
        int remain = x%base;
        if (remain==0) return false;
        x/=base;
    }
    return true;
}
bool lucky(int x){
    return lucky(x, 5) && lucky(x, 7) && lucky(x, 9);
}
int main(){
    int a, b, ans=0;
    cin >> a >> b;
    for(int i=a; i<=b; i++) ans+=lucky(i);
    cout << ans;
}