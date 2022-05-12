#include<iostream>
using namespace std;

int ans[18];
int temp[18];
long long diff=9e18;
// 重量
long long a[37];
int n; // max: 36
long long total;
long long calcDiff(){
    long long w1=0, w2=0;
    for(int i=1; i<=n/2; i++){
        w1 += a[temp[i]];
    }
    w2 = total-w1;
    return abs(w1-w2);
}
void saveTemp(){
    for(int i=1; i<=n/2; i++){
        ans[i] = temp[i];
    }
}
void dfs(int step){
    if (step>n/2){
        long long thisDiff = calcDiff();
        if (thisDiff<diff){
            diff = thisDiff;
            saveTemp();
        }
        return;
    }
    for(int i=temp[step-1]+1; i<=n/2+step; i++){
        temp[step] = i;
        dfs(step+1);
    }
}
void print(){
    cout << n / 2 << " " ;
    for (int i = 1; i <= n / 2; i++)
    {
        cout << ans[i] << " ";
    }
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        total += a[i];
    }

    dfs(1);
    print();
}
