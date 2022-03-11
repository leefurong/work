#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
const int top = 50000;
int a[100001];
int d[100001];
int len;
int n=0;
set<int> pao;

void printd(){
    cout <<"pd:"<<endl;
    for(int i=0; i<n; i++){
        cout <<top-d[i]<<" ";
    }
    cout <<endl;
}

int main(){
    int x;
    while(cin >> x){
        // 嗯嗯， 不存高度，而是存高度到top的距离。
        // 这样一来， d数组就可以是上升的了。 于是，lower_bound也好用了。
        a[n++]=top-x;
    }

    d[len++] = a[0];
    // quiz 1: 最长不下降子序列长度
    for(int i=1; i<n; i++){
        if (a[i]<d[len-1]){
            // printd();
            *upper_bound(d, d+len, a[i]) = a[i];
            // printd();
        }else if (a[i]>=d[len-1]){
            d[len++] = a[i];
        }
    }
    cout << len<<endl;

    // quiz2
    for(int i=0; i<n; i++){
        int h = top-a[i];
        set<int>::iterator p = pao.lower_bound(h);
        if (p!=pao.end()){
            pao.erase(p);
        }
        pao.insert(h);
    }
    cout << pao.size();

}